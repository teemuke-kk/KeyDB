#ifndef __STORAGE_H__
#define __STORAGE_H__

#define OBJ_ENCODING_EMBSTR_SIZE_LIMIT 44   // Note: also defined in object.c - should always match

enum MALLOC_CLASS
{
    MALLOC_LOCAL,
    MALLOC_SHARED,
};

void storage_init(void);

struct redisObject *salloc_obj();
void sfree_obj(struct redisObject *obj);
struct redisObject *salloc_objembstr();
void sfree_objembstr(struct redisObject *obj);

void *salloc(size_t cb, enum MALLOC_CLASS class);
void *scalloc(size_t cb, size_t c, enum MALLOC_CLASS class);
void sfree(void*);
void *srealloc(void *pv, size_t cb);

#endif

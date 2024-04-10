#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    void *go[2];
} trie_item;

static trie_item trie_allocator[10000000] = {};
static int trie_allocated = 0;

trie_item* trie = NULL;

inline trie_item* alloc_item()
{
    trie_item *res = trie_allocator + (trie_allocated++);
    res->cnt = 0;
    res->go[0] = res->go[1] = NULL;
    return res;
}

inline int cnt(trie_item* t)
{
    return t ? t->cnt : 0;
}

void add_(trie_item* t, char* s, int inc)
{
    t->cnt += inc;
    if (!(*s)) return;
    int i = *s - '0';
    if (!t->go[i]) t->go[i] = alloc_item();
    add_(t->go[i], s+1, inc);
}

void max_(trie_item* t, char* c, char* res)
{
    if (!(cnt(t->go[0]) || cnt(t->go[1])))
    {
        *res = '\0';
        return;
    }
    int i = (*c == '0') ? 1 : 0;
    if (!cnt(t->go[i]))
    {
        i = !i;
        *res = '0';
    }
    else *res = '1';
    max_(t->go[i], c+1, res+1);
}

void out(trie_item* t)
{
    static char out_buffer[1000];
    static char* bufptr = out_buffer;
    if (!t) return;
    *bufptr = '\0';
    int i, outcnt = cnt(t) - cnt(t->go[0]) - cnt(t->go[1]);
    for (i = 0; i < outcnt; i++)
        puts(out_buffer);
    for (i = 0; i < 2; i++)
    {
        *(bufptr++) = '0' + i;
        out(t->go[i]);
        bufptr--;
    }
}

void binstr(int n, char* c)
{
    int i;
    for (i = 0; i < 30; i++)
        c[30 - i - 1] = (n & (1 << i)) ? '1' : '0';
    c[30] = '\0';
}

int strbin(char* c)
{
    int res = 0;
    for (; *c; c++)
        res = (res << 1) + (*c - '0');
    return res;
}

void add(int n, int inc)
{
    char c[32];
    binstr(n, c);
    add_(trie, c, inc);
}

int max(int n)
{
    char c[32], res[32];
    binstr(n, c);
    max_(trie, c, res);
    return strbin(res);
}

void init()
{
    trie = alloc_item();
    add(0, 1);
}

inline int getint()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while ('0' <= c && c <= '9')
    {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline void putint(int n)
{
    char c[32];
    itoa(n, c, 10);
    puts(c);
}

int main()
{
    init();
    int i, q = getint();
    for (i = 0; i < q; i++)
    {
        char c = '\0';
        while (c <= ' ') c = getchar();
        int n = getint();
        switch (c)
        {
            case '+':
                add(n, 1);
            break;
            case '-':
                add(n, -1);
            break;
            case '?':
                putint(max(n));
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline int getint()
{
    int res = 0;
    char c = fgetc(stdin);
    while (c < '0' || c > '9') c = fgetc(stdin);
    while ('0' <= c && c <= '9')
    {
        res = res * 10 + (c - '0');
        c = fgetc(stdin);
    }
    return res;
}

inline void putint(int n)
{
    char c[32];
    itoa(n, c, 10);
    fputs(c, stdout);
}

typedef struct
{
    int item;
    void *down, *right;
} list_item;
typedef list_item* pitem;

pitem tmp;

#define swap(a, b) { tmp = a; a = b; b = tmp; }

static list_item alloc_table[4000000];
int alloc_cnt = 0;
inline pitem alloc_item()
{
    pitem res = alloc_table + (alloc_cnt++);
    res->item = 0;
    res->down = res->right = NULL;
    return res;
}

inline pitem down(pitem p)
{
    return p ? p->down : NULL;
}

inline pitem right(pitem p)
{
    return p ? p->right : NULL;
}

pitem find_item(pitem lst, int x, int y)
{
    int i;
    for (i = 0; i < x; i++) lst = down(lst);
    for (i = 0; i < y; i++) lst = right(lst);
    return lst;
}

pitem in_line(pitem upper_line, int n, bool must_read, bool forbid_reading)
{
    if (n == 0) return NULL;
    pitem p = alloc_item();
    if (must_read && !forbid_reading) p->item = getint();
    if (upper_line) upper_line->down = p;
    p->right = in_line(right(upper_line), n-1, true, forbid_reading);
    return p;
}

pitem in_table(int n, int m)
{
    int i;
    pitem prev, lst;
    prev = lst = in_line(NULL, m+1, false, true);
    for (i = 0; i < n; i++)
    {
        pitem p = in_line(prev, m+1, false, false);
        prev = p;
    }
    return lst;
}

void out_line(pitem it)
{
    if (!it) return;
    putint(it->item); putchar(' ');
    out_line(it->right);
}

void out_table(pitem lst)
{
    lst = down(lst);
    if (!lst) return;
    out_line(right(lst));
    putchar('\n');
    out_table(lst);
}

void swap_it(pitem a, pitem b, int x, int y)
{
    int i;
    pitem da = a, db = b;
    pitem ra = a, rb = b;
    // top of the rect
    for (i = 0; i < y; i++)
    {
        da = right(da), db = right(db);
        swap(da->down, db->down);
    }
    // right of the rect
    for (i = 0; i < x; i++)
    {
        da = down(da), db = down(db);
        swap(da->right, db->right);
    }
    // left of the rect
    for (i = 0; i < x; i++)
    {
        ra = down(ra), rb = down(rb);
        swap(ra->right, rb->right);
    }
    // bottom of the rect
    for (i = 0; i < y; i++)
    {
        ra = right(ra), rb = right(rb);
        swap(ra->down, rb->down);
    }
}

int main()
{
    int n = getint(), m = getint(), q = getint(), i;
    pitem lst = in_table(n, m);
    for (i = 0; i < q; i++)
    {
        int a = getint(), b = getint(),
            c = getint(), d = getint(),
            h = getint(), w = getint();
        swap_it(find_item(lst, a-1, b-1), find_item(lst, c-1, d-1), h, w);
    }
    out_table(lst);
    return 0;
}
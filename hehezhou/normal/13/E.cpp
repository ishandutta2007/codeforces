#include <bits/stdc++.h>
using namespace std;
struct node
{
    int son[2], size, fa, tag;
    inline int &operator[](int x)
    {
        return son[x];
    }
} e[100010];
inline void up(int x)
{
    e[x].size = e[e[x][0]].size + e[e[x][1]].size + 1;
}
inline void down(int x)
{
    if (e[x].tag)
    {
        swap(e[x][0], e[x][1]);
        e[e[x][0]].tag ^= 1, e[e[x][1]].tag ^= 1, e[x].tag = 0;
    }
}
inline int nroot(int x)
{
    return e[x].fa && (e[e[x].fa][1] == x || e[e[x].fa][0] == x);
}
inline void rotate(int x)
{
    down(e[e[x].fa].fa), down(e[x].fa), down(x);
    int f = e[x].fa, g = e[e[x].fa].fa, k = (x == e[f].son[1]), kk = (e[g].son[1] == f);
    e[f].son[k] = e[x].son[k ^ 1];
    if (e[x].son[k ^ 1])
        e[e[x].son[k ^ 1]].fa = f;
    e[x].fa = e[f].fa;
    if (nroot(f))
        e[g].son[kk] = x;
    e[x].son[k ^ 1] = f, e[f].fa = x;
    up(f), up(x);
}
inline void splay(int x)
{
    while (nroot(x))
    {
        down(e[e[x].fa].fa);
        down(e[x].fa);
        if (nroot(e[x].fa))
            if ((e[e[x].fa][1] == x) ^ (e[e[e[x].fa].fa][1] == e[x].fa))
                rotate(x);
            else
                rotate(e[x].fa);
        rotate(x);
    }
}
void access(int x)
{
    for (int y = 0; x; y = x, x = e[x].fa)
        splay(x), down(x), e[x][1] = y, e[y].fa = x, up(x);
}
void make_root(int x)
{
    access(x), splay(x), e[x].tag ^= 1;
}
void link(int x, int y)
{
    make_root(x);
    e[x].fa = y;
}
int split(int x, int y)
{
    make_root(x), access(y), splay(y);
    return y;
}
void cut(int x, int y)
{
    split(x, y);
    e[y].son[0] = e[x].fa = 0;
    up(y);
}
int n, m, a[100010];
int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n + 1; i++)
        e[i].size = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        link(i, a[i] = min(n + 1, a[i] + i));
    }
    for (int i = 1; i <= m; i++)
    {
        int opt, l;
        scanf("%d%d", &opt, &l);
        if (opt == 1) {
            int ans = e[split(n + 1, l)].size - 1;
            splay(n + 1);
            down(n + 1);
            int d = e[n + 1].son[1];
            while(down(d), e[d].son[0]) d = e[d].son[0];
            printf("%d ", d);
            printf("%d\n", ans);
        }
        else
            cut(a[l], l), scanf("%d", a + l), link(l, a[l] = min(n + 1, a[l] + l));
    }
    return 0;
}
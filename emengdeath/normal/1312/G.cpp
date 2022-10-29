#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 100;
struct node{
    int son[26];
    int id, tag;
    int deep, all, v;
}tri[N];
int n, m;
int ans[N];
void dfs(int x) {
    tri[x].tag = 1e9;
    tri[x].v = tri[x].deep;
    if (tri[x].id) {
        tri[x].all = 1;
    }
    for (int i = 0; i < 26; i ++)
        if (tri[x].son[i]) {
            tri[tri[x].son[i]].deep = tri[x].deep + 1;
            dfs(tri[x].son[i]);
            tri[x].all += tri[tri[x].son[i]].all;
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        tri[x].son[c - 'a'] = i;
    }
    scanf("%d", &m);
    for (int i= 1; i <= m; i ++) {
        int x;
        scanf("%d", &x);
        tri[x].id = i;
    }
    dfs(0);
    for (int i = 0; i <= n; i ++) {
        if (tri[i].id) {
            tri[i].v = min(tri[i].v, tri[i].tag);
        }
        if (tri[i].id)
            tri[i].tag = min(tri[i].v + 2, tri[i].tag +1);
        else
            tri[i].tag = min(tri[i].v + 1, tri[i].tag);
        for (int j= 0; j < 26; j ++)
            if (tri[i].son[j]) {
                tri[tri[i].son[j]].v = min(tri[tri[i].son[j]].v, tri[i].v + 1);
                tri[tri[i].son[j]].tag = min(tri[tri[i].son[j]].tag, tri[i].tag);
                tri[i].tag += tri[tri[i].son[j]].all;
            }
        if (tri[i].id)
            ans[tri[i].id] = tri[i].v;
    }
    for (int i = 1; i <= m; i ++)
        printf("%d%c", ans[i], " \n"[i == m]);
    return 0;
}
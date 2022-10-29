#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n;
char s[N];
int fa[N * 2], tot;
int ans = 0;
struct node{
    int son[26];
    int have, deep, fa;
}tri[N * 2];
int id[N];
int getfa(int x) {
    return fa[x] == x  ? x : fa[x] = getfa(fa[x]);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i <= 200000; i ++) fa[i] = i;
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s);
        int len = strlen(s), x = 0;
        for (int j = 0; j < len; j ++) {
            if (!tri[x].son[s[j] - 'a']) {
                tri[x].son[s[j] - 'a'] = ++tot;
                tri[tot].deep = j + 1;
                tri[tot].fa = x;
            }
            x = tri[x].son[s[j] - 'a'];
        }
        tri[x].have = 1;
        ans += len;
    }
    for (int i = 1; i <= tot; i ++)
        id[i] = i;
    sort(id + 1, id + tot + 1, [](int x, int y){
        return tri[x].deep > tri[y].deep;
    });
    for (int i = 1; i <= tot; i ++)
        if (tri[tri[i].fa].have && tri[i].have)
            fa[i] = tri[i].fa;
    for (int i = 1; i<= tot; i ++)
        if (tri[id[i]].have){
            int x = getfa(id[i]);
            while (tri[x].fa && tri[tri[x].fa].have) {
                fa[x] = tri[x].fa;
                x = getfa(x);
            }
            if (tri[x].fa) {
                ans =  ans - tri[id[i]].deep+ tri[tri[x].fa].deep;
                fa[x] = tri[x].fa;
                tri[tri[x].fa].have = 1;
            }
        }
    printf("%d\n", ans);
    return 0;
}
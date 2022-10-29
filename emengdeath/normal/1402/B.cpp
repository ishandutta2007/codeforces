#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int AC_N = 1e6;
const int AC_C = 26;
struct node {
    int son[AC_C];
    int match[AC_C];
    int sum, fail;
    int l, r;
    vector<int> g;
    void clear() {
        memset(son, 0, sizeof(son));
        memset(match, 0, sizeof(match));
        sum = fail = 0;
    }
} tri[AC_N];
int L;
int ins(int s, char *s1, int len) {
    for (int i = 0; i < len; i++) {
        if (!tri[s].son[s1[i] - 'a'])
            tri[s].son[s1[i] - 'a'] = ++L;
        s = tri[s].son[s1[i] - 'a'];
    }
    tri[s].sum++;
    return s;
}
int next(int x, int c) {
    while (x && !tri[x].son[c]) x = tri[x].fail;
    if (tri[x].son[c]) x = tri[x].son[c];
    return x;
}
int cnt=  0;
void dfs(int x) {
    tri[x].l = ++cnt;
    for (auto u:tri[x].g)
        dfs(u);
    tri[x].r = cnt;
}

void build() {
    vector<int>d;
    int x;
    d.push_back(0);
    for (int l = 0; l < d.size(); l ++) {
        for (int i = 0; i < AC_C; i++)
            if (x = tri[d[l]].son[i]) {
                d.push_back(x);
                tri[x].fail = next(tri[d[l]].fail, i);
                if (tri[x].fail == x) tri[x].fail = 0;
            }
        if (d[l])
            tri[tri[d[l]].fail].g.push_back(d[l]);
    }
    for (auto u:d)
        for (int i= 0; i < AC_C; i ++)
            tri[u].match[i] = (tri[u].son[i]? tri[u].son[i] : tri[tri[u].fail].match[i]);
    dfs(0);
}
const int N = 1e6;

int f[N];
int ans[N];
vector<pair<int,int> >g[N], q[N];
int a[N];
int n, m;
char s[N];
int get(int x) {
    int v = 0;
    while (x) {
        v += f[x];
        x -= x &-x;
    }
    return v;
}
void ins(int x, int y) {
    while (x <= cnt) {
        f[x] += y;
        x += x & -x;
    }
}
int get(int l, int r) {
    return get(r) - get(l - 1);
}
void dfs1(int x, int s){
    ins(tri[s].l, 1);
    for (auto u:q[x])
        ans[u.second] = get(tri[u.first].l, tri[u.first].r);
    for (auto u:g[x]) {
        dfs1(u.first, tri[s].match[u.second]);
    }
    ins(tri[s].l, -1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x, y;
        char c;
        scanf("%d", &x);
        if (x == 1) {
            scanf(" %c", &c);
            y = 0;
        } else {
            scanf("%d %c", &y, &c);
        }
        g[y].push_back({i, c - 'a'});
    }
    scanf("%d", &m);
    for (int i= 1; i <= m; i ++) {
        int x, len;
        scanf("%d %s", &x, s);
        len = strlen(s);
        int y = ins(0, s,len);
        q[x].push_back({y, i});
    }
    build();
    dfs1(0, 0);
    for (int i= 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}
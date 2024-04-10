#include <algorithm>
#include <cstdio>
#include <vector>
#define index index233
using namespace std;//
const int N = 5e5;
struct node{
    int son[26];
    int len, fail;
}tri[N];
char S[N];
int n, q;
int lst, L;
int index[N], dfn[N];
vector<int>g[N];
int deep[N], fa[N][20];
pair<int, int>a[N];
int sum[N][2];
int bz[N], tag;
long long ans = 0;
void add(int last,int c){
    static int v,u,up,up1;
    v=++L;
    u=last;
    tri[v].len=tri[u].len+1;
    for (;u&&!tri[u].son[c];u=tri[u].fail)tri[u].son[c]=v;
    if (!u)tri[v].fail=1;
    else{
        up=tri[u].son[c];
        if (tri[up].len==tri[u].len+1)tri[v].fail=up;
        else{
            up1=++L;
            tri[up1]=tri[up];
            tri[up1].len=tri[u].len+1;
            tri[up].fail=tri[v].fail=up1;
            for (;u&&tri[u].son[c]==up;u=tri[u].fail)tri[u].son[c]=up1;
        }
    }
    lst=v;
}
void dfs(int x) {
    static int cnt = 0;
    deep[x] ++;
    dfn[x] = ++cnt;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
        }
}
int up(int x, int y){
    const int S = 19;
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i))
            y -= (1 << i), x = fa[x][i];
    return x;
}
int getlca(int x, int y) {
    const int S = 19;
    if (deep[x] < deep[y])
        swap(x, y);
    x = up(x, deep[x] - deep[y]);
    for (int i = S; i >= 0; i --)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return x != y ? fa[x][0] : x;
}
vector<int> d;
void check(int x) {
    if (bz[x] != tag) {
        bz[x] = tag;
        sum[x][0] = sum[x][1] = 0;
    }
}
void link(int x, int y) {
    check(x), check(y);
    ans += 1ll * tri[x].len * (1ll * sum[x][0] * sum[y][1] + 1ll * sum[x][1] * sum[y][0]);
    sum[x][0] += sum[y][0];
    sum[x][1] += sum[y][1];
}
void add(int x) {//dfs
    if (d.empty()){
        d.push_back(x);
    } else {
        if (getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
            int last = d[d.size() - 1];
            d.pop_back();
            while (!d.empty() && getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
                link(d[d.size() - 1], last);
                last = d[d.size() - 1];
                d.pop_back();
            }
            if (d.empty() || getlca(last, x) != d[d.size() - 1] ) {
                int u = getlca(last, x);
                link(u, last);
                d.push_back(u);
            } else {
                link(d[d.size() - 1], last);
            }
        }
        d.push_back(x);
    }
}
int main() {
    scanf("%d %d", &n, &q);
    scanf(" %s",S+1);
    reverse(S + 1, S + n + 1);
    lst=1,L=1;
    for (int i=1;i<=n;i++){
        add(lst,S[i]-'a');
        index[i] = lst;
    }
    for (int i = 2; i <= L; i ++)
        g[tri[i].fail].push_back(i);
    dfs(1);
    while (q --) {
        int w1, w2;
        scanf("%d %d", &w1, &w2);
        ++tag;
        for (int i = 1; i <= w1; i ++)
            scanf("%d", &a[i].first), a[i].first = index[n - a[i].first + 1], a[i].second = 0;
        for (int i = 1; i <= w2; i ++)
            scanf("%d", &a[i + w1].first), a[i + w1].first = index[n - a[i + w1].first + 1], a[i + w1].second = 1;
        ans = 0;
        for (int i = 1; i <= w1 + w2; i ++) {
            check(a[i].first);
            sum[a[i].first][a[i].second] ++;
            ans += sum[a[i].first][0] * sum[a[i].first][1] * tri[a[i].first].len;
        }
        sort(a + 1,a + w1 + w2 + 1, [](pair<int, int>a, pair<int, int>b) {
            return dfn[a.first] < dfn[b.first];
        });
        d.clear();
        for (int i = 1; i <= w1 + w2; i ++)
            if (a[i].first != a[i - 1].first) {
                add(a[i].first);
            }
        while (d.size() > 1) {
            link(d[d.size() - 2], d[d.size() - 1]);
            d.pop_back();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
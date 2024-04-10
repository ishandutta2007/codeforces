#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define ri register int
#define il inline
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define mem0(x) memset((x),0,sizeof (x))
#define mem1(x) memset((x),0x3f,sizeof (x))
#define gc getchar
#define pb push_back
template<class T>void in(T &x)
{
    x = 0; bool f = 0; char c = gc();
    while (c < '0' || c > '9') {if (c == '-') f = 1; c = gc();}
    while ('0' <= c && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = gc();}
    if (f) x = -x;
}
#undef gc
void out(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) out(x / 10);
    putchar(x % 10 + '0');
}
#define N 10010
#define M N<<2
int n, m;
int v[M], u[M], nx[M], k[M];
int cnt = 1, head[N];
il void add(int uu, int vv) {
    u[++cnt] = uu, v[cnt] = vv, nx[cnt] = head[uu];
    head[uu] = cnt;
    k[cnt] = (cnt >> 1);
}
int dep[N];
bool vis[N];
int tag[N];
int zt;
vector<int>ans;
int lst;
void dfs(int x, int f, int d) {
    //printf("V %d\n",x);
    dep[x] = d;
    vis[x] = 1;
    for (ri i = head[x]; i; i = nx[i]) {
        if (i == f) continue;
        if (!vis[v[i]]) {
            dfs(v[i], i ^ 1, d + 1);
        }
        else {
            if (dep[v[i]] < dep[x]) continue;
            if ((dep[v[i]] - dep[x] + 1) & 1) {
                tag[x]--;  // in fact +1 -2
                tag[v[i]]++;
                zt++;
                lst=k[i];
            }
            else {
                tag[x]++;
                tag[v[i]]--;
            }
        }
    }
}
int dfs2(int x, int f) {
    vis[x] = 1;
    int res = tag[x];
    for (ri i = head[x]; i; i = nx[i]) {
        if (vis[v[i]]) continue;
        res += dfs2(v[i], i);
    }
    if (res == zt) ans.pb(k[f]);
    //printf("T %d %d %d\n",x,res,tag[x]);
    return res;
}
signed main() {
    in(n), in(m);
    for (ri i = 1, a, b; i <= m; ++i) {
        in(a), in(b);
        add(a, b);
        add(b, a);
    }
    for (ri i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, 0, 0);
    }
    if (zt == 0) {
        //cout << "A";
        printf("%d\n", m);
        for (ri i = 1; i <= m; ++i) printf("%d ", i);
        return 0;
    }
    if(zt==1) ans.pb(lst);
    //cout<<zt;
    mem0(vis);
    for (ri i = 1; i <= n; ++i) {
        if (!vis[i]) dfs2(i, 0);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (ri i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
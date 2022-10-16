#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,m;
vector<int> g[1100000];
int in[1100000];
int out[1100000];
int snkidx[1100000];
int seen[1100000];
int r[1100000];
int cc;
int snkcnt;

vector<int> src;

int dfs(int i) {
    int r = 0;
    seen[i] = cc;
    if (out[i] == 0) r |= (1<<snkidx[i]);
    for (int x : g[i]) if (seen[x] != cc) r |= dfs(x);
    return r;
}

void solve()
{
    re(n,m);
    rep(i,0,m) {
        int u,v; re(u,v); u--; v--;
        g[u].push_back(v);
        in[v]++; out[u]++;
    }

    rep(i,0,n) {
        if (!in[i]) {
            src.push_back(i);
        }
        if (!out[i]) {
            snkidx[i] = snkcnt++;
        }
    }

    rep(i,0,n) if (!in[i]) {
        cc++;
        r[(1<<i)] = dfs(i);
    }

    for (int i = 1; i < (1<<snkcnt)-1; i++) {
        int bit = i&-i;
        r[i] = r[i^bit] | r[bit];
        if (__builtin_popcount(r[i]) == __builtin_popcount(i)) {
            ps("NO");
            return;
        }
    }

    ps("YES");
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
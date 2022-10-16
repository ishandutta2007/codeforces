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

void pr(int x);

void pr(char x);
void pr(const char *x);

template<class T> void pr(const std::vector<T> x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int d[310000];
int pick[310000];
vector<pii> g[310000];
int seen[310000];
int n,m;

int dfs(int v) {
    seen[v] = true;
    int cnt = (d[v]==1);
    for (auto p : g[v]) if (!seen[p.first]) {
        int t = dfs(p.first);
        cnt ^= t;
        pick[p.second] ^= t;
    }
    return cnt;
}

void solve()
{
    re(n,m);
    rep(i,0,n) re(d[i]);
    
    rep(i,0,m) {
        int u,v; re(u,v); u--; v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }

    int s = 0;
    rep(i,0,n) if (d[i] != -1) s ^= d[i];
    if (s == 1) {
        bool ok = false;
        rep(i,0,n) if (d[i] == -1) {
            d[i] = 1; ok = true; break;
        }
        if (!ok) { ps(-1); return; }
    }

    rep(i,0,n) if (d[i] == 1) {
        dfs(i);        
        break;
    }

    vector<int> ans;
    rep(i,0,m) if (pick[i]) ans.push_back(i+1);
    ps(sz(ans));
    ps(ans);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }

template<class T> void pr(std::vector<T> v) {
    int f=0;
    for (int x : v) {
        if (f++) pr(' ');
        pr(x);
    }
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
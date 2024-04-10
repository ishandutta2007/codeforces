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

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
vi g[310000];
int u,v;

const int mod = 998244353;

int pd[310000][2][2];

int rec(int v, int p, int par_edge, int took_par) {
    int &ret = pd[v][par_edge][took_par];
    if (ret == -1) {
        ret = 0;

        // take v
        if (!took_par) {
            int acc = 1;
            int p2 = 1;
            for (int x : g[v]) if (x != p) {
                acc = (acc*1ll*(rec(x,v,0,0)+rec(x,v,1,1))) % mod;
            }        
            if (!par_edge) {
                int tacc = 1;
                for (int x : g[v]) if (x != p) {
                    tacc = (tacc*1ll*(rec(x,v,0,0))) % mod;
                }
                acc -= tacc;
                if (acc < 0) acc += mod;
            }

            ret = (ret+acc) % mod;
            // dbg(v,p,par_edge,took_par,acc);
        }

        // don't take v
        int acc = 1;
        for (int x : g[v]) if (x != p) {
            acc = (acc*1ll*(rec(x,v,1,0)+rec(x,v,0,0))) % mod;
            // dbg(v,p,par_edge,took_par,rec(x,v,1,0),rec(x,v,0,0));
        }
        ret = (ret+acc) % mod;
    }
    return ret;
}

void solve()
{
    memset(pd,-1,sizeof(pd));

    re(n);
    rep(i,0,n-1) {
        re(u,v); u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = rec(0, -1, 0, 0);
    ans--;
    if (ans < 0) ans += mod;
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

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
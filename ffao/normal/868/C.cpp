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

int g[110000][5];
int has[16];
int n,k;

void solve()
{
    re(n,k);
    rep(i,0,n) rep(j,0,k) re(g[i][j]);

    rep(j,0,k) {
        int ct = 0;
        rep(i,0,n) ct += g[i][j];
        if (ct == n) {
            ps("NO");
            return;
        }
    }

    rep(i,0,n) {
        int s = 0;
        rep(j,0,k) s += g[i][j];
        if (s <= 1) {
            ps("YES");
            return;
        }
    }

    if (k == 4) {
        rep(i,0,n) {
            int th = 0;
            rep(j,0,k) th += (1<<j) * g[i][j];
            // ps(th);
            has[th]++;
        }

        rep(th,0,16) if (has[th] && has[th^15]) {
            // ps(th);
            ps("YES");
            return;
        }
    }

    ps("NO");
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
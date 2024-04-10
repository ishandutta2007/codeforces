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

void pr(long long x);

void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
char g[20][20];
vector<long long> ans[17000][16][16];

void calc(int bm, int s, int e) {
    vector<long long>& v = ans[bm][s][e];

    if (v.empty()) {
        vi contains;

        int obm = bm;
        while (bm) {
            int bit = __builtin_ctz(bm&-bm);
            contains.push_back(bit);
            bm -= bm&-bm;
        }
        bm = obm;

        int tam = sz(contains);
        v.resize(1<<(tam-1));
        if (tam == 1) {
            v[0] = 1;
            return;
        }
        if (tam == 2) {
            if (s == n && e == n) v[g[contains[0]][contains[1]]] = 2;
            else v[g[contains[0]][contains[1]]] = 1;
            return;
        }

        int le = (tam-1)/2 + 1;
        int ri = tam - le + 1;

        for (int k = bm; k > 0; k = (k-1) & bm) {
            if (__builtin_popcount(k) == le && (s == n || (1<<s) & k) && (e == n || !((1<<e) & k))) {
                int ok = k;
                while (ok) {
                    int md = __builtin_ctz(ok&-ok);
                    ok -= ok&-ok;
                    if (md == s || md == e) continue;

                    calc(k, s, md);
                    calc(bm - k + (1<<md), md, e);

                    rep(i, 0, (1<<(le-1))) {
                        rep(j, 0, (1<<(ri-1))) {
                            v[i*(1<<(ri-1))+j] += ans[k][s][md][i] * 1ll * ans[bm-k+(1<<md)][md][e][j];
                        }
                    }
                }
            }
        }
    }

    return;
}

void solve()
{
    re(n);
    rep(i,0,n) scanf("%s", g[i]);
    rep(i,0,n) rep(j,0,n) g[i][j]-='0';

    calc((1<<n)-1,n,n);

    rep(i,0,(1<<(n-1))) pr(ans[(1<<n)-1][n][n][i], " ");
    ps();
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
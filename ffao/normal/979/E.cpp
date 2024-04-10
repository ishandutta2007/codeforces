#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n, p;
int c[51];
int dp[51][51][51];
int binom[61][61];
int p2[51];
const int mod = 1000000007;

int rec(int cur, int bp, int wp) {
    if (cur == n) return (bp+wp)%2 == p;
    
    int &ret = dp[cur][bp][wp];
    if (ret == -1) {
        ret = 0;

        for (int cc = 0; cc <= 1; cc++) {
            if (c[cur] != -1 && c[cur] != cc) continue;
            
            int od;
            if (cc == 0) od = wp;
            else od = bp;
            int ev = cur - od;

            for (int con_od = 0; con_od <= 1; con_od++) {
                int nbp = bp, nwp = wp;
                if (con_od % 2 == 0) {
                    if (cc == 0) nbp++;
                    else nwp++;
                }

                int hm;
                if (od == 0) hm = (con_od == 0);
                else hm = p2[od-1];

                long long th = (rec(cur+1, nbp, nwp) * 1ll * p2[ev]) % mod;
                th = (th * 1ll * hm) % mod;
                ret = (ret + th) % mod;
            }
        }

        //printf("%d %d %d -> %d\n", cur,bp,wp,ret);
    }
    return ret;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    re(n,p);
    rep(i,0,n) re(c[i]);

    p2[0] = 1;
    for (int i = 1; i <= 50; i++) p2[i] = (p2[i-1] + p2[i-1]) % mod;

    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) binom[i][j] = 1;
            else binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
        }
    }

    ps(rec(0,0,0));
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
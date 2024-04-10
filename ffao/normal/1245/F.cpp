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


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


int t;
int l, r;

int Lbin[30];
int Rbin[30];

long long dp[30][2][2][2][2][2][2][2][2];

long long rec(int p, 
              int Abigl, int Aeql, int Asmr, int Aeqr, 
              int Bbigl, int Beql, int Bsmr, int Beqr) {
    
    if (p == 30) {
        return 1;
    }
    
    long long &ret = dp[p][Abigl][Aeql][Asmr][Aeqr][Bbigl][Beql][Bsmr][Beqr];
    if (ret == -1) {
        ret = 0;

        // none
        if ( (!Aeql && !Beql) || Lbin[p] == 0) {
            int nAbigl = Abigl;
            int nAeql = Aeql && Lbin[p] == 0;
            int nAsmr = Asmr || Rbin[p] == 1;
            int nAeqr = Aeqr && Rbin[p] == 0;
            int nBbigl = Bbigl;
            int nBeql = Beql && Lbin[p] == 0;
            int nBsmr = Bsmr || Rbin[p] == 1;
            int nBeqr = Beqr && Rbin[p] == 0;
            
            ret += rec(p+1, nAbigl, nAeql, nAsmr, nAeqr, nBbigl, nBeql, nBsmr, nBeqr);
        }

        // B
        if (!Aeql || Lbin[p] == 0) {
            if (!Beqr || Rbin[p] == 1) {
                int nAbigl = Abigl;
                int nAeql = Aeql && Lbin[p] == 0;
                int nAsmr = Asmr || Rbin[p] == 1;
                int nAeqr = Aeqr && Rbin[p] == 0;

                int nBbigl = Bbigl || Lbin[p] == 0;
                int nBeql = Beql && Lbin[p] == 1;
                int nBsmr = Bsmr;
                int nBeqr = Beqr && Rbin[p] == 1;
                
                ret += rec(p+1, nAbigl, nAeql, nAsmr, nAeqr, nBbigl, nBeql, nBsmr, nBeqr);
            }
        }

        // A
        if (!Beql || Lbin[p] == 0) {
            if (!Aeqr || Rbin[p] == 1) {
                int nAbigl = Abigl || Lbin[p] == 0;
                int nAeql = Aeql && Lbin[p] == 1;
                int nAsmr = Asmr;
                int nAeqr = Aeqr && Rbin[p] == 1;

                int nBbigl = Bbigl;
                int nBeql = Beql && Lbin[p] == 0;
                int nBsmr = Bsmr || Rbin[p] == 1;
                int nBeqr = Beqr && Rbin[p] == 0;
                
                ret += rec(p+1, nAbigl, nAeql, nAsmr, nAeqr, nBbigl, nBeql, nBsmr, nBeqr);
            }
        }
    }
    return ret;

}

void solve()
{
    for (re(t); t; t--) {
        re(l, r);
        for (int i = 29; i >= 0; i--) {
            Lbin[29-i] = !!(l & (1<<i));
            Rbin[29-i] = !!(r & (1<<i));
        }

        memset(dp,-1,sizeof(dp));
        ps(rec(0,0,1,0,1,0,1,0,1));
    }    
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
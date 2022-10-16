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

template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);

int n,m;
int tt[61][61];
int agg[61][61];
int inv[150];
const int mod = 1000000007;

void solve()
{
    for (int i = 1; i <= 140; i++) inv[i] = modInv(i, mod);

    re(n,m);

    tt[0][0] = 1;
    for (int toto = 0; toto <= n-1; toto++) {
        for (int cutl = 0; cutl <= toto/2; cutl++) {
            int cut = cutl+1;
        
            long long poss = 0;
            for (int left = cutl; left <= toto-cutl; left++) {
                if (!tt[cutl][left]) break;
                int right = toto-left;
                long long right_poss = (2ll * agg[right][cutl+1] + tt[cutl][right]) % mod;
                long long bposs = (tt[cutl][left] * right_poss) % mod;
                poss = (bposs+poss)%mod;
            }

            for (int po = n-toto-1; po >= 0; po--) {
                for (int pc = n-cut; pc >= 0; pc--) {
                    int lim = min( (n-pc)/cut, (n-po)/(toto+1) );

                    int comb = (poss * 1ll * tt[pc][po]) % mod;

                    for (int hm = 1; hm <= lim; hm++) {
                        int& dest = tt[pc + cut*hm][po + (toto+1)*hm];
                        dest = (dest + comb) % mod;

                        comb = (comb * 1ll * (poss+hm)) % mod;
                        comb = (comb * 1ll * inv[hm+1]) % mod;
                    }
                }
            }
        }

        for (int cut = toto+1; cut >= 0; cut--) {
            agg[toto+1][cut] = (tt[cut][toto+1] + agg[toto+1][cut+1]) % mod;
        }
    }
    
    ps(tt[m-1][n]);
}

int main() {

    solve();
}

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
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
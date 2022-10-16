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


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


using namespace std;


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

void pc();
template<class T, class... Ts> void pc(const T& t, const Ts&... ts);

#define dbg(x...) pr("[",#x,"] = ["), pc(x);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


const int mod = 1000000007;
int p[110000];
int fac[110000];
int ifac[110000];

int calc(int n, int fr) {
    if (n < fr) return 0;
    int p = (fac[n-1] * 1ll * ifac[fr-1]) % mod;
    p = (p * 1ll * ifac[n-fr]) % mod;
    return p;
}

void solve()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fac[i] = (fac[i-1] * 1ll * i) % mod;
        ifac[i] = modInv(fac[i], mod);
    }

    for (int i = 2; i <= 100000; i++) if (p[i] == 0) {
        for (int j = i+i; j <= 100000; j+=i) if (!p[j]) p[j] = i;
    }

    int q, n, f;
    re(q);
    REP(i,q) {
        re(n, f);

        vector<int> ppp;
        int on = n;
        while (n != 1) {
            int d = (p[n] == 0 ? n : p[n]);
            while (n % d == 0) n /= d;
            ppp.push_back(d);
        }
        n = on;

        int ans = 0;
        for (int i = 0; i < (1<<ppp.size()); i++) {
            REP(j,ppp.size()) if (i & (1<<j)) n /= ppp[j];
            
            int th = calc(n, f);
            //dbg(n, f, th);
            if (__builtin_popcount(i) % 2 == 0) ans = (ans + th) % mod;
            else ans = ((ans - th) % mod + mod) % mod;

            n = on;
        }

        ps(ans);
    }
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

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

void pc() { pr("]\n"); }
template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
}
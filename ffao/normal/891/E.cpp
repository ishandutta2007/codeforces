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
void re(long long& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);
template<class T> void re(std::vector<T>& a);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);

typedef vector<int> vi;

int n;
long long k;

long long allprods[5100][5100];
const int mod = 1000000007;

long long modpow(long long b, long long e) {
    long long r = 1;
    while (e) {
        if (e&1) r = (r * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return r;
}

void solve()
{
    re(n,k);
    vi a(n); re(a);

    for (int i = 0; i <= n; i++) {
        allprods[i][0] = 1;
        for (int cnt = 1; cnt <= i; cnt++) {
            allprods[i][cnt] = (allprods[i-1][cnt] + allprods[i-1][cnt-1] * 1ll * a[i-1]) % mod;
        }
    }

    long long ans = 0;

    for (int m1 = 0; m1 <= n && m1 <= k; m1++) {
        long long locfa = 1;
        for (int locs = 0; locs < m1; locs++) {
            locfa = (locfa * (k - locs)) % mod;
        }

        long long th = (allprods[n][n - m1] * 1ll * locfa) % mod;
        th = (th * 1ll * modpow(n, k - m1));
        if (m1 % 2 == 1) th = (mod - th) % mod;

        ans = (ans + th) % mod;
    }

    ans = (ans * 1ll * modpow(modInv(n, mod), k)) % mod;
    ans = (allprods[n][n] - ans) % mod;
    if (ans < 0) ans += mod;

    ps(ans);
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
void re(long long& x) { scanf("%lld", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
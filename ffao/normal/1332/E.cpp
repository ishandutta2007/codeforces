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

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef long long ll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,m,l,r;

const int mod = 998244353;

template<class T, int N> struct Matrixa {
	typedef Matrixa M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) a.d[i][j] = (a.d[i][j] + d[i][k]*1ll*m.d[k][j]) % mod;
		return a;
	}
	M operator^(ll p) const {
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

void solve()
{
    re(n,m,l,r);    
    r -= l;

    long long sq = n*1ll*m;

    int is_odd = (n % 2 == 1) && (m % 2 == 1);

    int e = (r+2)/2;
    int o = (r+1)-e;

    Matrixa<ll, 2> m;
    rep(i,0,2) rep(j,0,2) m.d[i][j] = (i==j ? e : o);
    m = m ^ sq;

    long long a = m.d[0][0];
    if (is_odd) a = (a + m.d[0][1]) % mod;
    ps(a);
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
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <cstring>

char s[110000];
char t[110000];
int sn, tn;
int c[2][2];
int d[2][2];
int cnt[2][2];

const int mod = 1000000007;

int fac[210000];
int ifac[210000];

int stars_bars(int n, int k) {
    if (k == 0) return n == 0;

    int th = (fac[n+k-1] * 1ll * ifac[k-1]) % mod;
    return (th * 1ll * ifac[n]) % mod;
}

int count(int cur, int d[2][2]) {
    rep(i,0,2) rep(j,0,2) if (d[i][j] < 0) return 0;

    if (d[cur][cur^1] - d[cur^1][cur] > 1) return 0;
    if (d[cur^1][cur] > d[cur][cur^1]) return 0;

    int cur_blocks = d[cur^1][cur] + 1;
    int ot_blocks = d[cur][cur^1];

    int ans = 1;
    ans = (ans * 1ll * stars_bars(d[cur][cur], cur_blocks)) % mod;
    ans = (ans * 1ll * stars_bars(d[cur^1][cur^1], ot_blocks)) % mod;
    return ans;
}

int counta(int n, char* a) {
    memcpy(d,c,sizeof(c));
    int tot = count(1, d);

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            d[a[i-1]][1]--;
            tot = (tot - count(1, d)) % mod;
            if (tot < 0) tot += mod;
            d[a[i-1]][1]++;
        }

        d[a[i-1]][a[i]]--;
    } 

    return tot;
}

void solve()
{
    fac[0] = ifac[0] = 1;
    rep(i,1,210000) {
        fac[i] = (fac[i-1] * 1ll * i) % mod;
        ifac[i] = modInv(fac[i], mod);
    }

    scanf("%s %s", s, t);
    sn = strlen(s); tn = strlen(t);
    rep(i,0,sn) s[i]-='0';
    rep(i,0,tn) t[i]-='0';
    
    int totsz = 1;
    rep(i,0,2) rep(j,0,2) {
        re(c[i][j]);
        totsz += c[i][j];
    }

    int ans = 0; 
    if (totsz >= sn && totsz < tn) ans = count(1, c);

    if (sn == totsz) ans = (ans - counta(totsz, s)) % mod;
    if (tn == totsz) ans = (ans + counta(totsz, t)) % mod;

    // dbg(count(1,c));

    rep(i,0,sn-1) {
        cnt[s[i]][s[i+1]]++;
    }

    int cnteq = 0;
    rep(i,0,2) rep(j,0,2) cnteq += (cnt[i][j] == c[i][j]);
    if (cnteq == 4) {
        ans = (ans + 1) % mod;
    }

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

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
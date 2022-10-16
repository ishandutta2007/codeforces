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
 
 
struct FFT_mod {
	int mod, root, root_1, root_pw;
};
 
extern FFT_mod suggested_fft_mods[5];
 
void ntt_shortmod(std::vector<int>& a, bool invert, const FFT_mod& mod_data);
 
 
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
 
 
int ns, nt, k;
char s[210000];
char t[210000];
int matches[210000];
 
const FFT_mod mod = suggested_fft_mods[0];
 
void go(int look_for) {
    //dbg(look_for);
    vector<int> fuzzy_s(524288);
    vector<int> fuzzy_t(524288);
 
    int last_seen = -k - 1;
    REP(i,ns) {
        if (s[i] == look_for) last_seen = i;
        fuzzy_s[i] |= (i - last_seen <= k);
    }
 
    last_seen = ns + k + 1;
    for (int i = ns-1; i >= 0; i--) {
        if (s[i] == look_for) last_seen = i;
        fuzzy_s[i] |= (last_seen - i <= k);
        //dbg(i, fuzzy_s[i]);
    }
 
    REP(i, nt) fuzzy_t[nt-i-1] = (t[i] == look_for);
 
    ntt_shortmod(fuzzy_s, false, mod);
    ntt_shortmod(fuzzy_t, false, mod);
    REP(i, fuzzy_t.size()) fuzzy_t[i] = (fuzzy_t[i] * 1ll * fuzzy_s[i]) % mod.mod;
    ntt_shortmod(fuzzy_t, true, mod);
 
    REP(i,ns) {
        //dbg(look_for, i, fuzzy_t[i + (nt-1)]);
        matches[i] += fuzzy_t[i + (nt-1)];
    }
}
 
void solve()
{
    re(ns,nt,k);
    scanf("%s", s); scanf("%s", t);
 
    REP(i, ns) {
        if (s[i] == 'A') s[i] = 1;
        if (s[i] == 'G') s[i] = 2;
        if (s[i] == 'C') s[i] = 3;
        if (s[i] == 'T') s[i] = 4;
    }
 
    REP(i, nt) {
        if (t[i] == 'A') t[i] = 1;
        if (t[i] == 'G') t[i] = 2;
        if (t[i] == 'C') t[i] = 3;
        if (t[i] == 'T') t[i] = 4;
    }
 
    for (int i = 1; i <= 4; i++) {
        go(i);
    }
 
    int ans = 0;
    REP(i,ns) ans += (matches[i] == nt);
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
 
 
FFT_mod suggested_fft_mods[] = {
	{ 7340033, 5, 4404020, 1 << 20 },
	{ 415236097, 73362476, 247718523, 1<<22 },
	{ 463470593, 428228038, 182429, 1<<21},
	{ 998244353, 15311432, 469870224, 1 << 23 },
	{ 918552577, 86995699, 324602258, 1 << 22 }
};
 
int FFT_w[1050000];
int FFT_w_dash[1050000];
 
 
void ntt_shortmod(std::vector<int>& a, bool invert, const FFT_mod& mod_data) {
	// only use if mod < 5*10^8
	int n = (int)a.size();
	int mod = mod_data.mod;
 
	for (int i = 1, j = 0; i<n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			std::swap(a[i], a[j]);
	}
 
	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? mod_data.root_1 : mod_data.root;
		for (int i = len; i<mod_data.root_pw; i <<= 1)
			wlen = int(wlen * 1ll * wlen % mod_data.mod);
		long long tt = wlen;
		for (int i = 1; i < len / 2; i++) {
			FFT_w[i] = tt;
			FFT_w_dash[i] = (tt << 31) / mod;
			int q = (FFT_w_dash[1] * 1ll * tt) >> 31;
			tt = (wlen * 1ll * tt - q * 1ll * mod) & ((1LL << 31) - 1);
			if (tt >= mod) tt -= mod;
		}
		for (int i = 0; i<n; i += len) {
			int uu = a[i], vv = a[i + len / 2] % mod;
			if (uu >= 2*mod) uu -= 2*mod;
			a[i] = uu + vv;
			a[i + len / 2] = uu - vv + 2 * mod;
 
			for (int j = 1; j<len / 2; ++j) {
				int u = a[i + j];
				if (u >= 2*mod) u -= 2*mod;
				int q = (FFT_w_dash[j] * 1ll * a[i + j + len / 2]) >> 31;
				int v = (FFT_w[j] * 1ll * a[i + j + len / 2] - q * 1ll * mod) & ((1LL << 31) - 1);
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v + 2*mod;
			}
		}
	}
	if (invert) {
		int nrev = modInv(n, mod);
		for (int i = 0; i<n; ++i)
			a[i] = int(a[i] * 1ll * nrev % mod);
	}
}
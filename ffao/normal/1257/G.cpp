#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>


using namespace std;


#include <cmath>

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


struct FFT_mod {
	int mod, root, root_1, root_pw;
};

extern FFT_mod suggested_fft_mods[5];


void ntt(std::vector<int>& a, bool invert, const FFT_mod& mod_data);


#include <array>


typedef pair<int, int> pii;
typedef vector<int> vi;


#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)


map<int,int> m;
int n,p;

const int mod = 998244353;


void conv(vi& a, vi &b) {
    int x = 1;
    int len = a.size() + b.size() - 1;
    while (x < len) x <<= 1;

    a.resize(x);
    b.resize(x);
    ntt(a,false,suggested_fft_mods[3]);
    ntt(b,false,suggested_fft_mods[3]);
    
    for (int i = 0; i < x; i++) a[i] = (a[i]*1ll*b[i]) % mod;
    ntt(a,true,suggested_fft_mods[3]);
}

vector<int> vs[210000];

void solve()
{
    re(n);
    rep(i,0,n) {re(p); m[p]++;}

    vi cts;
    for (auto p: m) cts.push_back(p.second);
    sort(cts.begin(),cts.end());

    set< pii > ss;
    for (int i = 0; i < sz(cts); i++) {
        vs[i] = vi(cts[i]+1, 1);
        ss.insert({cts[i]+1, i});
    }
    
    while (ss.size() >= 2) {
        int a = ss.begin()->second;
        ss.erase(ss.begin());
        int b = ss.begin()->second;
        ss.erase(ss.begin());

        conv(vs[a],vs[b]);
        ss.insert({sz(vs[a]),a});
    }

    ps(vs[ss.begin()->second][n/2]);
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


FFT_mod suggested_fft_mods[] = {
	{ 167772161, 243, 114609789, 1 << 25 },
	{ 415236097, 73362476, 247718523, 1<<22 },
	{ 463470593, 428228038, 182429, 1<<21},
	{ 998244353, 15311432, 469870224, 1 << 23 },
	{ 918552577, 86995699, 324602258, 1 << 22 }
};

int FFT_w[1050000];
int FFT_w_dash[1050000];


void ntt(std::vector<int>& a, bool invert, const FFT_mod& mod_data) {
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
			if (uu >= mod) uu -= mod;
			a[i] = uu + vv < mod ? uu + vv : uu + vv - mod;
			a[i + len / 2] = uu - vv >= 0 ? uu - vv : uu - vv + mod;

			for (int j = 1; j<len / 2; ++j) {
				int u = a[i + j];
				if (u >= mod) u -= mod;
				int q = (FFT_w_dash[j] * 1ll * a[i + j + len / 2]) >> 31;
				int v = (FFT_w[j] * 1ll * a[i + j + len / 2] - q * 1ll * mod) & ((1LL<<31)-1);
				if (v >= mod) v -= mod;
				a[i + j] = u + v < mod ? u + v : u + v - mod;
				a[i + j + len / 2] = u - v + mod;
			}
		}
	}
	if (invert) {
		int nrev = modInv(n, mod);
		for (int i = 0; i<n; ++i)
			a[i] = int(a[i] * 1ll * nrev % mod);
	}
}
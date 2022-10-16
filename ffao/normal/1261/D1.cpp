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


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);
template<class T> void re(std::vector<T>& a);


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


struct FFT_mod {
	int mod, root, root_1, root_pw;
};

extern FFT_mod suggested_fft_mods[5];


void ntt(std::vector<int>& a, bool invert, const FFT_mod& mod_data);


vector<int> poly(524288, 0);
vector<int> res(524288, 1);

const int mod = 998244353;
int n,k;

const FFT_mod md = suggested_fft_mods[3];
vector<int> a;

void solve()
{
    re(n,k);
    a.resize(n);
    re(a);

	if (k == 1) {
		printf("0\n");
		return;
	}

    poly[0] = 1;
    poly[1] = k-2;
    poly[2] = 1;
    ntt(poly, false, md);

    int whatever = 1;
    int pot = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == a[ (i+1)%n ]) {
            whatever = (whatever * 1ll * k) % mod;
        }
        else {
            pot++;
        }
    }

	//printf("wh %d pot %d\n", whatever, pot);
    int op = pot;
    while (pot) {
        if (pot & 1) {
            for (int i = 0; i < 524288; i++) res[i] = (res[i] * 1ll * poly[i]) % mod;
        }

        for (int i = 0; i < 524288; i++) poly[i] = (poly[i] * 1ll * poly[i]) % mod;
        pot >>= 1;
    }

    ntt(res, true, md);

    int ans = 0;
    for (int i = 0; i < op; i++) {
		//printf("res %d = %d\n", i, res[i]);
        ans = (ans + res[i]) % mod;
    }
    ans = (ans * 1ll * whatever) % mod;
    printf("%d\n", ans);
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
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


FFT_mod suggested_fft_mods[] = {
	{ 7340033, 5, 4404020, 1 << 20 },
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


/*#include "AhoCorasick.h"

ACnode AhoCorasick::data[2100000];
int AhoCorasick::d_cnt;

ACnode* AhoCorasick::new_node(){
	data[d_cnt].reset();
	return &data[d_cnt++];
}

AhoCorasick::AhoCorasick() {
	reset();
}

void AhoCorasick::reset() {
	d_cnt = 0;
	string_cnt = 0;
	root = new_node();
}

void AhoCorasick::add_string(char* s) {
	ACnode *p = root;
	char c;
	for (int j = 0; (c = s[j]) != '\0'; j++){
		ACnode *it = p->son(c);
		if (it == NULL){
			p->add(c, it = new_node());
		}
		p = it;
	}
	p->o = string_cnt++;
}

void AhoCorasick::compute_fail() {
	std::queue<ACnode*> q;
	for (ACnode *it = root->p; it != NULL; it = it->l){
		q.push(it);
		it->f = root;
	}
	while (!q.empty()){ //calcula os fail
		ACnode *p = q.front();
		q.pop();
		for (ACnode *it = p->p; it != NULL; it = it->l){
			q.push(it);
			ACnode *jt, *kt;
			for (jt = p->f; (kt = jt->son(it -> c)) == NULL; jt = jt->f){
				if (jt == root){
					kt = root;
					break;
				}
			}
			it->f = kt;
			if (it->o == -1){
				it->o = kt->o;
			}
		}
	}
}*/
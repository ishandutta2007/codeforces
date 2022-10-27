#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const int mod = 998244353;
const int root = 15311432;
const int rooti = 469870224;
const int rootpw = 1 << 23;

int f[maxn], fac[maxn], ifac[maxn], inv[maxn];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int inverse(int n){
	if(n < maxn)return inv[n];
	return 1LL*(mod - mod/n)*inverse(mod%n)%mod;
}

inline void fft(vector<int> &a, bool inv){
	int n = (int)a.size();
	for(int i = 1, j = 0; i < n; i++){
		int bit = n >> 1;
		while(j & bit){
			j ^= bit;
			bit >>= 1;
		}
		j ^= bit;
		if(i < j)swap(a[i], a[j]);
	}
	for(int len = 2; len <= n; len <<= 1){
		int hen = len >> 1;
		int mul = inv?rooti:root;
		for(int i = len; i < rootpw; i <<= 1){
			mul = 1LL*mul*mul%mod;
		}
		for(int i = 0; i < n; i += len){
			int prd = 1;
			for(int j = 0; j < hen; j++){
				int u = a[i + j];
				int v = 1LL*prd*a[i + j + hen]%mod;
				a[i + j] = u + v;
				a[i + j + hen] = u + mod - v;
				prd = 1LL*prd*mul%mod;
			}
		}
		for(int i = 0; i < n; i++){
			if(a[i] >= mod)a[i] -= mod;
		}
	}
	if(inv){
		int invn = inverse(n);
		for(auto &x : a){
			x = 1LL*x*invn%mod;
		}
	}
}

inline vector<int> multiply(vector<int> a, vector<int> b){
	int n = 1;
	while(n < a.size() + b.size())n <<= 1;
	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);
	for(int i = 0; i < n; i++){
		a[i] = 1LL*a[i]*b[i]%mod;
	}
	fft(a, true);
	return a;
}

void init(){
	fac[0] = ifac[0] = 1;
	fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2; i < maxn; i++){
		fac[i] = 1LL*i*fac[i - 1]%mod;
		inv[i] = 1LL*inv[mod%i]*(mod - mod/i)%mod;
		ifac[i] = 1LL*ifac[i - 1]*inv[i]%mod;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int n; cin >> n;
	int r = (n - 1) >> 1;

	f[0] = 1;
	int sum = 1;
	for(int i = 1; i <= n; i++){
		f[i] = 1LL*fac[i - 1]*sum%mod;
		add(sum, 1LL*f[i]*ifac[i]%mod);
		if(i >= r){
			add(sum, mod - 1LL*f[i - r]*ifac[i - r]%mod);
		}
	}
	vector<int> a(n);
	vector<int> b(n);
	for(int k = 0; k <= r; k++){
		b[k] = ifac[k];
		if(k)a[n - 1 - k] = (1LL*f[n - 1 - k]*ifac[n - 1 - k]%mod)*fac[k - 1]%mod;
	}
	vector<int> c = multiply(a, b);
	
	cout << f[n - 1] << " ";
	for(int i = 2; i <= n; i++){
		cout << (1LL*c[n - i]*(i - 1)%mod)*fac[n - i]%mod << ' ';
	}
	cout << '\n';

	return 0;
}
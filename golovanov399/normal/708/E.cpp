#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

long long pw(long long a, long long b){
	long long res = 1;
	while (b){
		if (b & 1ll)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv(long long x){
	return pw(x % mod, mod - 2);
}

vector<long long> mult(const vector<long long>& a, const vector<long long>& b){
	vector<long long> res;
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < b.size(); j++){
			if (i + j >= res.size())
				res.push_back(0);
			res[i + j] += a[i] * b[j] % mod;
		}
	}
	for (auto& x : res)
		x %= mod;
	return res;
}

vector<long long> poly_pw(vector<long long> a, int k, int m){
	vector<long long> res(1, 1);
	while (k){
		if (k & 1){
			res = mult(res, a);
			if (res.size() > m)
				res.resize(m);
		}
		k >>= 1;
		a = mult(a, a);
		if (a.size() > m)
			a.resize(m);
	}
	return res;
}

void out(long long r){
	for (int i = 1; i < 100; i++){
		for (int j = 0; j <= i; j++){
			if (1ll * inv(i) * j % mod == r){
				cerr << j << "/" << i << "\n";
				return;
			}
		}
	}
	cerr << "nan\n";
}

int main(){

	int n = nxt(), m = nxt();
	long long p = nxt();
	p = p * inv(nxt()) % mod;
	long long q = (mod + 1 - p) % mod;
	while (q < 0)
		q += mod;

	vector<long long> gen(1, q);
	gen.push_back(p);

	int k = nxt();
	gen = poly_pw(gen, k, m);

	vector<long long> S(m + 1);
	S[0] = gen[0];
	for (int i = 1; i <= m; i++){
		if (i < gen.size())
			S[i] = S[i - 1] + gen[i];
		else
			S[i] = S[i - 1];
		if (S[i] >= mod)
			S[i] -= mod;
	}

	vector<long long> xui(m);
	vector<long long> c(m);
	vector<long long> pre(m);
	gen.resize(m, 0);

	for (int i = 0; i < m; i++)
		xui[i] = gen[i] * S[m - i - 1] % mod;
	for (int i = 0; i < m; i++)
		c[i] = S[i] * S[m - 1 - i] % mod;
	pre[0] = xui[0];
	for (int i = 1; i < m; i++)
		pre[i] = (pre[i - 1] + xui[i]) % mod;

	for (int _ = 1; _ < n; _++){
		vector<long long> _x(m);
		vector<long long> _c(m);
		vector<long long> zlp(m);
		zlp[m - 1] = 0;//S[0] * xui[m - 1] % mod;
		for (int i = m - 2; i >= 0; i--){
			zlp[i] = zlp[i + 1] + S[m - i - 2] * xui[i + 1] % mod;
			if (zlp[i] >= mod)
				zlp[i] -= mod;
		}

		for (int i = 0; i < m; i++){
			_x[i] = c[i] * gen[i] % mod * S[m - i - 1] % mod;
			_x[i] += gen[i] * zlp[i] % mod;
			if (_x[i] >= mod)
				_x[i] -= mod;
		}

		vector<long long> _p(m);
		_p[0] = _x[0];
		for (int i = 1; i < m; i++){
			_p[i] = _p[i - 1] + _x[i];
			if (_p[i] >= mod)
				_p[i] -= mod;
		}
		for (int i = 0; i < m; i++){
			_c[i] = _p[i] - _p[m - 1] + _p[m - i - 1];
			while (_c[i] < 0)
				_c[i] += mod;
			while (_c[i] >= mod)
				_c[i] -= mod;
		}

		_p.swap(pre);
		_x.swap(xui);
		_c.swap(c);
	}

	// out(pre[m - 1] % mod);
	cout << pre[m - 1] % mod << "\n";

	return 0;
}
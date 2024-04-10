#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

void otp(vi a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}

namespace MTT {
	const int maxn = 263000;
	#define ld long double
	struct cpl
	{
		ld r, i;
		cpl(){r = i = 0;}
		cpl(ld a, ld b){r = a, i = b;}
		cpl operator + (cpl a){return cpl(r + a.r, i + a.i);}
		cpl operator - (cpl a){return cpl(r - a.r, i - a.i);}
		cpl operator * (cpl a){return cpl(r * a.r - i * a.i, r * a.i + i * a.r);}
	}x[maxn]; 
	int r[maxn], l;
	const ld pi = acos(-1.0);
	int qmod = 35000;
	void FFT(cpl *a, int tp)
	{
		for(int i = 0; i < l; i++) x[r[i]] = a[i];
		for(int i = 0; i < l; i++) a[i] = x[i];
		for(int i = 1; i < l; i <<= 1)
		{
			cpl w = cpl(cos(pi / i), tp * sin(pi / i));
			for(int j = 0; j < l; j += (i << 1))
			{
				cpl wn = cpl(1, 0);
				for(int k = 0; k < i; k++)
				{
					cpl t = a[i + j + k] * wn;
					a[i + j + k] = a[j + k] - t, 
					a[j + k] = a[j + k] + t;
					wn = wn * w;
				}
			}
		}
	}
	int a[maxn], b[maxn];
	cpl a1[maxn], a2[maxn], b1[maxn], b2[maxn], c1[maxn], c2[maxn], c3[maxn];
	
	ll ret[maxn];
	void mult()
	{	
		r[0] = 0;
		for(int i = 1; i < l; i <<= 1)
			for(int k = 0; k < i; k++)
				r[i + k] = r[k] + l / i / 2;
		for(int i = 0; i < l; i++)	
			a1[i] = cpl(a[i] / qmod, 0), 
			a2[i] = cpl(a[i] % qmod, 0), 
			b1[i] = cpl(b[i] / qmod, 0), 
			b2[i] = cpl(b[i] % qmod, 0); 
	
		FFT(a1, 1), 
		FFT(a2, 1), 
		FFT(b1, 1), 
		FFT(b2, 1);
	
		for(int i = 0; i < l; i++)
			c1[i] = a1[i] * b1[i], 
			c2[i] = a1[i] * b2[i] + a2[i] * b1[i], 
			c3[i] = a2[i] * b2[i];
		FFT(c1, -1), FFT(c2, -1), 
		FFT(c3, -1);
		for(int i = 0; i < l; i++)
			ret[i] = (ll)(c1[i].r / l + 0.5) % mod * qmod * qmod % mod + 
					 (ll)(c2[i].r / l + 0.5) % mod * qmod % mod + 
					 (ll)(c3[i].r / l + 0.5);
	}
	vi mul(vi x, vi y) {
		l = 1;
		while(l <= x.size() + y.size()) l <<= 1;
		for (int j = 0; j < l; j++) a[j] = 0, b[j] = 0, ret[j] = 0;
		for (int j = 0; j < x.size(); j++)
			a[j] = x[j];
		for (int j = 0; j < y.size(); j++)
			b[j] = y[j];
	//	otp(x), otp(y);
		mult();
		vi fn(l);
		for (int i = 0; i < l; i++)
			fn[i] = ret[i] % mod;
	//	otp(fn);
		return fn;
	}
};

ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
const int maxn = 60005;
ll n;
ll jc[maxn], bjc[maxn];
int k; 
vi pw[20];
vi cur;
vi cal(vi a, vi b, int u2) {
	ll pw = ksm(2, u2);
	ll cur = 1;
	for (int i = 0; i <= k; i++) {
		a[i] = 1ll * a[i] * cur % mod;
		cur = cur * pw % mod;
	}
	for (int i = 0; i <= k; i++)	
		a[i] = a[i] * bjc[i] % mod, 
		b[i] = b[i] * bjc[i] % mod;
	vi c = MTT::mul(a, b);
	for (int i = 0; i <= k; i++)
		c[i] = c[i] * jc[i] % mod;
	c.resize(k + 1);
	return c;
} 
int main() {
	cin >> n >> k;
	if (n > k) {
		cout << 0 << endl;
		return 0;
	}
	jc[0] = 1, bjc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
	vi cur(k + 1);
	cur[0] = 1; 
	for (int j = 0; j < 20; j++) {
		if (j == 0) {
			pw[j].resize(k + 1);
			for (int m = 0; m <= k; m++) {
				pw[j][m] = ksm(1, m);
				pw[j][m] -= ksm(0, m);
			}
		} 
		else {
			pw[j] = cal(pw[j - 1], pw[j - 1], (1 << (j - 1)));
		}
	} 
//	otp(cur);
	int bs = 0;
	for (int j = 0; j < 20; j++)
		if (n & (1 << j))
			cur = cal(cur, pw[j], (1 << j));
		//	cout << j << endl, 
		//	otp(pw[j]), 
		//	otp(cur);
	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		ll s = jc[k] * bjc[i] % mod * bjc[k - i] % mod;
		s = s * cur[i] % mod;
		ans = (ans + s) % mod;
	} 
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}
/*
CHHOCH
*/
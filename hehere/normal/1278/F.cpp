#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const LL P = 998244353;
const int maxK = 5000 + 5;
LL qpow(LL a, LL b) {
	LL r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P; b >>= 1;
	}
	return r;
}
LL n, m;
int k;
LL fac[maxK], ifac[maxK];
LL C(int n, int k) {
	if(k < 0 || k > n) return 0;
	else return fac[n] * ifac[k] % P * ifac[n - k] % P;
}
LL falling(LL n, int k) {
	LL r = 1;
	while(k--) r = r * n % P, n--;
	return r;
}
LL S[2][maxK];


int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m >> k;
	LL im = qpow(m, P - 2); 
	LL im1 = qpow(m - 1, P - 2); // if m == 1?
	
	if(m == 1) {
		cout << qpow(n, k) << endl;
		return 0;
	}
	
	fac[0] = 1;
	for(int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i % P;
	ifac[k] = qpow(fac[k], P - 2);
	for(int i = k - 1; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % P;
	
	memset(S, 0, sizeof(S));
	{
		for(int n = 1; n <= k; ++n) {
			S[n & 1][1] = 1;
			for(int i = 2; i <= n; ++i) {
				S[n & 1][i] = (S[(n - 1) & 1][i - 1] + S[(n - 1) & 1][i] * i) % P;
			}
		}
	}
	
//	displaya(S[k & 1], 1, k);
	LL ans = 0;
	LL falling = 1;
	for(int j = 1; j <= k && j <= n; ++j) {
//		display(j);
//		display(falling);
//		display(S[k & 1][j]);
//		display(qpow(m,  j));
//		display(qpow(m + 1, n - j));
		falling = falling * (n - j + 1) % P;
		(ans += S[k & 1][j] * falling % P * qpow(1 - im, n) % P * qpow(im1, j) % P * qpow(im1 + 1, n - j)) %= P;
	}
	cout << ((ans % P + P) % P) << endl;
	return 0;
}
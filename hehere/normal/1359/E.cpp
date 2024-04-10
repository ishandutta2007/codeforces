#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << (x) << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << ((a)[qwq]);\
		else cerr << ", " << ((a)[qwq]);\
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
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

const LL P = 998244353;
const int maxN = 500000 + 5;
LL qpow(LL a, LL b) {
	LL r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P; b >>= 1;
	}
	return r;
}
int n, k;
LL fac[maxN], ifac[maxN];
LL C(int n, int k) {
	if(k < 0 || k > n) return 0;
	return fac[n] * ifac[k] % P * ifac[n - k] % P;
}

int main() {
	cin >> n >> k;
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % P;
	ifac[n] = qpow(fac[n], P - 2);
	for(int i = n - 1; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % P;
	
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += C(n / i - 1, k - 1);
		ans %= P;
	}
	cout << ans << endl;
	return 0;
}
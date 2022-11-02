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
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

template<const int P = 998244353, const int g = 3, int maxN = (1 << 20)>
struct FNT {
	int n;
	int rev[maxN];
	int p[maxN], ip[maxN];

	FNT() : n(0) {}

	LL qpow(LL a, LL b) {
		LL r = 1;
		while(b) {
			if(b & 1) (r *= a) %= P;
			(a *= a) %= P; b >>= 1;
		}
		return r;
	}

	void prepare(int n) {
		this->n = n;
		assert((n & (n - 1)) == 0);
		int width = 0;
		while((1 << width) < n) ++width;
		rev[0] = 0;
		for(int i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (width - 1);
		p[0] = 1; p[1] = qpow(g, (P - 1) / n);
		ip[0] = 1; ip[1] = qpow(p[1], P - 2);
		for(int i = 2; i < n; ++i) p[i] = (LL)p[i - 1] * p[1] % P, ip[i] = (LL)ip[i - 1] * ip[1] % P;
	}
	
	void transform(vector<int> &a, int flag) {
		int n = a.size();
		if(this->n != n) prepare(n);
		assert(flag == 1 || flag == -1);
		for(int i = 0; i < n; ++i) if(rev[i] < i) std::swap(a[i], a[rev[i]]);
		for(int i = 1; i < n; i <<= 1) {
			int step = n / (i << 1);
			for(int j = 0; j < n; j += (i << 1)) {
				int *w = flag == 1 ? p : ip;
				for(int k = 0; k < i; ++k, w += step) {
					int x = a[j + k], y = (LL)a[j + k + i] * *w % P;
					a[j + k] = x + y >= P ? x + y - P : x + y;
					a[j + k + i] = x - y < 0 ? x - y + P : x - y;
				}
			}
		}
		if(flag == -1) {
			LL in = qpow(n, P - 2);
			for(int i = 0; i < n; ++i) a[i] = a[i] * in % P;
		}
	}

};

template<const LL P>
LL qpow(LL a, LL b) {
	LL r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P; b >>= 1;
	}
	return r;
}

const LL P1 = 998244353, P2 = 1004535809;
const LL I1 = qpow<P2>(P1, P2 - 2), I2 = qpow<P1>(P2, P1 - 2);
FNT<P1, 3, 1 << 20> f1;
FNT<P2, 3, 1 << 20> f2;
LL mul(LL x, LL y, LL M)
{
	using ULL = unsigned long long;
	LL a = (ULL)x * (ULL)y, b = (ULL)((long double)x / M * y) * (ULL)M;
	if(a - b < (1ull << 63)) return (a - b) % M;
	else return (M - (b - a) % M) % M;
	// return a - b;

	// unsigned long long x = (ULL)
	// return (unsigned long long)
	
    // long long t=((long double)x)*y/mod;
    // long long s=x*y-t*mod;
    // s=(s%mod+mod)%mod;
    // return s;
}

const int P = 490019;
const int maxN = (1 << 20) + 5;
int n, m, a[maxN], b[maxN], c, f[maxN], g[maxN];
LL p[maxN];

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	// cin >> n >> m >> c;
    scanf("%d %d %d", &n, &m, &c);
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	for(int i = 0; i < m; ++i) scanf("%d", b + i);

    p[0] = 1;
    for(int i = 1; i < (1 << 20); ++i) p[i] = p[i - 1] * c % P;

	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	for(int i = 0; i < n; ++i) (f[(LL)i * i % (P - 1)] += a[i]) %= P;
	for(int i = 0; i < m; ++i) (g[(LL)i * i * i % (P - 1)] += b[i]) %= P;
	// sum f[i]*g[j]*c^(i*j)
	for(int i = 0; i < P; ++i) f[i] = f[i] * p[P - 1 - (LL)i * (i + 1) / 2 % (P - 1)] % P;
	for(int i = 0; i < P; ++i) g[i] = g[i] * p[P - 1 - (LL)i * (i + 1) / 2 % (P - 1)] % P;

	vector<int> a, b;
	a.assign(f, f + (1 << 20));
	b.assign(g, g + (1 << 20));
	f1.transform(a, 1);
	f1.transform(b, 1);
	vector<int> c1(1 << 20);
	for(int i = 0; i < (1 << 20); ++i) c1[i] = (LL)a[i] * b[i] % P1;
	f1.transform(c1, -1);
	a.assign(f, f + (1 << 20));
	b.assign(g, g + (1 << 20));
	f2.transform(a, 1);
	f2.transform(b, 1);
	vector<int> c2(1 << 20);
	for(int i = 0; i < (1 << 20); ++i) c2[i] = (LL)a[i] * b[i] % P2;
	f2.transform(c2, -1);

	vector<int> r(1 << 20);
	for(int i = 0; i < (1 << 20); ++i) r[i] = (mul(c1[i], I2 * P2, P1 * P2) + mul(c2[i], I1 * P1, P1 * P2)) % (P1 * P2) % P;
	LL ans = 0;
	for(int i = 0; i < (1 << 20); ++i) (ans += (LL)r[i] * p[(LL)i * (i + 1) / 2 % (P - 1)]) %= P;
	cout << ans << endl;
	return 0;
}
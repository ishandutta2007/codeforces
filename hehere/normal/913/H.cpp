#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) {}
#define eprintf(...) do {} while(0)
#endif

template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template<typename T>
ostream& operator << (ostream& out, const vector<T> &v) {
	int n = v.size();
	out << "{";
	for(int i = 0; i < n; ++i) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "}";
}
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &v) {
	return out << "(" << v.first << ", " << v.second << ")";
}

typedef long long LL;
const int P = 998244353;
LL qpow(LL a, LL b) {
	LL r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P; b >>= 1;
	}
	return r;
}
const int e6 = 1000000;
const int ie6 = qpow(e6, P - 2);
const int maxN = 30 + 5;

int n;
vector<int> lim;
vector<LL> fac, ifac;
void prepare(int n) {
	fac.resize(n);
	ifac.resize(n);
	fac[0] = 1;
	for(int i = 1; i < n; ++i) fac[i] = fac[i - 1] * i % P;
	ifac[n - 1] = qpow(fac[n - 1], P - 2);
	for(int i = n - 2; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % P;
}
LL C(int n, int k) {
	if(k < 0 || k > n) return 0;
	assert(n < (int)fac.size());
	return fac[n] * ifac[k] % P * ifac[n - k] % P;
}

void reduce(vector<int> &f) {
	while(f.size() && f.back() == 0) f.pop_back();
}
vector<int> integrate(vector<int> f) {
	int n = f.size();
	vector<int> r(n + 1);
	r[0] = 0;
	for(int i = 1; i < n + 1; ++i) r[i] = f[i - 1] * ifac[i] % P * fac[i - 1] % P;
	return r;
}
vector<int> operator + (vector<int> f, vector<int> g) {
	vector<int> p(max(f.size(), g.size()), 0);
	for(size_t i = 0; i < f.size(); ++i) p[i] = f[i];
	for(size_t i = 0; i < g.size(); ++i) p[i] = (p[i] + g[i]) % P;
	reduce(p);
	return p;
}
vector<int> operator - (vector<int> g) {
	vector<int> r = g;
	for(size_t i = 0; i < r.size(); ++i) r[i] = (P - r[i]) % P;
	return r;
}
vector<int> operator - (vector<int> f, vector<int> g) {
	return f + (-g);
}
vector<int> operator * (vector<int> f, vector<int> g) {
	int n = f.size(), m = g.size();
	vector<int> r(n + m - 1, 0);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			r[i + j] = (r[i + j] + (LL)f[i] * g[j]) % P;
	reduce(r);
	return r;
}
int eval(vector<int> f, int x) {
	int r = 0;
	for(int i = (int)f.size() - 1; i >= 0; --i) {
		r = ((LL)r * x + f[i]) % P;
	}
	return r;
}
vector<int> compose(vector<int> f, vector<int> g) { // f(g(x))
	vector<int> r;
	for(int i = (int)f.size() - 1; i >= 0; --i) {
		r = r * g + vector<int>(1, f[i]);
	}
	return r;
}

void roll(vector<int> &p, vector< vector<int> > &g, int lim) {
	vector<int> q = p;
	for(auto x : p) q.push_back(x + e6);
	sort(q.begin(), q.end());
	q.erase(unique(q.begin(), q.end()), q.end());

	if(lim <= q.back()) {
		while(q.back() >= lim) q.pop_back();
		q.push_back(lim);
	}
	
	vector<int> precomp;
	for(int j = 0; j + 1 < (int)p.size(); ++j) {
		auto poly = integrate(g[j]);
		LL re = eval(poly, (LL)p[j + 1] * ie6 % P) - eval(poly, (LL)p[j] * ie6 % P) + P;
		re = re % P;
		precomp.push_back(re);
	}

	vector< vector<int> > f;
	for(int i = 0; i + 1 < (int)q.size(); ++i) {
		vector<int> re;
		for(int j = 0; j + 1 < (int)p.size(); ++j) {
			// eprintf("(%d, %d) -> (%d, %d)\n", q[i], q[i + 1], p[j], p[j + 1]);
			if(q[i] - e6 < p[j + 1] && q[i + 1] > p[j]) {
				// eprintf("ok\n");
				assert(q[i + 1] - e6 <= p[j + 1]);
				assert(q[i] >= p[j]);
				if(q[i] >= p[j + 1] && q[i + 1] - e6 <= p[j])
					re = re + vector<int>(1, precomp[j]);
				else {
					auto poly = integrate(g[j]);
					vector<int> now;
					if(q[i] >= p[j + 1]) now = now + compose(poly, {(int)((LL)p[j + 1] * ie6 % P)});
					else now = now + compose(poly, {0, 1});
					if(q[i + 1] - e6 <= p[j]) now = now - compose(poly, {(int)((LL)p[j] * ie6 % P)});
					else now = now - compose(poly, {-1, 1});
					// display(now);
					re = re + now;
				}
			}
		}
		f.push_back(re);
	}

	p = q;
	g = f;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i) {
		double x; cin >> x;
		lim.push_back((int)(x * 1e6 + 0.5));
	}
	for(int i = n - 2; i >= 0; --i) chmin(lim[i], lim[i + 1]);
	display(lim);
	prepare(n + 5);
	vector<int> crit = {0, min(e6, lim[0])};
	vector< vector<int> > polys = {{1}};
	for(int i = 1; i < n; ++i) {
		roll(crit, polys, lim[i]);
		for(auto &p : polys) assert((int)p.size() <= n + 3);
		display(crit);
		display(polys);
	}
	int ans = 0;
	for(int i = 0; i + 1 < (int)crit.size(); ++i) {
		auto f = integrate(polys[i]);
		int seg = eval(f, (LL)crit[i + 1] * ie6 % P) - eval(f, (LL)crit[i] * ie6 % P);
		ans = (ans + seg % P) % P;
		assert((int)polys[i].size() <= n + 3);
	}
	cout << ((ans + P) % P) << endl;
	return 0;
}
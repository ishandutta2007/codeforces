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

LL fac[21];
LL C(int n, int k) {
	if(k < 0 || k > n) return 0;
	return fac[n] / fac[k] / fac[n - k];
}

LL solve() {
	LL n;
	cin >> n;
	map<int, int> f;
	int m = 0;
	for(int i = 2; n; ++i) {
		f[n % i]++;
		n /= i;
		m = i;
	}
	auto count = [&]() {
		LL ans = 1;
		int total = m;
		for(auto i = f.rbegin(); i != f.rend(); ++i) {
//			eprintf("%d %d\n", i->first, i->second);
			int c = total - max(i->first, 1);
//			eprintf("%d chooses %d\n", c, i->second);
			ans *= C(c, i->second);
			total -= i->second;
		}
		return ans;
	};
	LL ans = count();
	if(f.count(0)) f[0]--, m--, ans -= count();
	return ans - 1;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	fac[0] = 1;
	for(int i = 1; i <= 20; ++i) fac[i] = fac[i - 1] * i;
	int T; cin >> T;
	while(T--) {
		cout << solve() << '\n';
	}
	return 0;
}
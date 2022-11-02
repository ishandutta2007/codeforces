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

int main() {
	ios::sync_with_stdio(false);
	vector<pii> vp;
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		vp.emplace_back(x + ta, 0);
	}
	for(int i = 1; i <= m; ++i) {
		int x; cin >> x;
		vp.emplace_back(x, 1);
	}
	sort(vp.begin(), vp.end());
	vector<int> af(n + m), bf(n + m);
	if(vp[0].second == 0) {
		af[0] = 0;
		bf[0] = 1;
	} else {
		af[0] = bf[0] = 0;
	}
	int ans = -1;
	for(int i = 1; i < n + m; ++i) {
		if(vp[i].second == 0) {
			af[i] = af[i - 1];
			chmin(af[i], bf[i - 1]);
			bf[i] = bf[i - 1] + 1;
		} else {
			af[i] = af[i - 1] + 1;
			chmin(af[i], bf[i - 1]);
			bf[i] = bf[i - 1];
			if(af[i - 1] <= k || bf[i - 1] <= k)
				ans = vp[i].first + tb;
		}
	}
//	displayv(af);
//	displayv(bf);
	if(af.back() <= k) ans = -1;
	cout << ans << endl;
	return 0;
}
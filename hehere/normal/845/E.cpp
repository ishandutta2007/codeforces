#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
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

const int maxK = 500 + 5;
int n, m, k;
LL px[maxK], py[maxK];

LL solve(LL th) {
	vector<LL> vi;
	vi.push_back(1);
	vi.push_back(n + 1);
	for(int i = 1; i <= k; ++i) vi.push_back(px[i] - th);
	for(int i = 1; i <= k; ++i) vi.push_back(px[i] + th + 1);
	sort(vi.begin(), vi.end());
	vi.erase(unique(vi.begin(), vi.end()), vi.end());
	while(vi.size() && vi.back() > n + 1) vi.pop_back();
	reverse(vi.begin(), vi.end());
	while(vi.size() && vi.back() < 1) vi.pop_back();
	reverse(vi.begin(), vi.end());
	vector< vector<LL> > y(vi.size());
	int sz = vi.size() - 1;
	for(int i = 1; i <= k; ++i) {
		LL l = px[i] - th, r = px[i] + th + 1;
		for(int j = 0; j < sz; ++j) {
			if(l <= vi[j] && vi[j + 1] <= r) {
				y[j].push_back(py[i] - th);
			}
		}
	}
	LL x1 = 2e9, x2 = -2e9, y1 = 2e9, y2 = -2e9;
	for(int j = 0; j < sz; ++j) {
		y[j].push_back(m + 1);
		sort(y[j].begin(), y[j].end());
		y[j].erase(unique(y[j].begin(), y[j].end()), y[j].end());
		LL base = 1;
		for(auto t : y[j]) {
			if(t > base) {
				chmin(y1, base);
				chmax(y2, t - 1);
				chmin(x1, vi[j]);
				chmax(x2, vi[j + 1] - 1);
			}
			base = t + 2 * th + 1;
		}
		eprintf("[%lld, %lld)\n", vi[j], vi[j + 1]);
		displayv(y[j]);
	}
	if(x1 == (LL)2e9) return 0;
	return (max(x2 - x1, y2 - y1) + 1) / 2;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i) cin >> px[i] >> py[i];
	LL L = 0, R = max(n, m);
	LL ans = max(n, m);
	display(solve(0));
	while(L < R) {
		LL M = (L + R) >> 1;
//		display(M);
		LL ms = solve(M);
		eprintf("solve(%lld) = %lld\n", M, ms);
		chmin(ans, max(ms, M));
		if(M < ms) L = M + 1;
		else R = M;
	}
	cout << ans << endl;
	return 0;
}
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

const int maxN = 400000 + 5;
int n, m, a[maxN];
int qp[maxN], qv[maxN];
vector<int> qs[maxN];

struct MaxTree {
	int n, C[maxN * 2];
	void init(int n) {
		this->n = n;
		memset(C, 0, sizeof(C));
	}
	void update(int p, int x) {
		for(; p <= n; p += p & -p) chmax(C[p], x);
	}
	int query(int p) {
		int r = 0;
		for(; p > 0; p -= p & -p) chmax(r, C[p]);
		return r;
	}
} tree;
int f[maxN], g[maxN];
int tl[maxN], tr[maxN];
int cnt[maxN];

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> qp[i] >> qv[i], qs[qp[i]].push_back(i);
	vector<int> t(a + 1, a + n + 1);
	t.insert(t.end(), qv + 1, qv + m + 1);
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin() + 1;
	for(int i = 1; i <= m; ++i) qv[i] = lower_bound(t.begin(), t.end(), qv[i]) - t.begin() + 1;
	
	tree.init(t.size());
	for(int i = 1; i <= n; ++i) {
		f[i] = 1 + tree.query(a[i] - 1);
		for(int j : qs[i]) tl[j] = tree.query(qv[j] - 1) + 1;
		tree.update(a[i], f[i]);
	}
	tree.init(t.size());
	for(int i = n; i >= 1; --i) {
		g[i] = 1 + tree.query(t.size() + 1 - a[i] - 1);
		for(int j : qs[i]) tr[j] = tree.query(t.size() + 1 - qv[j] - 1) + 1;
		tree.update(t.size() + 1 - a[i], g[i]);
	}
//	displaya(f, 1, n);
//	displaya(g, 1, n);
	int lis = 0;
	for(int i = 1; i <= n; ++i) chmax(lis, f[i] + g[i] - 1);
	display(lis);
//	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; ++i) if(f[i] + g[i] - 1 == lis) cnt[f[i]]++;
	for(int i = 1; i <= m; ++i) {
		int ans = lis - 1;
		if(cnt[f[qp[i]]] - (f[qp[i]] + g[qp[i]] - 1 == lis) >= 1) ans = lis;
		chmax(ans, tl[i] + tr[i] - 1);
		cout << ans << '\n';
	}
	return 0;
}
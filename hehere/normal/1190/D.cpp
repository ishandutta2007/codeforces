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

const int maxN = 200000 + 233;
int n, x[maxN], y[maxN];
vector<int> py[maxN];
LL up[maxN];

LL C[maxN];
void add(int p, LL x) {
	for(; p <= n; p += p & -p) C[p] += x;
}
LL sum(int p) {
	LL r = 0;
	for(; p > 0; p -= p & -p) r += C[p];
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	vector<int> t;
	t.assign(x + 1, x + n + 1);
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for(int i = 1; i <= n; ++i) {
		x[i] = lower_bound(t.begin(), t.end(), x[i]) - t.begin() + 1;
	}
	t.assign(y + 1, y + n + 1);
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for(int i = 1; i <= n; ++i) {
		y[i] = lower_bound(t.begin(), t.end(), y[i]) - t.begin() + 1;
	}
	vector<int> p;
	for(int i = 1; i <= n; ++i) p.push_back(i);
	sort(p.begin(), p.end(), [&](int a, int b) {
		return y[a] != y[b] ? y[a] > y[b] : x[a] > x[b];
	});
	memset(C, 0, sizeof(C));
	for(int i : p) {
		if(sum(x[i]) - sum(x[i] - 1) == 0) add(x[i], 1);
		up[i] = sum(n) - sum(x[i] - 1);
	}
	displaya(up, 1, n);
	for(int i = 1; i <= n; ++i) py[y[i]].push_back(i);
	memset(C, 0, sizeof(C));
	for(int i = 1; i <= n; ++i) {
		sort(py[i].begin(), py[i].end(), [&](int a, int b) {
			return x[a] > x[b];
		});
		if(py[i].size()) add(i, up[py[i].back()]);
	}
	sort(p.begin(), p.end(), [&](int a, int b) {
		return x[a] != x[b] ? x[a] < x[b] : y[a] > y[b];
	});
	LL ans = 0;
	for(int l = 0; l < (int)p.size(); ++l) {
		int r = l;
		for(; r < (int)p.size() && x[p[l]] == x[p[r]]; ++r);
		--r;
//		for(int k = l; k <= r; ++k) cout << p[k] << " ";
//		cout << endl;
		ans += sum(y[p[l]]);
//		cerr << sum(y[p[l]]) << endl;
		for(int k = l; k <= r; ++k) {
//			display(up[p[k]]);
			add(y[p[k]], -up[p[k]]);
			py[y[p[k]]].pop_back();
			if(py[y[p[k]]].size()) add(y[p[k]], up[py[y[p[k]]].back()]);
		}
		l = r;
	}
	cout << ans << endl;
	return 0;
}
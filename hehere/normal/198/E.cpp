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

const int maxN = 250000 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m[maxN], p[maxN];
LL r[maxN];
LL sx, sy, sp, sr;
LL d[maxN];
vector<int> all;

LL getd() {
	LL x, y;
	cin >> x >> y;
	return (sx - x) * (sx - x) + (sy - y) * (sy - y);
}
vector<int> v[maxN * 4];
LL mn[maxN * 4];
bool cmp(int x, int y) {
	return d[x] > d[y];
}
#define lson (o << 1)
#define rson (lson | 1)
void insert(int o, int L, int R, int p, int x) {
	if(L == R) {
		v[o].push_back(x);
		chmin(mn[o], d[x]);
	} else {
		int M = (L + R) >> 1;
		if(p <= M) insert(lson, L, M, p, x);
		else insert(rson, M + 1, R, p, x);
		mn[o] = min(mn[lson], mn[rson]);
	}
}
void dig(int o, int L, int R, LL range) {
	if(L == R) {
		while(mn[o] <= range) {
			all.push_back(v[o].back());
			v[o].pop_back();
			if(v[o].size()) mn[o] = d[v[o].back()];
			else mn[o] = INF;
		}
	} else {
		int M = (L + R) >> 1;
		if(mn[lson] <= range) dig(lson, L, M, range);
		if(mn[rson] <= range) dig(rson, M + 1, R, range);
		mn[o] = min(mn[lson], mn[rson]);
	}
}
void seek(int o, int L, int R, int ql, int qr, LL range) {
	if(ql <= L && R <= qr) {
		dig(o, L, R, range);
	} else {
		int M = (L + R) >> 1;
		if(ql <= M) seek(lson, L, M, ql, qr, range);
		if(qr > M) seek(rson, M + 1, R, ql, qr, range);
		mn[o] = min(mn[lson], mn[rson]);
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> sx >> sy >> sp >> sr >> n;
	sr = sr * sr;
	for(int i = 1; i <= n; ++i) {
		d[i] = getd();
		cin >> m[i] >> p[i] >> r[i];
		r[i] = r[i] * r[i];
	}
	vector<int> t(m + 1, m + n + 1);
	sort(t.begin(), t.end());
	for(int i = 1; i <= n; ++i)
		m[i] = lower_bound(t.begin(), t.end(), m[i]) - t.begin() + 1;
	for(int i = 1; i <= n; ++i)
		p[i] = upper_bound(t.begin(), t.end(), p[i]) - t.begin();
	p[0] = upper_bound(t.begin(), t.end(), sp) - t.begin();
	r[0] = sr;
	
	for(int i = 1; i <= n * 4; ++i) mn[i] = INF;
	for(int i = 1; i <= n; ++i) {
		insert(1, 1, n, m[i], i);
	}
	for(int i = 1; i <= n * 4; ++i) sort(v[i].begin(), v[i].end(), cmp);
	all.assign(1, 0);
	for(int i = 0; i < (int)all.size(); ++i) if(p[all[i]]) {
		seek(1, 1, n, 1, p[all[i]], r[all[i]]);
	}
	cout << ((int)all.size() - 1) << endl;
	return 0;
}
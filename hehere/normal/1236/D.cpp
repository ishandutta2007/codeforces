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

const int maxN = 100000 + 5;
int n, m;
set<int> px[maxN], py[maxN];

bool full(int x1, int x2, int y1, int y2) {
//	eprintf("%d %d %d %d is checked\n", x1, x2, y1, y2);
	for(int x = x1; x <= x2; ++x)
		for(int y = y1; y <= y2; ++y)
			if(!px[x].count(y)) return false;
	return true;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
	int c; cin >> c;
	while(c--) {
		int x, y;
		cin >> x >> y;
		px[x].insert(y);
		py[y].insert(x);
	}
	#define nos() {cout << "No" << endl;return 0;}
	int xl = 1, xr = n, yl = 1, yr = m;
	int dir = 1;
	while(xl <= xr && yl <= yr) {
//		eprintf("%d %d %d %d, dir = %d\n", xl, xr, yl, yr, dir);
		if(dir == 1) {
			auto p = px[xl].lower_bound(yl);
			if(p != px[xl].end() && *p <= yr) {
				if(!full(xl, xr, *p, yr)) nos()
				yr = *p - 1;
			}
			++xl; dir = 2;
		} else if(dir == 2) {
			auto p = py[yr].lower_bound(xl);
			if(p != py[yr].end() && *p <= xr) {
				if(!full(*p, xr, yl, yr)) nos()
				xr = *p - 1;
			}
			--yr; dir = 3;
		} else if(dir == 3) {
			auto p = px[xr].upper_bound(yr);
			if(p != px[xr].begin() && *(--p) >= yl) {
				if(!full(xl, xr, yl, *p)) nos()
				yl = *p + 1;
			}
			--xr; dir = 4;
		} else if(dir == 4) {
			auto p = py[yl].upper_bound(xr);
//			display(py[yl].size());
//			display(*(py[yl].begin()));
//			display((p == py[yl].end()));
//			display(xr);
			if(p != py[yl].begin() && *(--p) >= xl) {
				if(!full(xl, *p, yl, yr)) nos()
				xl = *p + 1;
			}
			++yl; dir = 1;
		} else {
			assert(false);
		}
	}
	cout << "Yes" << endl;
	return 0;
}
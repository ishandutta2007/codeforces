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

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	for(int i = 0; i < m; ++i) cin >> l[i];
	vector<int> p(m);
	for(int i = 0; i < m; ++i) p[i] = i + 1;
	for(int i = 0; i < m; ++i) if(p[i] + l[i] - 1 > n) {
		cout << -1 << endl;
		return 0;
	}
	int last = n;
	for(int i = m - 1; i >= 0; --i) {
		chmax(p[i], last - l[i] + 1);
		last = p[i] - 1;
	}
	displayv(p);
	if(p[0] != 1) {
		cout << -1 << endl;
		return 0;
	}
	for(int x : p) cout << x << ' '; cout << endl;
	return 0;
}
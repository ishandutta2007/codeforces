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

const int maxN = 100000 + 5;
int n;
int x[maxN], y[maxN];

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	set<pii> S;
	for(int i = 0; i < n; ++i) {
		S.emplace(x[(i + 1) % n] - x[i], y[(i + 1) % n] - y[i]);
	}
	bool ok = true;
	for(int i = 0; i < n; ++i) {
		ok &= S.count(pii(-x[(i + 1) % n] + x[i], -y[(i + 1) % n] + y[i]));
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}
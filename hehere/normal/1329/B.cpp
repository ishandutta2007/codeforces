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

LL f[50];
int solve(int d, LL m) {
	LL ans = 0;
	for(int i = 0; (1 << i) <= d; ++i) {
		LL t = (1 << i);
		if((1 << (i + 1)) > d) t = d - (1 << i) + 1;
//		eprintf("%d: %lld\n", i, t);
		t = t * (1 + ans) % m;
		(ans += t) %= m;
	}
	return ans;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int T; cin >> T;
	while(T--) {
		int d, m;
		cin >> d >> m;
		cout << solve(d, m) << endl;
	}
	return 0;
}
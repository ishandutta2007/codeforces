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
#ifndef LOCAL 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	int ans = n;
	int mxl = n;
	set<int> S;
	for(int i = 0; i < n; ++i) {
		if(S.count(a[i])) {
			mxl = i; break;
		} else {
			S.insert(a[i]);
		}
	}
	if(mxl == n) {
		cout << 0 << endl;
		return 0;
	}
	int l = mxl, r = n - 1;
	while(l >= 0) {
		while(l <= r - 1 && !S.count(a[r])) S.insert(a[r--]);
		chmin(ans, r - l + 1);
		--l;
		if(l >= 0) S.erase(a[l]);
	}
	cout << ans << endl;
	return 0;
}
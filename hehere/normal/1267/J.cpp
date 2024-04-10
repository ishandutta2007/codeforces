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

const int maxN = 2000000 + 5;
int n, a[maxN];

LL solve() {
	cin >> n;
	fill(a + 1, a + n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		int c; cin >> c;
		a[c]++;
	}
	sort(a + 1, a + n + 1);
	int p = 0;
	while(a[p] == 0) ++p;
	for(int i = p; i <= n; ++i) a[i - p + 1] = a[i];
	n = n - p + 1;
	displaya(a, 1, n);
	int ans = accumulate(a + 1, a + n + 1, 0);
	for(int s = 2; s <= a[1] + 1; ++s) {
		int tot = 0;
		for(int i = 1; i <= n; ++i) {
			int that = -1;
			for(int m = a[i] / s; m <= a[i] / s + 2; ++m)
				if(m * (s - 1) <= a[i] && a[i] <= m * s) {
					that = m; break;
				}
			if(that == -1) tot = -1;
			else if(tot != -1) tot += that;
		}
		if(tot != -1) chmin(ans, tot);
	}
	return ans;
}

/*
3
11
1 5 1 5 1 5 1 1 1 1 5
6
1 2 2 2 2 1
5
4 3 3 1 2
*/

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int T; cin >> T;
	while(T--) cout << solve() << '\n';
	return 0;
}
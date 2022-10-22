#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<13;
struct SegTree {
	int t[2*N];
	SegTree() { memset(t, 0, sizeof t); }
	void insert(int x) {
		for (x+=N; x>0; x/=2) {
			t[x]++;
		}
	}
	int query(int l, int r) {
		int res = 0;
		for (l+=N,r+=N+1; l<r; l/=2,r/=2) {
			if (l&1) res += t[l++]; 
			if (r&1) res += t[--r]; 
		}
		return res;
	}
} segt[2];


//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	int cnt[n+1];
	memset(cnt, 0, sizeof cnt);
	int l[m], r[m];
	for (int i=0; i<m; i++) {
		cin >> l[i] >> r[i];
		for (int j=l[i]; j<=r[i]; j++) {
			cnt[j]++;
		}
	}

	int tot = 0;
	for (int i=1; i<=n; i++) {
		tot += (cnt[i]>0);
		if (cnt[i] == 1) {
			segt[0].insert(i);
		} else if (cnt[i] == 2) {
			segt[1].insert(i);
		}
	}

	int ans = 0;
	for (int i=0; i<m; i++) {
		for (int j=0; j<i; j++) {
			if (l[i] > r[j] || l[j] > r[i]) {
				ans = max(ans, tot - segt[0].query(l[i],r[i]) - segt[0].query(l[j],r[j]));
			} else {
				int minl = min(l[i],l[j]);
				int maxl = max(l[i],l[j]);
				int minr = min(r[i],r[j]);
				int maxr = max(r[i],r[j]);
				ans = max(ans, tot - segt[0].query(minl,maxr) - segt[1].query(maxl,minr));
			}
		}
	}
	cout << ans << nl;

	return 0;
}
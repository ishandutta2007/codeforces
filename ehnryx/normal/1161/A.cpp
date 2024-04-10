#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



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

	int a[m];
	map<int,int> idx;
	for (int i=0; i<m; i++) {
		cin >> a[i];
		idx[a[i]] = i+1;
	}

	vector<pii> order;
	for (const pii& it : idx) {
		order.push_back(pii(it.second, it.first));
	}
	for (int i=1; i<=n; i++) {
		if (!idx.count(i)) {
			order.push_back(pii(0, i));
		}
	}
	sort(order.begin(), order.end());

	ll ans = 0;
	set<int> cur;
	int pos = 0;
	for (const pii& it : order) {
		while (pos < it.first) {
			cur.insert(a[pos++]);
		}
		ans += !cur.count(it.second);
		if (it.second < n) ans += !cur.count(it.second+1);
		if (it.second > 1) ans += !cur.count(it.second-1);
	}
	cout << ans << nl;

	return 0;
}
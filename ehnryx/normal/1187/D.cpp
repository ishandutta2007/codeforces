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

const int M = 1<<19;
int segt[2*M];
int query(int l, int r) {
	int res = -1;
	for (l+=M,r+=M; l<r; l/=2,r/=2) {
		if (l&1) res = max(res, segt[l++]);
		if (r&1) res = max(res, segt[--r]);
	}
	return res;
}
void update(int x, int v) {
	segt[x+=M] = v;
	for (x/=2; x>0; x/=2) {
		segt[x] = max(segt[2*x], segt[2*x+1]);
	}
}

const int N = 3e5+1;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	For(i,n) {
		cin >> a[i];
	}
	unordered_map<int,set<int>> idx;
	For(i,n) {
		cin >> b[i];
		update(i, b[i]);
		idx[b[i]].insert(i);
	}

	For(i,n) {
		auto it = idx[a[i]].begin();
		if (it == idx[a[i]].end()) {
			cout << "NO" << nl;
			return;
		}
		if (query(0,*it) > a[i]) {
			cout << "NO" << nl;
			return;
		}
		update(*it,0);
		idx[a[i]].erase(it);
	}
	cout << "YES" << nl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
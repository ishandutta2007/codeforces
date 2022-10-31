#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1 << 20;

int a[N], h, g, can[N];
vector<int> operations;
vector<int> values[N];
ll sum = 0;

void dfs(int v, int depth) {
	if (depth == h) {
		values[v].pb(a[v]);
		return;
	}
	int l = 2 * v;
	int r = 2 * v + 1;
	dfs(l, depth + 1);
	dfs(r, depth + 1);
	
	int childSize = sz(values[l]);
	int curSize = 2 * childSize + 1;

	values[v].resize(curSize - 1);
	merge(all(values[l]), all(values[r]), values[v].begin());
	values[v].pb(a[v]);
	if (depth > g) {
		return;
	}
	if (depth == g) {
		sum += values[v][0];
		can[v] = curSize - 1;
		if (v == 1) {
			forn(i, can[v]) {
				operations.pb(v);
			}
		}
		return;
	}
	int valLeft = values[l][childSize - can[l] - 1];
	int valRight = values[r][childSize - can[r] - 1];
	if (valLeft < valRight) {
		swap(valLeft, valRight);
		swap(l, r);
	}
	int ind = int(upper_bound(all(values[r]), valLeft) - values[r].begin());
/*	cout << l << " " << r << " " << valLeft << " " << valRight << '\n';
	for(int x : values[r]) cout << x << " ";
	cout << '\n';
	cout << ind << '\n';*/
	if (can[l] == 0 && ind == childSize) {
		sum += a[v];
	} else if (ind == childSize) {
		sum += values[l][childSize - can[l]];
	} else if (can[l] == 0) {
		sum += values[r][ind];
	} else {
		sum += min(values[r][ind], values[l][childSize - can[l]]);
	}
	can[v] = can[l] + (childSize - ind);
//	cout << can[v] << '\n';
	forn(i, can[r] - (childSize - ind)) {
		operations.pb(r);
	}
	if (v == 1) {
		forn(i, can[v]) {
			operations.pb(v);
		}
	}
//	cout << v << " can " << can[v] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> h >> g;
		int n = 1 << h;
		int m = 1 << g;
		forab(i, 1, n) {
			cin >> a[i];
			values[i].clear();
		}
		sum = 0;
		operations.clear();
		dfs(1, 1);
		reverse(all(operations));
		cout << sum << '\n';
		for(int x : operations) cout << x << " ";
		cout << '\n';
	}
	
    return 0;
}
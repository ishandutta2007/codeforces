#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(2*n, vector<int>(n));
	vector<vector<set<int>>> S(n, vector<set<int>>(n));
	rep(i,0,2*n) {
		rep(j,0,n) {
			cin >> a[i][j];
			--a[i][j];
			S[j][a[i][j]].insert(i);
		}
	}
	ll ans = 1;
	vector<bool> used(2*n, false);
	vector<int> side(2*n);
	int I = 0;
	while (true) {
		bool any = false;
		int r;
		int i = I;
		while (!any) {
			rep(j,0,n) {
				if (sz(S[i][j]) == 1) {
					any = true;
					r = *S[i][j].begin();
					break;
				}
			}
			if (any)
				break;
			i = (i+1)%n;
			if (i == I)
				break;
		}
		I = i;
		if (!any) {
			rep(i,0,2*n)
				if (!used[i]) {
					r = i;
					any = true;
				}
			if (!any)
				break;
			ans = (ans*2) % MOD;
		}
		used[r] = true;
		side[r] = 0;
		set<int> toRemove;
		rep(l,0,n) {
			for (int k : S[l][a[r][l]]) {
				toRemove.insert(k);
			}
		}
		for (int k : toRemove) {
			used[k] = true;
			side[k] = k == r;
			rep(l,0,n)
				S[l][a[k][l]].erase(k);
		}
	}
	cout << ans << endl;
	rep(i,0,2*n) {
		if (side[i] == 1) {
			cout << i+1 << " ";
		}
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}
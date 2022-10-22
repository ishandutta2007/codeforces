#include <bits/stdc++.h>
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n*m);
	vector<pair<int, int>> b;
	rep(i,0,n*m) {
		cin >> a[i];
		b.emplace_back(a[i], i);
	}
	sort(all(b));
	vector<int> pos_to_vis(n*m+1);
	rep(i,0,sz(b)) {
		pos_to_vis[i+1] = b[i].first;
	}
	map<int, queue<int>> Q;
	rep(row,0,n) {
		for (int pos = row*m+m; pos > row*m; --pos) {
			Q[pos_to_vis[pos]].push(pos);
		}
	}
	vector<vector<bool>> occupied(n, vector<bool>(m));
	int ans = 0;
	rep(i,0,n*m) {
		int pos = Q[a[i]].front();
		Q[a[i]].pop();
		int r = (pos-1)/m;
		int c = (pos-1)%m;
		rep(j,0,c)
			ans += occupied[r][j];
		occupied[r][c] = true;
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}
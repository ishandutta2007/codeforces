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
	vector<string> s(n);
	vector<string> c(n);
	rep(i,0,n) {
		cin >> s[i];
	}
	vector<tuple<int, int, int, int>> ans;
	rrep(i,n,0)
	rrep(j,m,0) {
		if (s[i][j] == '1') {
			if (i) {
				ans.emplace_back(i, j+1, i+1, j+1);
				//cout << i << " " << j+1 << " " << i+1 << " " << j+1 << endl;
			} else if (j) {
				ans.emplace_back(i+1, j, i+1, j+1);
			} else {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto it : ans) {
		cout << std::get<0>(it) << " " << std::get<1>(it) << " " << std::get<2>(it) << " " << std::get<3>(it) << endl;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}
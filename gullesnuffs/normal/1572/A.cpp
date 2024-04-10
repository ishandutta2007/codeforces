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
	int n;
	cin >> n;
	vector<int> need_num(n);
	vector<vector<int>> unlocks(n);
	set<int> s;
	rep(i,0,n) {
		cin >> need_num[i];
		if (!need_num[i])
			s.insert(i);
		rep(k,0,need_num[i]) {
			int j;
			cin >> j;
			--j;
			unlocks[j].push_back(i);
		}
	}
	int remaining = n;
	rep(pass,1,n+5) {
		int x = 0;
		while (true) {
			auto it = s.lower_bound(x);
			if (it == s.end())
				break;
			--remaining;
			x = *it;
			s.erase(x);
			for (int i : unlocks[x]) {
				--need_num[i];
				if (!need_num[i])
					s.insert(i);
			}
		}
		if (!remaining) {
			cout << pass << endl;
			return;
		}
	}
	cout << "-1" << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}
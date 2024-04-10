#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;

	int n = s.size();
	vector<vector<int>> ans;
	stack<int> one, zero;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (one.empty()) {
				ans.push_back({i+1});
				zero.push(ans.size()-1);
			} else {
				int id = one.top();
				one.pop();
				ans[id].push_back(i+1);
				zero.push(id);
			}
		}
		else {
			if (zero.empty()) {
				cout << -1 << nl;
				return 0;
			} else {
				int id = zero.top();
				zero.pop();
				ans[id].push_back(i+1);
				one.push(id);
			}
		}
	}

	if (!one.empty()) {
		cout << -1 << nl;
	}
	else {
		cout << ans.size() << nl;
		for (const vector<int>& v : ans) {
			cout << v.size() << " ";
			for (int it : v) {
				cout << it << " ";
			}
			cout << nl;
		}
	}

	return 0;
}
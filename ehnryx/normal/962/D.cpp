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

	int n;
	cin >> n;

	int a[n+1];
	map<ll,set<int>> index;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		index[a[i]].insert(i);
	}

	map<int,ll> ans;
	while (!index.empty()) {
		map<ll,set<int>>::iterator cur = index.begin();
		ll val = cur->first;
		vector<int> row;
		for (int it : cur->second) {
			row.push_back(it);
		}

		for (int i = 1; i < row.size(); i += 2) {
			index[2*cur->first].insert(row[i]);
		}
		if (row.size() % 2 == 1) {
			ans[row.back()] = val;
		}
		index.erase(cur);
	}

	cout << ans.size() << nl;
	for (const pair<int,ll>& it : ans) {
		cout << it.second << " ";
	}
	cout << nl;

	return 0;
}
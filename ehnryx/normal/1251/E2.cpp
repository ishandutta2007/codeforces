#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		map<int,vector<int>> vals;
		for (int i=0;i<n;i++) {
			int m, p;
			cin >> m >> p;
			vals[m].push_back(p);
		}

		priority_queue<int> nxt;
		int left = n;
		int bought = 0;
		ll ans = 0;
		for (auto it=vals.rbegin(); it!=vals.rend(); it++) {
			left -= it->second.size();
			for(auto jt:it->second) {
				nxt.push(-jt);
			}
			while (left + bought < it->first) {
				ans += -nxt.top();
				nxt.pop();
				bought++;
			}
		}
		cout << ans << nl;
	}

	return 0;
}
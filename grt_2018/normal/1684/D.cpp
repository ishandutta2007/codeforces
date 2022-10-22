//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t, n, k;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		ll ans = 0;
		priority_queue<int>PQ = {};
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			ans += x;
			PQ.push(-(-x + (n - 1 - i)));
		}
		ll res = ans;
		for(int i = 0; i < k; ++i) {
			auto tp = PQ.top();
			PQ.pop();
			ans -= tp;
			res = min(res, ans - (ll)i * (i + 1) / 2);
		}
		cout << res << "\n";
	}
			
			
}
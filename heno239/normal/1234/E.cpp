#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

vector<int> loc[1 << 18];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> difs(m - 1);
	vector<int> x(m);
	rep(i, m) {
		cin >> x[i]; x[i]--;
		loc[x[i]].push_back(i);
	}
	ll ans = 0;
	rep(i, m - 1) {
		difs[i] = abs(x[i + 1] - x[i]);
		ans += difs[i];
	}
	vector<ll> anss;
	rep(i, n) {
		anss.push_back(ans);
		if (i < n - 1) {
			for (int to : loc[i]) {
				if (to - 1 >= 0) {
					if (x[to - 1] != i && x[to - 1] != i + 1) {
						ans -= difs[to - 1];
						if (x[to - 1] < i) {
							difs[to - 1] = i - x[to - 1];
						}
						else {
							difs[to - 1] = x[to - 1] - i - 1;
						}
						ans += difs[to - 1];
					}
				}
				if (to + 1 < m) {
					if (x[to + 1] != i && x[to+ 1] != i + 1) {
						ans -= difs[to];
						if (x[to + 1] < i) {
							difs[to] = i - x[to + 1];
						}
						else {
							difs[to] = x[to + 1] - i - 1;
						}
						ans += difs[to];
					}
				}
			}
			for (int to : loc[i+1]) {
				if (to - 1 >= 0) {
					if (x[to - 1] != i && x[to - 1] != i + 1) {
						ans -= difs[to - 1];
						if (x[to - 1] < i) {
							difs[to - 1] = x[to - 1] + 1;
						}
						else {
							difs[to - 1] = x[to - 1];
						}
						ans += difs[to - 1];
					}
				}
				if (to + 1 < m) {
					if (x[to + 1] != i && x[to + 1] != i + 1) {
						ans -= difs[to];
						if (x[to + 1] < i) {
							difs[to] = x[to + 1] + 1;
						}
						else {
							difs[to] = x[to + 1];
						}
						ans += difs[to];
					}
				}
			}
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << anss[i];
	}
	cout << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}
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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	int le = -1, ri = mod;
	int ans;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		int l = 0, r = 1000000000;
		bool valid = true;
		rep(i, n-1) {
			if (a[i] >= 0 && a[i + 1] >= 0) {
				int dif = abs(a[i + 1] - a[i]);
				if (dif > mid)valid = false;
			}
			else if (a[i] < 0 && a[i + 1] < 0)continue;
			else if (a[i] < 0) {
				l = max(l, a[i + 1] - mid);
				r = min(r, a[i + 1] + mid);
			}
			else {
				l = max(l, a[i] - mid);
				r = min(r, a[i] + mid);
			}
		}
		//cout << mid << " ? " << l << " "<<r << endl;
		if (!valid || l > r) {
			le = mid;
		}
		else {
			ri = mid;
			ans = l;
		}
	}
	//cout << ri << endl;
	cout << ri << " " << ans << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	stop
		return 0;
}
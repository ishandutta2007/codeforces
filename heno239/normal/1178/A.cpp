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
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int sum = 0;
	vector<int> ans;
	int alsum = 0;
	rep(i, n) {
		cin >> a[i]; alsum += a[i];
	}
	ans.push_back(0); sum += a[0];
	rep1(i, n - 1) {
		if (a[0] >= 2 * a[i]) {
			ans.push_back(i); sum += a[i];
		}
	}
	alsum = alsum / 2 + 1;
	if (sum < alsum) {
		cout << 0 << endl;
	}
	else {
		cout << ans.size() << endl;
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i] + 1;
		}
		cout << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}
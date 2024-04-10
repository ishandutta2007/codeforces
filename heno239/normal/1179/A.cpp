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
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<P> ans;
	int ma = 0;
	rep(i, n)ma = max(ma, a[i]);
	queue<int> que; int memo = a[0];
	rep1(i, n-1)que.push(a[i]);
	while (memo != ma) {
		int nex= que.front(); que.pop();
		ans.push_back({ memo,nex });
		if (memo > nex) {
			que.push(nex);
		}
		else {
			que.push(memo);
			memo = nex;
		}
	}
	vector<int> b;
	b.push_back(memo);
	while (!que.empty()) {
		b.push_back(que.front()); que.pop();
	}
	rep(i, q) {
		ll m; cin >> m;
		if (m <= ans.size()) {
			cout << ans[m - 1].first << " " << ans[m - 1].second << endl;
		}
		else {
			m -= (int)ans.size(); m--;
			m %= (n - 1);
			cout << ma << " " << b[m + 1] << endl;
		}
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
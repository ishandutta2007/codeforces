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

//#define int long long
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
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

ll dp[1 << 18][2];

vector<int> G[1 << 18];

void dfs(int id) {
	if (G[id].size() == 0) {
		dp[id][0] = dp[id][1] = 1;
	}
	dp[id][0] = 1;
	dp[id][1] = 1;
	rep(j, G[id].size()) {
		int to = G[id][j];
		dfs(to);
		(dp[id][0] *= dp[to][0]) %= mod;
		(dp[id][1] *= dp[to][0] + dp[to][1]) %= mod;
	}
}

ll ans[1 << 18];

void dfs2(int id,LP p) {
	if (id == 0) {
		vector<LP> memo;
		rep(j, G[id].size()) {
			int to = G[id][j];
			memo.push_back({ dp[to][0],dp[to][0] + dp[to][1] });
		}
		vector<ll> lf(memo.size()+1), ls(memo.size() + 1), rf(memo.size() + 1), rs(memo.size() + 1);
		lf[0] = ls[0] = 1;
		rep(j, memo.size()) {
			lf[j + 1] = lf[j] * memo[j].first%mod;
			ls[j + 1] = ls[j] * memo[j].second%mod;
		}
		rf[memo.size()] = rs[memo.size()] = 1;
		per(j, (int)memo.size()) {
			rf[j] = rf[j + 1] * memo[j].first%mod;
			rs[j] = rs[j + 1] * memo[j].second%mod;
		}
		ans[id] = ls[memo.size()];
		rep(j, memo.size()) {
			int to = G[id][j];
			ll d0 = lf[j] * rf[j + 1] % mod;
			ll d1 = ls[j] * rs[j + 1] % mod;
			dfs2(to, { d0,d1 });
		}
	}
	else {
		//cout << " ? " << id << " " << p.first << " " << p.second << endl;
		vector<LP> memo;
		rep(j, G[id].size()) {
			int to = G[id][j];
			memo.push_back({ dp[to][0],dp[to][0] + dp[to][1] });
		}
		memo.push_back({ p.first,p.first + p.second });
		vector<ll> lf(memo.size() + 1), ls(memo.size() + 1), rf(memo.size() + 1), rs(memo.size() + 1);
		lf[0] = ls[0] = 1;
		rep(j, memo.size()) {
			lf[j + 1] = lf[j] * memo[j].first%mod;
			ls[j + 1] = ls[j] * memo[j].second%mod;
		}
		rf[memo.size()] = rs[memo.size()] = 1;
		per(j, (int)memo.size()) {
			rf[j] = rf[j + 1] * memo[j].first%mod;
			rs[j] = rs[j + 1] * memo[j].second%mod;
		}
		ans[id] = ls[memo.size()];
		rep(j, (int)memo.size()-1) {
			int to = G[id][j];
			ll d0 = lf[j] * rf[j + 1] % mod;
			ll d1 = ls[j] * rs[j + 1] % mod;
			dfs2(to, { d0,d1 });
		}
	}
}

void solve(){
	int n; cin >> n;
	rep(i, n - 1) {
		int p; cin >> p;
		G[p - 1].push_back(i + 1);
	}
	dfs(0); dfs2(0, { 0,0 });
	/*rep(i, n) {
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}*/
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}
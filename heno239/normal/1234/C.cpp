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

bool dp[1 << 18][4];
char mp[2][1 << 18];

int judge(char t) {
	if (t <= '2')return 0;
	else return 1;
}
void solve() {
	int n; cin >> n;
	rep(i, n + 1)rep(j, 4)dp[i][j] = false;
	dp[0][1] = true;
	rep(i, 2)rep(j, n)cin >> mp[i][j];
	rep(i, n) {
		int c = judge(mp[0][i]);
		int d = judge(mp[1][i]);
		rep(j, 4) {
			if (!dp[i][j])continue;
			bool up = j % 2;
			bool dow = j / 2;
			int nex = 0;
			if (!c&&up)nex |= 1;
			if (!d&&dow)nex |= 2;
			if (c&&d) {
				if (up)nex |= 2;
				if (dow)nex |= 1;
			}
			dp[i + 1][nex] = true;
		}
	}
	if (dp[n][2] || dp[n][3]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	//solve();
	stop
		return 0;
}
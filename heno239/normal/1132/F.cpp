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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

bool used[500][500];
int ans[500][500];
string s;
int dfs(int l, int r) {
	if (used[l][r])return ans[l][r];
	used[l][r] = true;
	if (r < l)return ans[l][r] = 0;
	vector<P> dp;
	char key = s[l];
	dp.push_back({ l,0 });
	Rep1(i, l+1, r) {
		if (key != s[i])continue;
		int le = i;
		while (i + 1 <= r&&s[i] == s[i + 1]) {
			i++;
		}
		int mi = mod;
		rep(j, dp.size()) {
			mi = min(mi, dp[j].second + dfs(dp[j].first + 1, le - 1));
		}
		dp.push_back({ i,mi });
	}
	if (s[r] != key) {
		int ret = mod;
		rep(j, dp.size()) {
			ret = min(ret, dp[j].second + dfs(dp[j].first + 1, r));
		}
		return ans[l][r] = ret+1;
	}
	else {
		return ans[l][r]=dp.back().second+1;
	}
}
void solve() {
	int n; cin >> n;
	cin >> s;
	cout << dfs(0, n - 1) << endl;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}
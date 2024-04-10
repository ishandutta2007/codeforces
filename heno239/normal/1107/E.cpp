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
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
bool used[100][100];
ll ans[100][100];
ll x[100];
ll num[2][101];
string s;
ll dfs(int le, int ri) {
	if (le > ri)return 0;
	if (used[le][ri])return ans[le][ri];
	used[le][ri] = true;
	int key = s[le]-'0';
	int c = 0;
	ll res = 0;
	int cur = le + 1;
	vector<vector<ll>> dp;
	vector<int>v; v.push_back(le);
	int cnt = num[key][ri + 1] - num[key][le];
	dp.resize(cnt);
	rep(i, cnt) {
		dp[i].resize(cnt + 1,-INF);
	}
	dp[0][1] = 0;
	res = dfs(le + 1, ri)+x[0];
	Rep1(i, le+1, ri) {
		if (s[i]-'0' == key) {
			c++;
			rep1(j, c) {
				rep(k, c) {
					dp[c][j + 1] = max(dp[c][j + 1], dp[k][j] + dfs(v[k] + 1, i - 1));
				}
				res = max(res, dp[c][j + 1] + x[j] + dfs(i + 1, ri));
			}
			v.push_back(i);
		}
	}
	return ans[le][ri] = res;
}
int n;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	rep(i, n) {
		if (s[i] == '1') {
			num[1][i + 1] = num[1][i]+1;
			num[0][i + 1] = num[0][i];
		}
		else {
			num[1][i + 1] = num[1][i];
			num[0][i + 1] = num[0][i]+1;
		}
	}
	rep(i, n) {
		cin >> x[i];
	}
	cout << dfs(0, n - 1) << endl;
	//stop
	return 0;
}
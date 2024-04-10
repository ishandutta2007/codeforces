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

int dp[1 << 20];
int n, m;
char mp[20][20];
int cost[20][20];

vector<P> memo[20];
void solve(){
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> mp[i][j];
		}
	}
	rep(i, n) {
		rep(j, m) {
			cin >> cost[i][j];
		}
	}
	rep(j, m) {
		vector<bool> used(n, false);
		rep(i, n) {
			if (used[i])continue;
			vector<int> v; v.push_back(i);
			used[i] = true;
			Rep(k, i + 1, n) {
				if (mp[i][j] == mp[k][j]) {
					used[k] = true; v.push_back(k);
				}
			}
			int s = 0; int sum = 0;
			int ma = 0;
			rep(k, v.size()) {
				s += 1 << v[k]; sum += cost[v[k]][j];
				ma = max(ma, cost[v[k]][j]);
			}
			memo[j].push_back({ s,sum - ma });
			
		}
	}
	fill(dp, dp + (1 << n), mod);
	dp[0] = 0;
	rep(j, m) {
		rep(i, (1 << n)) {
			// add 1
			rep(k, n) {
				if ((i&(1 << k)) == 0) {
					dp[i ^ (1 << k)] = min(dp[i ^ (1 << k)], dp[i] + cost[k][j]);
				}
			}
			//add all
			rep(k, memo[j].size()) {
				dp[i | memo[j][k].first] = min(dp[i | memo[j][k].first], dp[i] + memo[j][k].second);
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
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
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
ll dp[100001][202];
int n, m, k;
typedef pair<LP, int> speP;
vector<speP> c[100001];
vector<int> vc[100001];
bool canuse[100001];

priority_queue<speP> q;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	rep(i, k) {
		int s, t, d; ll w;
		cin >> s >> t >> d >> w; s--; t--; d--;
		c[s].push_back({ {w,d},i });
		vc[t].push_back(i);
	}
	rep(i, n + 1) {
		rep(j, m + 1) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, c[i].size()) {
			q.push(c[i][j]);
			canuse[c[i][j].second]=true;
		}
		while (!q.empty()) {
			speP p = q.top();
			if (!canuse[p.second])q.pop();
			else break;
		}
		rep(j, m+1) {
			if (dp[i][j] == INF)continue;
			//disturb
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			//non disturb
			if (q.empty()) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
			else {
				speP p = q.top();
				int nex = p.first.second;
				dp[nex + 1][j] = min(dp[nex + 1][j], dp[i][j] + p.first.first);
			}
		}
		rep(j, vc[i].size()) {
			canuse[vc[i][j]] = false;
		}
	}
	ll ans = INF;
	rep(i, m + 1) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
	//stop
	return 0;
}
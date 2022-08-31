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
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<ll, ll> LP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef long double ld;



ll dp[1002][1001];

void solve() {
	string t; cin >> t;
	reverse(all(t));
	int n; cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
		reverse(all(s[i]));
	}
	vector<int> score(10);
	rep(i, 10)cin >> score[i];
	vector<vector<int>> memo;
	vector<int> ids;
	rep(i, n)ids.push_back(i);
	memo.push_back(ids);
	rep(i, 1001) {
		vector<int> nex[10];
		for (int id : ids) {
			if (i < s[id].size()) {
				nex[s[id][i] - '0'].push_back(id);
			}
			else {
				nex[0].push_back(id);
			}
		}
		ids.clear();
		rep(j, 10)for (int id : nex[j])ids.push_back(id);
		memo.push_back(ids);
	}
	rep(i, 1002)rep(j, n + 1)dp[i][j] = -INF;
	dp[0][n] = 0;
	rep(i, 1001) {
		rep(to, 10) {
			if (i < t.size() && t[i] != '?') {
				if ((t[i] - '0') != to)continue;
			}
			if (i >= t.size() && to > 0)continue;
			if (i == (int)t.size() - 1 && t.back() == '?'&&to == 0)continue;
			
			int c = 0;

			ll sum = 0;
			rep(j, n) {
				int id = memo[i + 1][j];
				int x = 0;
				if (i < s[id].size()) {
					x = s[id][i] - '0';
				}
				if (x + to < 10)c++;
				int r = (x + to) % 10;
				if ((x+to)!=0||i<s[id].size()||i<t.size()) {
					sum += score[r];
				}
			}
			for (int j = n; j >= 0; j--) {
				dp[i + 1][c] = max(dp[i + 1][c], dp[i][j] + sum);
				if (j > 0) {
					int id = memo[i][j - 1];

					int x = 0;
					if (i < s[id].size()) {
						x = s[id][i] - '0';
					}

					if ((x + to) != 0 || i<s[id].size()||i<t.size()) {
						sum -= score[(x+to)%10];
					}
					sum += score[(x + to + 1) % 10];
					if (x + to + 1 == 10) {
						c--;
						//assert(memo[i + 1][c] == id);
					}
				}
			}
		}
	}
	ll ans = dp[1001][n];
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//int t; cin >> t; rep(i, t)
		solve();
	stop
		return 0;
}
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
int alf[26];
ll dp[1 << 20][26];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int m = s.length();
	rep(i, m) {
		ll sum = 0;
		rep(j, k) {
			sum += dp[i][j];
		}
		sum %= mod;
		rep(j, k) {
			if (s[i] == 'a' + j) {
				dp[i + 1][j] = sum+1;
			}
			else {
				dp[i + 1][j]=dp[i][j];
			}
		}
	}
	rep(j, 26) {
		dp[0][j] = dp[m][j];
	}
	vector<char> u;
	bool used[26] = {};
	per(i, m) {
		if (!used[s[i] - 'a']) {
			used[s[i] - 'a'] = true;
			u.push_back(s[i]);
		}
	}
	rep(i, k) {
		if (!used[i]) {
			u.push_back('a' + i);
		}
	}
	reverse(u.begin(), u.end());
	//cout << dp[m][0] + dp[m][1] + dp[m][2] << endl;
	rep(i, n) {
		ll sum = 0;
		rep(j, k) {
			sum += dp[i][j];
		}
		sum %= mod;
		rep(j, k) {
			if (u[i%k] == 'a' + j) {
				dp[i + 1][j] = sum+1;
			}
			else {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}

	ll out = 0;
	rep(j, k) {
		//1 3cout << dp[m + n][j] << endl;
		out += dp[n][j];
	}
	cout << (out+1) % mod << endl;
		return 0;
}
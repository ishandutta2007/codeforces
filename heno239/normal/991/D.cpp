#include<iostream>
#include<cstdio>
#include<string>
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
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
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
int main() {
	string s;
	cin >> s;
	int len = s.length();
	char board[2][100];
	rep(i, 2) {
		if (i == 1)cin >> s;
		rep(j, len) {
			board[i][j] = s[j];
		}
	}
	int dp[100][4] = {};
	Rep(i, 1, len) {
		int ma = 0;
		rep(j, 4) {
			ma = max(dp[i - 1][j], ma);
		}
		dp[i][0] = ma;
		if (board[1][i] == '0'&&board[1][i-1]=='0'&&board[0][i-1]=='0') {
			dp[i][1] = dp[i - 1][0] + 1;
		}
		if (board[0][i] == '0'&&board[1][i - 1] == '0'&&board[0][i - 1] == '0') {
			dp[i][2] = dp[i - 1][0] + 1;
		}
		if (board[0][i] == '0'&&board[1][i] == '0') {
			if (board[0][i - 1] == '0') {
				dp[i][3] = max(dp[i][3], dp[i - 1][0] + 1);
				dp[i][3] = max(dp[i][3], dp[i - 1][1] + 1);
			}
			if (board[1][i - 1] == '0') {
				dp[i][3] = max(dp[i][3], dp[i - 1][0] + 1);
				dp[i][3] = max(dp[i][3], dp[i - 1][2] + 1);
			}
		}
	}
	int out = 0;
	rep(i, 4) {
		out = max(out, dp[len-1][i]);
	}
	cout << out << endl;
	return 0;
}
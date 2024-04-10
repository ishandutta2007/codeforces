#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	int n, m;
	cin>>n>>m;
	vector<string>  s(n);
	vector<vector<int> > c(n, vector<int>(2, INF));
	REP(i, n) {
		cin>>s[i];
	}
	bool hoge = false;
	int maxi = -1;
	REP(i, n) {
		REP(j, m + 2) {
			if(s[i][j] == '1') {
				if(c[i][0] == INF) {
					c[i][0] = c[i][1] = j;
				} else {
					c[i][1] = j;
				}
			}
		}
		if(c[i][0] == INF && !hoge) {
			maxi = i;
			c[i][0] = m + 1;
			c[i][1] = 0;
		} else if(c[i][0] == INF) {
			hoge = true;
			c[i][0] = m + 1;
			c[i][1] = 0;
		} else {
			hoge = true;
		}
	}
	vector<vector<int> > dp(n, vector<int>(2));
	FOR(i, maxi + 1, n) {
		if(i != maxi + 1) {
			dp[i][0] = c[i][1] + min(dp[i - 1][0] + c[i][1] + 1, dp[i - 1][1] + (m + 1) - c[i][1] + 1);
			dp[i][1] = (m + 1) - c[i][0] + min(dp[i - 1][0] + c[i][0] + 1, dp[i - 1][1] + (m + 1) - c[i][0] + 1);
		} else {
			dp[i][0] = c[i][1];
			dp[i][1] = (m + 1) - c[i][0];
		}
	}
	cout<<dp[n - 1][0]<<endl;
}
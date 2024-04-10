#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll dp[555][555];
int n;
string s;

ll dfs(ll l, ll r) {
	if(dp[l][r] != -1) return dp[l][r];
	if(r - l == 0) return 0;
	if(r - l == 1) return 1;
	ll ret = INF;
	for(ll i = l + 1; i < r; i++) {
		ret = min(ret, dfs(l, i) + dfs(i, r));
	}
	ret = min(ret, 1 + dfs(l + 1, r));
	for(ll i = l + 1; i < r; i++) {
		if(s[i] != s[l]) continue;
		ret = min(ret, dfs(l + 1, i) + dfs(i, r));
	}
	return dp[l][r] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	REP(i, 555) REP(j, 555) dp[i][j] = -1;
	cout << dfs(0, n) << endl;
}
/* --------------------------------------- */
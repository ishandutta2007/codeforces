#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
ll dp[N][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int T;
	for(cin>>T;T--;) {
		int n, a, b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		s += '0';
		memset(dp,INF,sizeof dp);
		dp[0][0] = b;
		for(int i=1;i<=n;i++) {
			dp[i][1] = min(dp[i][1], dp[i-1][1]+2*b+a);
			dp[i][1] = min(dp[i][1], dp[i-1][0]+2*b+2*a);
			if(s[i-1]=='0'&&s[i]=='0') {
				dp[i][0] = min(dp[i][0], dp[i-1][0]+b+a);
				dp[i][0] = min(dp[i][0], dp[i-1][1]+b+2*a);
			}
		}
		cout<<dp[n][0]<<nl;
	}

	return 0;
}
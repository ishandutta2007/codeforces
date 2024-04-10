#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll dp[505][1005];
ll MOD;
ll a[505];

int main(){
	int n, m, b;
	cin >> n >> m >> b;
	cin >> MOD;
	rep(i,0,n)
		cin >> a[i];
	bool read=0, write=1;
	rep(i,0,505)
		rep(j,0,505)
			dp[i][j]=0;
	dp[0][0]=1;
	write^=1;
	read^=1;
	rep(i,0,n){
		read^=1;
		write^=1;
		rep(j,0,b+1){
			rep(k,0,m+1){
				dp[k+1][j+a[i]]=(dp[k+1][j+a[i]]+dp[k][j])%MOD;
			}
		}
	}
	ll ans=0;
	rep(j,0,b+1)
		ans=(ans+dp[m][j])%MOD;
	cout << ans << endl;
}
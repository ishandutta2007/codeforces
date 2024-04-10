#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll dp[5001][5001];
ll f[5001][5001];
vector<ll> a;

ll dfs(ll l, ll r) {
	if(dp[l][r]!=-1) return dp[l][r];
	if(l==r) {
		f[l][r]=a[l];
		return a[l];
	}
	ll ret=0;
	ret=max(ret,dfs(l+1,r));
	ret=max(ret,dfs(l,r-1));
	f[l][r]=f[l+1][r]^f[l][r-1];
	ret=max(ret,f[l][r]);
	return dp[l][r]=ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	REP(i,5001) REP(j,5001) {
		dp[i][j]=-1;
		f[i][j]=-1;
	}
	ll n;
	cin>>n;
	a.resize(n);
	REP(i,n) cin>>a[i];
	ll q;
	cin>>q;
	REP(i,q) {
		ll l,r;
		cin>>l>>r;
		l--;
		r--;
		cout<<dfs(l,r)<<endl;
	}
}
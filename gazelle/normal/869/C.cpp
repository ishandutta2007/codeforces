#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 998244353ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
ll memo[5001][5001];
ll dfs(ll pos, ll tgt) {
	if(memo[pos][tgt]!=INF*INF) return memo[pos][tgt];
	if(pos==1) return memo[pos][tgt]=(tgt+1)%MOD;
	if(tgt==0) return memo[pos][tgt]=1;
	ll ret=0;
	ret+=tgt*dfs(pos-1,tgt-1)+dfs(pos-1,tgt);
	return memo[pos][tgt]=ret%MOD;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<ll> d(3);
	cin>>d[0]>>d[1]>>d[2];
	sort(ALL(d));
	ll a=d[2],b=d[1],c=d[0];
	ll res=1;
	REP(i,5001) {
		REP(j,5001) {
			memo[i][j]=INF*INF;
		}
	}
	res*=dfs(a,b);
	res%=MOD;
	res*=dfs(a,c);
	res%=MOD;
	res*=dfs(b,c);
	cout<<res%MOD<<endl;
}
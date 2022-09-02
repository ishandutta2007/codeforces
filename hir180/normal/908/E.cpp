#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[1005],c[1005][1005];
int n,m;
map<string,int>M;
string x[1005];
int main(){
	rep(i,1005)rep(j,i+1){
		if(j==0||j==i)c[i][j]=1;
		else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	dp[0] = dp[1] = 1;
	for(int i=2;i<=1000;i++){
		for(int j=1;j<=i;j++){
			dp[i] += c[i-1][j-1]*dp[i-j]%mod;
			dp[i] %= mod;
		}
	}
	cin>>n>>m;
	for(int i=0;i<m;i++){
		string s; cin>>s;
		for(int j=0;j<n;j++){
			x[j].pb(s[j]);
		}
	}
	for(int i=0;i<n;i++) M[x[i]]++;
	ll ans = 1;
	for(map<string,int>::iterator it=M.begin();it!=M.end();++it){
		ans = ans*dp[it->sc]%mod;
	}
	cout<<ans<<endl;
}
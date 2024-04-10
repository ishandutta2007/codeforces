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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,k;
ll c[2005][2005];
int main(){
	cin>>n>>m>>k;
	rep(i,2005)rep(j,i+1){
		if(j==0 || j==i) c[i][j] = 1;
		else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	}
	ll ans = m;
	for(int i=0;i<k;i++) ans = ans*1LL*(m-1)%mod;
	ans = ans*c[n-1][k]%mod;
	cout<<ans<<endl;
}
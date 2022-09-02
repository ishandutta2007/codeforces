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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
int n;
ll p,q,r,a[100005],up[100005][3],down[100005][3];
int main(){
	cin>>n>>p>>q>>r;
	repn(i,n)scanf("%lld",&a[i]);
	rep(i,3) up[0][i] = -8e18;
	repn(i,n){
	    up[i][0] = max(up[i-1][0],p*a[i]);

	}
	rep(i,3) down[n+1][i] = -8e18;
	for(int i=n;i>=1;i--){
	    down[i][2] = max(down[i+1][2],r*a[i]);
	}
	ll ans = -8e18;
	for(int i=1;i<=n;i++){
		ans = max(ans,up[i][0]+a[i]*q+down[i][2]);
	}
	cout<<ans<<endl;
}
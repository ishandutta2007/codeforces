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
int n,m;
ll best[2005];
ll a[2005],b[2005];
ll S;
int main(){
	cin>>n>>m;
	repn(i,n) cin>>a[i];
	repn(i,m) cin>>b[i];
	cin>>S;
	for(int i=0;i<2005;i++) best[i] = 1e18;
	for(int i=1;i<=m;i++){
		ll cur = 0;
		for(int j=i;j<=m;j++){
			cur += b[j];
			best[j-i+1] = min(best[j-i+1],cur);
		}
	}
	for(int i=1;i<m;i++) assert(best[i] < best[i+1]);
	ll ans = 0;
	repn(i,n){
		ll cur = 0;
		for(int j=i;j<=n;j++){
			cur += a[j];
			if(cur > S) continue;
			ll zan = S/cur;
			int f = upper_bound(best+1,best+m+1,zan)-best;
			//best[f-1] is ok
			ans = max(ans,1LL*(j-i+1)*(f-1));
		}
	}
	cout << ans << endl;
}
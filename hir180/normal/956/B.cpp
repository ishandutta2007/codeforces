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
ll v[100005],u;
int n;
int main(){
	cin>>n>>u;
	rep(i,n) cin>>v[i];
	double ans = -1e18;
	for(int i=0;i<n-2;i++){
		ll ok = v[i]+u;
		int k = upper_bound(v,v+n,ok)-v;
		k--;
		if(k<i+2){
			continue;
		}
		ans = max(ans,(double)(v[k]-v[i+1])/(double)(v[k]-v[i]));
	}
	if(ans>-1e2) printf("%.10f\n",ans);
	else puts("-1");
}
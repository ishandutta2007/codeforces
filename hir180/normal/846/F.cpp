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
vector<int>a[1000005];
int n,x[1000005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=1000000;i++) a[i].pb(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		a[x[i]].pb(i);
	}
	for(int i=1;i<=1000000;i++) a[i].pb(n+1);
	double ans = 0;
	for(int i=1;i<=1000000;i++){
		ll cur = 1LL*n*n;
		for(int j=1;j<a[i].size();j++){
			cur -= 1LL*(a[i][j]-a[i][j-1]-1)*(a[i][j]-a[i][j-1]-1);
		}
		ans += (double)(cur)/(double)(1LL*n*n);
	}
	printf("%.8f\n",ans);
}
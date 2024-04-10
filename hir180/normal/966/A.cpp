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
ll n,m,cl,ce,v;
int q;
vector<ll>L,E;
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&cl,&ce,&v);
	rep(i,cl){
		ll a; scanf("%lld",&a);
		L.pb(a);
	}
	rep(i,ce){
		ll a; scanf("%lld",&a);
		E.pb(a);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		ll xa,ya,xb,yb; scanf("%lld%lld%lld%lld",&xa,&ya,&xb,&yb);
		if(xa > xb){
			swap(xa,xb);
			swap(ya,yb);
		}
		ll ans = 1e18;
		int x = POSL(L,ya);
		for(int y=x-2;y<=x+2;y++){
			if(0<=y && y<L.size()){
				ans = min(ans,abs(L[y]-ya) + abs(xb-xa) + abs(L[y]-yb));
			}
		}
		x = POSL(E,ya);
		for(int y=x-2;y<=x+2;y++){
			if(0<=y && y<E.size()){
				ans = min(ans,abs(E[y]-ya) + (abs(xb-xa)+v-1)/v + abs(E[y]-yb));
			}
		}
		x = POSL(L,yb);
		for(int y=x-2;y<=x+2;y++){
			if(0<=y && y<L.size()){
				ans = min(ans,abs(L[y]-ya) + abs(xb-xa) + abs(L[y]-yb));
			}
		}
		x = POSL(E,yb);
		for(int y=x-2;y<=x+2;y++){
			if(0<=y && y<E.size()){
				ans = min(ans,abs(E[y]-ya) + (abs(xb-xa)+v-1)/v + abs(E[y]-yb));
			}
		}
		if(xa == xb) ans = min(ans,abs(ya-yb));
		printf("%lld\n",ans);
	}
}
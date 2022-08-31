#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const ll mod = 1000000007;

ll x0,y0,ax,ay,bx,by;
ll xs,ys,t;
vector<pair<ll,ll>>vec;
ll dist(pair<ll,ll>a,pair<ll,ll>b){
	return abs(a.fi-b.fi)+abs(a.sc-b.sc);
}
int main(){
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	while(dist(mp(xs,ys),mp(x0,y0)) <= 3e16){
		vec.pb(mp(x0,y0));
		x0 = ax*x0+bx;
		y0 = ay*y0+by;
	}
	int ans = 0;
	rep(i,vec.size()){
		rep(j,vec.size()){
			if(i > j) continue;
			ll D = 0;
			D += min(dist(mp(xs,ys),vec[i]),dist(mp(xs,ys),vec[j]));
			for(int x=i;x<j&&D<=t;x++){
				D += dist(vec[x],vec[x+1]);
			}
			if(D <= t){
				ans = max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<endl;
}
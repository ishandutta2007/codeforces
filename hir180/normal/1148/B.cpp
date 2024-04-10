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
ll ta,tb,k,a[200005],b[200005];

int main(){
	scanf("%d%d%lld%lld%lld",&n,&m,&ta,&tb,&k);
	repn(i,n) scanf("%lld",&a[i]);
	repn(i,m) scanf("%lld",&b[i]);
	ll mx = 0;
	if(k >= n){
	    puts("-1"); return 0;
	}
	rep(i,n){
		ll cur = a[i+1]+ta;
		int zan = k-i;
		if(zan < 0) continue;
		int x = lower_bound(b+1,b+m+1,cur)-b;
		x += zan;
		if(x > m){
			puts("-1"); return 0;
		}
		mx = max(mx,b[x]+tb);
	}
	cout<<mx<<endl;
}
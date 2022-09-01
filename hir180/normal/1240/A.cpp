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
int q,n;
ll val[200005],rui[200005];
int x,a,y,b;
ll need;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		repn(i,n) scanf("%lld",&val[i]);
		sort(val+1,val+n+1,greater<ll>());
		for(int i=1;i<=n;i++){
			rui[i] = rui[i-1]+val[i];
		}
		scanf("%d%d%d%d%lld",&x,&a,&y,&b,&need);
		if(x < y){
			swap(x,y);
			swap(a,b);
		}
		int c = __gcd(a,b);
		ll ab = 1LL*a*b/c;
		
		int lb = 0,ub = n+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			int all = (int)(1LL*mid / ab);
			int X = mid / a; X -= all;
			int Y = mid / b; Y -= all;
			ll cur = rui[all] / 100LL * (x+y);
			cur += (rui[X+all]-rui[all]) / 100LL * x;
			cur += (rui[X+all+Y]-rui[X+all]) / 100LL * y;
			if(cur >= need) ub = mid;
			else lb = mid;
		}
		if(ub == n+1) puts("-1");
		else printf("%d\n",ub);
	}
}
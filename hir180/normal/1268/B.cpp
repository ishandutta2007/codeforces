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
const ll mod = 998244353;
int n;
ll a[300005];
ll x,y;
int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&a[i]);
	x = (a[n-1]+1)/2;
	y = a[n-1]/2;
	for(int i=n-2;i>=0;i--){
		if(i%2 == n%2){
			x += (a[i])/2;
			y += (a[i]+1)/2;
		}
		else{
			x += (a[i]+1)/2;
			y += a[i]/2;
		}
	}
	printf("%lld\n",min(x,y));
}
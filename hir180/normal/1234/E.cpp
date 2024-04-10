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
#define INF 10000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
int n,m,a[200005];
ll rui[200005];
int main(){
	scanf("%d%d",&n,&m);
	repn(i,m){
		scanf("%d",&a[i]);
	}
	repn(i,m-1){
		int x = a[i] , y = a[i+1];
		if(x == y) continue;
		if(x > y) swap(x,y);
		rui[1] += y-x;
		rui[x] -= y-x;
		rui[x+1] += y-x-1;
		rui[y] -= y-x-1;
		rui[y+1] += y-x;
		rui[x] += y-1; rui[x+1] -= y-1;
		rui[y] += x; rui[y+1] -= x;
	}
	for(int i=1;i<=n;i++) rui[i] += rui[i-1];
	for(int i=1;i<=n;i++) printf("%lld\n",rui[i]);
}
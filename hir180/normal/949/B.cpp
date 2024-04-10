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
ll n;
int q;
ll rec(ll m,ll b){
	if(m<=2) return b;
	if(b%2 == 1){
		return (b+1LL)/2;
	}
	else{
		ll gen = b/2;
		return rec(m-gen,m-gen)+gen;
	}
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		ll a; scanf("%lld",&a);
		printf("%lld\n",rec(n,a));
	}
}
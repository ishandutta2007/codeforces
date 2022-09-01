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
ll gcd(ll a,ll b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	return gcd(b,a%b);
}
int n;
int main(){
	scanf("%d",&n);
	ll x = 0;
	rep(i,n){
		ll a; scanf("%lld",&a); x = gcd(x,a);
	}
	int ans = 0;
	for(ll i=1;i*i<=x;i++){
		if(x%i!=0)continue;
		ans++;
		if(i*i!=x) ans++;
	}
	printf("%d\n",ans);
}
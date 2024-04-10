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
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll g = a; x = 1; y = 0;
	if(b != 0) g = extgcd(b,a%b,y,x),y-=(a/b)*x;
	return g;
}
ll AxB(ll A,ll B,ll C){
	//minimum non-negaitive x such that Ax godo b (mod C)
	if(B%gcd(A,C) != 0) return -1;
	ll x,y;
	extgcd(A,C,x,y);
	x = x*B/gcd(A,C)%(C/gcd(A,C));
	ll f = C/gcd(A,C);
	if(x > 0){
		x %= abs(f);
	}
	else{
		x = (x%abs(f)+abs(f))%abs(f);
	}
	return x;
}

int n,m,k;
ll solve(ll p,ll q,ll a,ll b){
	//ax-by = cx,y
	ll c = q-p;
	ll x = AxB(a,(c%b+b)%b,b);
	if(x == -1) return 1e18;
	ll y = (a*x-c)/b;
	if(y < 0){
		ll need = (-y+a-1)/a;
		x += need * b;
		y += need * a;
	}
	return a*x+p;
}
int main(){
	cin >> n >> m >> k;
	rep(i,k){
		int a,b; cin >> a >> b;
		ll ret = 1e18;
		ret = min(ret,solve(a,b,2*n,2*m));
		ret = min(ret,solve(2*n-a,b,2*n,2*m));
		ret = min(ret,solve(a,2*m-b,2*n,2*m));
		ret = min(ret,solve(2*n-a,2*m-b,2*n,2*m));
		
		if(ret > 5e17) puts("-1");
		else printf("%lld\n",ret);
	}
}
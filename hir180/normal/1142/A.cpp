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
ll n,k,a,b;
ll gcd(ll a,ll b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	else return gcd(b,a%b);
}
vector<ll>hoge;
int main(){
	cin>>n>>k>>a>>b;
	//--
	ll x = (1-a+n*k)%(n*k);
	ll y = (1-b+n*k)%(n*k);
	x = (x-y+n*k)%(n*k);
	rep(a,n){
		hoge.pb(x);
		x = (x+k)%(n*k);
	}
	//-+
	x = (1-a+n*k)%(n*k);
	y = (1+b+n*k)%(n*k);
	x = (x-y+n*k)%(n*k);
	rep(a,n){
		hoge.pb(x);
		x = (x+k)%(n*k);
	}
	//+-
	x = (1+a+n*k)%(n*k);
	y = (1-b+n*k)%(n*k);
	x = (x-y+n*k)%(n*k);
	rep(a,n){
		hoge.pb(x);
		x = (x+k)%(n*k);
	}
	//++
	x = (1+a+n*k)%(n*k);
	y = (1+b+n*k)%(n*k);
	x = (x-y+n*k)%(n*k);
	rep(a,n){
		hoge.pb(x);
		x = (x+k)%(n*k);
	}
	SORT(hoge); ERASE(hoge);
	ll mn = 1e18,mx = -1e18;
	rep(i,hoge.size()){
		ll G = gcd(hoge[i],n*k);
		mn = min(mn,G);
		mx = max(mx,G);
	}
	cout << n*k / mx << " " << n*k / mn << endl;
	return 0;
}
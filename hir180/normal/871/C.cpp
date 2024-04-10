#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int n;
int x[100005],y[100005];
vector<int>zx,zy;
int par[300005],ran[300005];
void init(){ for(int i=0;i<300005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int cnt[300005],C[300005];
int main(){
	cin>>n;
	rep(i,n){
		cin>>x[i]>>y[i];
		zx.pb(x[i]); zy.pb(y[i]);
	}
	SORT(zx); ERASE(zx);
	SORT(zy); ERASE(zy);
	init();
	rep(i,n){
		x[i]=POSL(zx,x[i]);
		y[i]=POSL(zy,y[i]);
		unite(x[i],y[i]+150000);
	}
	rep(i,n){
		cnt[find(x[i])]++;
	}
	rep(i,zx.size()) C[find(i)]++;
	rep(i,zy.size()) C[find(i+150000)]++;
	
	ll ret = 1;
	rep(i,zx.size()){
		if(find(i) != i) continue;
		ll b = 1;
		rep(j,C[i]) b = b*2LL%mod;
		if(C[i]-1 == cnt[i]) b--;
		ret = ret*b%mod;
	}
	rep(i,zy.size()){
		if(find(i+150000) != i+150000) continue;
		ll b = 1;
		rep(j,C[i+150000]) b = b*2LL%mod;
		if(C[i+150000]-1 == cnt[i+150000]) b--;
		ret = ret*b%mod;
	}
	cout<<ret<<endl;
}
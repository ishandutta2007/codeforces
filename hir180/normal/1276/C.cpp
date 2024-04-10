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
int n;
vector<int>vec;
vector<P>v;
int rui[400005],sum[400005];
vector<vector<int>>ans;
vector<P>pos;
vector<int>L;
int main(){
	scanf("%d",&n);
	rep(i,n){
		int a; scanf("%d",&a); vec.pb(a);
	}
	SORT(vec);
	int cur=0,num=0;
	rep(i,n){
		if(i==0){
			cur = vec[i]; num = 1; continue;
		}
		if(cur == vec[i]) num++;
		else{
			v.pb(P(num,cur));
			cur = vec[i] ; num = 1;
		}
	}
	v.pb(P(num,cur));
	sort(v.begin(),v.end(),greater<P>());
	rep(i,v.size()){
		rui[v[i].fi]++;
		sum[v[i].fi]+=v[i].fi;
	}
	for(int i=2;i<400005;i++) { rui[i] += rui[i-1]; sum[i] += sum[i-1]; }
	int mx = 0;
	P p;
	for(int a=1;a<=700;a++){
		int ok = sum[a] + (rui[400004]-rui[a])*a;
		ok -= ok%a;
		if(ok < a*a) continue;
		if(mx < ok){
			mx = ok;
			p = mp(a,ok/a);
		}
	}
	assert(mx);
	int a = p.fi, b = p.sc;
	if(a > b) swap(a,b);
	printf("%d\n%d %d\n",mx,a,b);
	int d = __gcd(a,b);
	rep(i,d){
		int x = 0, y = i;
		do{
			pos.pb(P(x,y));
			x = (x+1)%a;
			y = (y+1)%b;
		}while(mp(x,y) != mp(0,i));
	}
	assert(pos.size() == mx);
	
	rep(i,a){
		vector<int>x;
		x.resize(b,0);
		ans.pb(x);
	}
	rep(i,v.size()){
		rep(j,min(v[i].fi,a)){
			L.pb(v[i].sc);
		}
	}
	assert(L.size() >= mx);
	L.resize(mx);
	rep(i,pos.size()){
		ans[pos[i].fi][pos[i].sc] = L[i];
	}
	rep(i,a){
		rep(j,b) printf("%d%c",ans[i][j],(j+1==b?'\n':' '));
	}
}
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

int n;
vector<pair<ll,int>>vec;
ll target[300005];
vector<pair<ll,int>>pos,neg;
int main(){
	scanf("%d",&n);
	rep(i,n){
		ll a; scanf("%lld",&a);
		vec.pb(mp(a,i));
	}
	rep(i,n) scanf("%lld",&target[i]);
	sort(target,target+n,greater<ll>());
	
	sort(vec.begin(),vec.end(),greater<pair<ll,int>>());
	
	ll cur = 0;
	rep(i,vec.size()){
		if(vec[i].fi > target[i]){
			pos.pb(mp(vec[i].fi-target[i],vec[i].sc));
		}
		else if(vec[i].fi < target[i]){
			neg.pb(mp(target[i]-vec[i].fi,vec[i].sc));
		}
		cur += vec[i].fi - target[i];
		if(cur < 0){
			puts("NO"); return 0;
		}
	}
	if(cur != 0){
		puts("NO"); return 0;
	}
	puts("YES");
	int ptp = 0, ptn = 0;
	vector<pair<P,ll>>ans;
	//cout<<pos[0].fi << " " << pos[0].sc << endl;
	while(ptp < pos.size() && ptn < neg.size()){
		ll gen = min(pos[ptp].fi, neg[ptn].fi);
		
		ans.pb(mp(mp(pos[ptp].sc,neg[ptn].sc),gen));
		
		if(pos[ptp].fi == gen){
			ptp++;
		}
		else pos[ptp].fi -= gen;
		
		if(neg[ptn].fi == gen){
			ptn++;
		}
		else neg[ptn].fi -= gen;
	}
	assert(ptp == pos.size() && ptn == neg.size());
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d %d %lld\n",1+ans[i].fi.sc,1+ans[i].fi.fi,ans[i].sc);
	}
}
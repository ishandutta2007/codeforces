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
ll dfs(int bit,vector<pair<ll,ll>>vec){
	if(bit == 0) return 1;
	vector<pair<ll,ll>>nxt;
	ll S = 0;
	ll sum = 0;
	rep(i,vec.size()){
		ll v = vec[i].fi;
		ll m = vec[i].sc;
		sum += v; assert(m);
		if(__builtin_popcountll(m)%2 == 0){
			S += v;
			nxt.pb(mp(v,m-(m&(1LL<<bit))));
		}
	}
	assert(sum > 0);
	if(S <= 0){
		return (2LL<<bit)-1;
	}
	ll res = dfs(bit-1,nxt);
	ll res2 = (2LL<<bit)-1-res;
	
	ll check = 0, check2 = 0;
	rep(i,vec.size()){
		ll v = vec[i].fi;
		ll m = vec[i].sc;
		if(__builtin_popcountll(m&res)%2 == 1) check -= v; else check += v;
		if(__builtin_popcountll(m&res2)%2 == 1) check2 -= v; else check2 += v;
	}
	assert( (check+check2)%2 == 0 && (check+check2)/2 < 0);
	if(check < 0) return res;
	else return res2;
}
int main(){
	vector<pair<ll,ll>>vec;
	scanf("%d",&n); //n = 300000;
	ll S = 0;
	//srand((unsigned)time(NULL));
	rep(i,n){
		ll a,b; scanf("%lld%lld",&a,&b);
		//a = 1LL*rand()*rand()%(2*INF)-INF;
		//b = 1LL*rand()*rand()%( (1LL<<62)-1 ) + 1;
		S += a;
		vec.pb(mp(a,b));
	}
	if(S < 0){
		rep(i,n) vec[i].fi *= -1;
	}
	
	ll ret = dfs(61,vec);
	cout << ret << endl;
}
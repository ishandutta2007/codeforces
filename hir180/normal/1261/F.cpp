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

typedef pair<ll,ll> Q;
vector<Q>p,q;
vector<Q>a,b;
int x,y;
vector<ll>node[2][65];
vector<ll>used[2][65];

void make(ll a,ll b,ll l,ll r,int dep,int id){
	if(r < a || b < l)  return ;
	used[id][dep].pb(l);
	if(a <= l && r <= b){
	    //cout << id << " " << dep << " " << l << endl;
		node[id][dep].pb(l);
		return;
	}
	make(a,b,l,(l+r)/2,dep-1,id);
	make(a,b,(l+r)/2+1,r,dep-1,id);
}

vector<ll>val[65];

set<Q>S;
ll ans;
const ll mod = 998244353;
ll calc(ll a,ll b){
	ll x = (a+b)%mod *((b-a+1) % mod)%mod;
	x = x*((mod+1)/2)%mod;
	return x;
}

int main(){
	cin >> x;
	rep(i,x){
		ll a,b; cin >> a >> b;
		p.pb(mp(a,b));
	}
	cin >> y;
	rep(i,y){
		ll a,b; cin >> a >> b;
		q.pb(mp(a,b));
	}
	SORT(p); SORT(q);
	
	rep(i,p.size()){
		if(a.empty() || a.back().sc+1 < p[i].fi){
			a.pb(p[i]);
		}
		else{
			a.back().sc = max(a.back().sc,p[i].sc);
		}
	}
	rep(i,q.size()){
		if(b.empty() || b.back().sc+1 < q[i].fi){
			b.pb(q[i]);
		}
		else{
			b.back().sc = max(b.back().sc,q[i].sc);
		}
	}
	//rep(i,a.size()) cout << a[i].fi << " " << a[i].sc << endl;
	//rep(i,b.size()) cout << b[i].fi << " " << b[i].sc << endl;
	
	rep(i,a.size()) make(a[i].fi,a[i].sc,0,(1LL<<60)-1,60,0);
	rep(i,b.size()) make(b[i].fi,b[i].sc,0,(1LL<<60)-1,60,1);
	
	rep(d,61){
		rep(i,node[0][d].size()){
			rep(j,used[1][d].size()){
				val[d].pb( node[0][d][i] ^ used[1][d][j] );
			}
		}
	}
	rep(d,61){
		rep(i,node[1][d].size()){
			rep(j,used[0][d].size()){
				val[d].pb( node[1][d][i] ^ used[0][d][j] );
			}
		}
	}
	
	rep(d,61){ SORT(val[d]) ; ERASE(val[d]); }
	
	for(int d=60;d>=0;d--){
		rep(i,val[d].size()){
			ll l = val[d][i];
			ll r = val[d][i]+(1LL<<d)-1;
			auto it = S.lower_bound(mp(l+1,-1));
			bool bad = 0;
			if(it != S.begin()){
				it --;
				if((*it).fi <= l && r <= (*it).sc) bad = 1;
			}
			if(bad) continue;
			ans = ans+calc(l,r);
			S.insert(mp(l,r));
		}
	}
	cout << (ans%mod+mod)%mod << endl;
}
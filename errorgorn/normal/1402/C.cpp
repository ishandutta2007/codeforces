//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll n,s;
vector<ii> v;

struct line{
	ll m,c;
	
	line (ll _m,ll _c){
		m=_m,c=_c;
	}
	
	ii get(ll s){
		//mx+c=s, return ceil(x)
		
		ll pos=ceil((s-c)/(long double)m);
		return ii(pos,m*pos+c);
	}
	
	ll eval(ll x){
		return m*x+c;
	}
};

struct lin_hull{
	deque<line> dq;
	
	long double POI(line i,line j){
		return (long double)(j.c-i.c)/(i.m-j.m);
	}
	
	void add(line i){
		while (sz(dq)>=2 && POI(dq[sz(dq)-2],dq[sz(dq)-1])>=POI(dq[sz(dq)-1],i)) dq.pop_back();
		dq.push_back(i);
	}
	
	ii get(ll s){
		while (sz(dq)>=2){
			ll x=dq[0].get(s).fi;
			if (dq[0].eval(x)<=dq[1].eval(x)) dq.pop_front();
			else break;
		}
		return dq.front().get(s);
	}
} hull=lin_hull();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	
	cin>>n>>s;
	
	ll a,b;
	rep(x,0,n){
		cin>>a>>b;
		if (b<s) v.push_back(ii(b,a));
	}
	
	sort(all(v));
	
	hull.add(line(1,0)); //this line can exist
	
	ll bv=1;
	rep(x,0,sz(v)){
		if (v[x].se<=bv) continue;
		bv=v[x].se;
		
		auto res=hull.get(v[x].fi);
		hull.add(line(v[x].se,(res.se-v[x].fi)-res.fi*v[x].se));
	}
	
	auto res=hull.get(s);
	cout<<res.fi<<endl;
}
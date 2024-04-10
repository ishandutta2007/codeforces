/*













*/

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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;

long double POI(ii i,ii j){
	return (long double)(i.se-j.se)/(long double)(j.fi-i.fi);
}

ll linsum(ll i, ll j){
	return (j*(j+1)-i*(i+1))/2%MOD;
}

int n,m,q;
vector<iii> edges;
ll w[2][2005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>q;
	
	int a,b,c;
	while (m--){
		cin>>a>>b>>c;
		
		edges.push_back(iii(ii(a,b),c));
	}
	
	memset(w,128,sizeof(w));
	w[0][1]=0;
	
	a=0,b=1;
	
	ll ans=0;
	rep(x,0,min(q,4005)){
		for (auto &it:edges){
			w[b][it.fi.fi]=max(w[b][it.fi.fi],w[a][it.fi.se]+it.se);
			w[b][it.fi.se]=max(w[b][it.fi.se],w[a][it.fi.fi]+it.se);
		}
		
		ll temp=0;
		rep(y,1,n+1) temp=max(temp,w[b][y]);
		
		ans=(ans+temp)%MOD;
		
		swap(a,b);
	}
	
	if (q<=4005){
		cout<<ans<<endl;
		return 0;
	}
	
	q-=4005;
	
	vector<ii> lines;
	
	ll best=0,delta=0;
	for (auto &it:edges){
		lines.push_back({it.se,w[a][it.fi.fi]});
		lines.push_back({it.se,w[a][it.fi.se]});
	}
	
	sort(all(lines));
	
	vector<ii> hull;
	for (auto &it:lines){
		while (sz(hull)>=2 && POI(it,hull[sz(hull)-2])<=POI(hull.back(),hull[sz(hull)-2])){
			hull.pop_back();
		}
		
		hull.push_back(it);
	}
	
	//cout<<(ans+linsum(0,q)*hull.back().fi+(q-0)*hull.back().se)%MOD;
	//return 0;
	
	ll lb=0,ub;
	rep(x,0,sz(hull)){
		//cout<<hull[x].fi<<" "<<hull[x].se<<endl;
		
		if (x==sz(hull)-1) ub=1e18;
		else ub=floor(POI(hull[x],hull[x+1]));
		
		ub=min(ub,(ll)q);
		
		if (lb<ub){
			ans=(ans+linsum(lb,ub)*hull[x].fi+(ub-lb)*hull[x].se)%MOD;
			lb=ub;
		}
	}
	
	cout<<ans<<endl;
}
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

int n;
ii arr[2005];
int perm[2005];
int pos[2005];

#define di pair<double,ii>
vector<di> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	rep(x,0,n) perm[x]=x;
	
	sort(perm,perm+n,[](int i,int j){
		if (arr[i].fi!=arr[j].fi) return arr[i].fi<arr[j].fi;
		else return arr[i].se>arr[j].se;
	});
	
	//rep(x,0,n) cout<<perm[x]<<" "; cout<<endl;
	rep(x,0,n) pos[perm[x]]=x;
	
	rep(x,0,n){
		rep(y,x+1,n){
			double val;
			if (arr[x].fi==arr[y].fi) val=-1.0/0;
			else val=(double)(arr[x].se-arr[y].se)/(arr[x].fi-arr[y].fi);
			
			v.push_back({val,{x,y}});
		}
	}
	
	sort(all(v));
	//for (auto &it:v) cout<<it.fi<<" "; cout<<endl;
	
	ll ans=0;
	for (auto &it:v){
		int a=it.se.fi,b=it.se.se;
		if (pos[a]>pos[b]) swap(a,b);
		//cout<<a<<" "<<b<<endl;
		
		ll l=pos[a],r=n-2-l;
		ans+=l*(l-1)*r*(r-1)/2;
		
		swap(pos[a],pos[b]);
		swap(perm[pos[a]],perm[pos[b]]);
		
		//rep(x,0,n) cout<<perm[x]<<" "; cout<<endl;
	}
	
	cout<<ans/2<<endl;
}
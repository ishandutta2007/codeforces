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

vector<ii> v;

ll test(ll i){
	//12
	//34
	
	vector<ll> hor={v[0].fi,v[1].fi-i,v[2].fi,v[3].fi-i};
	vector<ll> ver={v[0].se,v[1].se,v[2].se-i,v[3].se-i};
	
	sort(all(hor));
	sort(all(ver));
	
	return hor[3]+hor[2]-hor[1]-hor[0]+ver[3]+ver[2]-ver[1]-ver[0];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		v.clear();
		
		ll a,b;
		rep(x,0,4){
			cin>>a>>b;
			v.push_back(ii(a,b));
		}
		
		sort(all(v));
		
		ll ans=1e18;
		do{
			ll lo=0,hi=1e9,m1,m2,v1,v2;
			while (hi-lo>10){
				m1=lo+(hi-lo)*3/7,m2=lo+(hi-lo)*4/7;
				v1=test(m1),v2=test(m2);
				
				if (v1<v2) hi=m2;
				else lo=m1;
			}
			
			rep(x,lo,hi+1) ans=min(ans,test(x));
		} while (next_permutation(all(v)));
		
		cout<<ans<<endl;
	}
}
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
#define iii pair<ll,ii>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
ll cost=0;
priority_queue<iii> pq;

ll sq(ll i){
	return i*i;
}

ll val(ll len,ll nums){
	ll unit=len/nums;
	ll extra=len-unit*nums;
	
	return (nums-extra)*sq(unit)+extra*sq(unit+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	rep(x,0,n){
		ll t;
		cin>>t;
		cost+=sq(t);
		
		pq.push(iii(val(t,1)-val(t,2),ii(t,2)));
	}
	
	rep(x,0,k-n){
		cost-=pq.top().fi;
		int a=pq.top().se.fi,b=pq.top().se.se;
		pq.pop();
		
		pq.push(iii(val(a,b)-val(a,b+1),ii(a,b+1)));
	}
	
	cout<<cost<<endl;
}
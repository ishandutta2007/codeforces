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

int n,m,k;
ll original[100005];
ll arr[100005];
iii upd[100005];
ll cnt[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
		
	rep(x,0,n) cin>>original[x];
	
	rep(x,0,m){
		cin>>upd[x].fi.fi>>upd[x].fi.se>>upd[x].se;
		upd[x].fi.fi--;
		upd[x].fi.se--;	
	}
	
	int a,b;
	rep(x,0,k){
		cin>>a>>b;
		a--,b--;
		cnt[a]++,cnt[b+1]--;
	}
	
	rep(x,0,m){
		//cout<<cnt[x]<<endl;
		arr[upd[x].fi.fi]+=upd[x].se*cnt[x];
		arr[upd[x].fi.se+1]-=upd[x].se*cnt[x];
		cnt[x+1]+=cnt[x];
	}
	
	rep(x,0,n){
		cout<<arr[x]+original[x]<<" ";
		arr[x+1]+=arr[x];
	}
	
}
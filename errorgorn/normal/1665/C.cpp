// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
int cnt[200005];
vector<int> v;

bool can(int i){
	if (i<sz(v)) return false;
	
	int tot=0;
	rep(x,0,sz(v)){
		tot+=max(0LL,v[x]-(i-x));
	}
	
	return tot<=(i-sz(v));
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n) cin>>arr[x];
		rep(x,1,n+1) cnt[x]=0;
		
		rep(x,1,n) cnt[arr[x]]++;
		
		v={1};
		rep(x,1,n+1) if (cnt[x]) v.pub(cnt[x]);
		
		sort(all(v));
		reverse(all(v));
		
		int lo=0,hi=2e5,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (can(mi)) hi=mi;
			else lo=mi;
		}
		
		cout<<hi<<endl;
	}
}
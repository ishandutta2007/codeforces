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

int n,m;
int arr[300005];
map<int,int> cnt;
vector<int> pos[300005];
set<ii> s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[x];
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			s.insert({a,b});
			s.insert({b,a});
		}
		
		cnt.clear();
		rep(x,1,n+1) cnt[arr[x]]++;
		rep(x,1,n+1) pos[x].clear();
		
		set<int> uni;
		set<int> t;
		for (auto [a,b]:cnt){
			uni.insert(a);
			t.insert(b);
			pos[b].pub(a);
		}
		
		rep(x,1,n+1) reverse(all(pos[x]));
		
		int ans=0;
		for (auto it:uni){
			for (auto it2:t){
				if (it2>cnt[it]) break;
				
				for (auto it3:pos[it2]){
					if (it==it3 || s.count({it,it3})) continue;
					ans=max(ans,(cnt[it]+it2)*(it+it3));
					break;
				}
			}
		}
		
		cout<<ans<<endl;
	}
}
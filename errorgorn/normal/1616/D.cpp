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

ll n,k;
ll arr[50005];
multiset<ll,greater<ll> > s;
multiset<ll,greater<ll> > A,B;
ll ans[50005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		A.clear();
		B.clear();
		
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		cin>>k;
		
		rep(x,1,n+1) arr[x]-=k;
		
		//rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
		
		rep(x,1,n+1) arr[x]+=arr[x-1];
		
		//rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
		
		int l=0;
		ans[0]=0;
		A.insert(0);
		rep(x,1,n+1){
			while (!s.empty() && *s.begin()>arr[x]){
				s.erase(s.find(arr[l]));
				l++;
				
				B.erase(B.find(ans[l-1]-l));
				A.insert(ans[l-1]);
			}
			
			ans[x]=*A.begin()+(x-l);
			if (!B.empty()) ans[x]=max(ans[x],*B.begin()+x);
			
			s.insert(arr[x-1]);
			B.insert(ans[x-1]-x);
		}
		
		// rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
		// cout<<ans[n]<<endl;
		
		ll val=0;
		rep(x,1,n+1) val=max(val,ans[x]);
		
		cout<<val<<endl;
	}
}
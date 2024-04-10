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
#define iii tuple<int,int,int>
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
int arr[100005];
int cnt[200010];

int solve(int l,int r){ //brute force
	int ans=1;
	rep(x,l+1,r+1){
		if ((arr[x]-arr[l])%(x-l)==0){
			int val=(arr[x]-arr[l])/(x-l)+100005;
			cnt[val]++;
			ans=max(ans,cnt[val]+1);
		}
	}
	rep(x,l+1,r+1){
		if ((arr[x]-arr[l])%(x-l)==0){
			int val=(arr[x]-arr[l])/(x-l)+100005;
			cnt[val]--;
		}
	}
	
	return ans;
}

const int B1=340;
const int B2=300;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int ans=1;
	
	rep(d,-B1,B1+1){
		vector<int> v;
		rep(x,1,n+1) v.pub(arr[x]-d*x);
		
		sort(all(v));
		
		int curr=0;
		int p=-1e18;
		for (auto it:v){
			if (it!=p){
				p=it;
				curr=0;
			}
			
			curr++;
			ans=max(ans,curr);
		}
	}
	
	rep(x,1,n){
		ans=max(ans,solve(x,min(n,x+B2)));
	}
	
	cout<<n-ans<<endl;
}
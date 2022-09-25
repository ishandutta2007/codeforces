// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int arr[100005];
int brr[100005];
int crr[100005];
int ans[100005];

vector<int> diff[100005];
vector<int> same[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		rep(x,1,m+1) cin>>crr[x];
		
		rep(x,1,n+1){
			diff[x].clear();
			same[x].clear();
		}
		
		rep(x,1,n+1){
			if (arr[x]==brr[x]) same[brr[x]].pub(x);
			else diff[brr[x]].pub(x);
		}
		
		int curr=-1;
		
		bool ok=true;
		
		rep(x,m+1,1){
			if (!diff[crr[x]].empty()){
				curr=ans[x]=diff[crr[x]].back();
				diff[crr[x]].pob();
			}
			else if (curr!=-1){
				ans[x]=curr;
			}
			else if (!same[crr[x]].empty()){
				curr=ans[x]=same[crr[x]].back();
			}
			else{
				ok=false;
			}
		}
		
		rep(x,1,n+1) if (!diff[x].empty()) ok=false;
		
		if (!ok) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			rep(x,1,m+1) cout<<ans[x]<<" "; cout<<endl;
		}
	}
}
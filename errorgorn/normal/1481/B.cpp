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

int n,k;
int arr[105];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		k--;
		rep(x,1,n+1) cin>>arr[x];
		arr[0]=1e9;
		
		while (true){
			int r=-1;
			rep(x,n,1) if (arr[x]<arr[x+1]) r=x;
			
			if (r==-1){
				cout<<"-1"<<endl;
				break;
			}
			
			int l=r;
			while (1<=l-1 && arr[l-1]==arr[l]) l--;
			
			if ((min(arr[r+1],arr[l-1])-arr[r])*(r-l+1)<=k){
				k-=(min(arr[r+1],arr[l-1])-arr[r])*(r-l+1);
				rep(x,l,r+1) arr[x]=min(arr[r+1],arr[l-1]);
			}
			else{
				k%=(r-l+1);
				cout<<r-k<<endl;
				break;
			}
		}
	}
}
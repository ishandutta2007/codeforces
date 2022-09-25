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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		if (n<=3){
			cout<<0<<endl;
			continue;
		}
		
		int curr=0;
		rep(x,1,n-1){
			if (arr[x-1]>arr[x] && arr[x]<arr[x+1]) curr++;
			if (arr[x-1]<arr[x] && arr[x]>arr[x+1]) curr++;
		}
		
		int ans=curr;
		
		rep(x,1,n-1){
			//cout<<"debug: "<<curr<<endl;
			
			int temp=arr[x];
			int v1=curr;
			
			if (arr[x-1]>arr[x] && arr[x]<arr[x+1]) curr--;
			if (arr[x-1]<arr[x] && arr[x]>arr[x+1]) curr--;
			if (x!=1 && arr[x-2]>arr[x-1] && arr[x-1]<arr[x]) curr--;
			if (x!=1 && arr[x-2]<arr[x-1] && arr[x-1]>arr[x]) curr--;
			if (x!=n-2 && arr[x]>arr[x+1] && arr[x+1]<arr[x+2]) curr--;
			if (x!=n-2 && arr[x]<arr[x+1] && arr[x+1]>arr[x+2]) curr--;
			
			//cout<<"debug2: "<<curr<<endl;
			int v2=curr;
			
			arr[x]=arr[x-1];
			
			if (arr[x-1]>arr[x] && arr[x]<arr[x+1]) curr++;
			if (arr[x-1]<arr[x] && arr[x]>arr[x+1]) curr++;
			if (x!=1 && arr[x-2]>arr[x-1] && arr[x-1]<arr[x]) curr++;
			if (x!=1 && arr[x-2]<arr[x-1] && arr[x-1]>arr[x]) curr++;
			if (x!=n-2 && arr[x]>arr[x+1] && arr[x+1]<arr[x+2]) curr++;
			if (x!=n-2 && arr[x]<arr[x+1] && arr[x+1]>arr[x+2]) curr++;
			
			ans=min(ans,curr);
			
			curr=v2;
			arr[x]=arr[x+1];
			
			if (arr[x-1]>arr[x] && arr[x]<arr[x+1]) curr++;
			if (arr[x-1]<arr[x] && arr[x]>arr[x+1]) curr++;
			if (x!=1 && arr[x-2]>arr[x-1] && arr[x-1]<arr[x]) curr++;
			if (x!=1 && arr[x-2]<arr[x-1] && arr[x-1]>arr[x]) curr++;
			if (x!=n-2 && arr[x]>arr[x+1] && arr[x+1]<arr[x+2]) curr++;
			if (x!=n-2 && arr[x]<arr[x+1] && arr[x+1]>arr[x+2]) curr++;
			
			ans=min(ans,curr);
			
			curr=v1;
			arr[x]=temp;
		}
		
		cout<<ans<<endl;
	}
}
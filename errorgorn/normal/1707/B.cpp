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
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[250005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		//when we go from a to b
		//sum b=max a-min a
		
		//potential=sum a
		//after 1 iter, potential <=1e5??
		//worst multitest~sqrt???
		
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		reverse(arr,arr+n);
		
		while (n!=1){
			int curr=0;
			while (curr<n-1){
				if (arr[curr+1]){
					arr[curr]-=arr[curr+1];
					curr++;
				}
				else{
					curr++;
					break;
				}
			}
			sort(arr,arr+curr);
			reverse(arr,arr+curr);
			n--;
			
			//rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
		}
		cout<<arr[0]<<endl;
	}
}
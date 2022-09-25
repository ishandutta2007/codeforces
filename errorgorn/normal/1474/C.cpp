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
int arr[2005];

multiset<int,greater<int> > s;
vector<ii> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,2*n) cin>>arr[x];
		sort(arr,arr+2*n);
		
		rep(x,0,2*n-1){
			s.clear();
			ans.clear();
			rep(y,0,2*n-1) if (y!=x) s.insert(arr[y]);
			ans.pub(ii(arr[x],arr[2*n-1]));
			
			int val=arr[2*n-1];
			
			while (!s.empty()){
				int temp=*s.begin();
				s.erase(s.begin());
				
				if (s.count(val-temp)){
					s.erase(s.find(val-temp));
					ans.pub(ii(val-temp,temp));
					val=temp;
				}
				else{
					break;
				}
			}
			
			if (s.empty()){
				cout<<"YES"<<endl;
				cout<<arr[2*n-1]+arr[x]<<endl;
				for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
				goto done;
			}
		}
		
		cout<<"NO"<<endl;
		done:;
	}
}
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
int arr[100005];
deque<int> dq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		dq.clear();
		
		cin>>n;
	
		if (n==1){
			cout<<"0\n1\n0\n"<<endl;
			continue;
		}
	
		ll val=0;
		vector<ii> ans;
		
		rep(x,1,n+1) arr[x]=x;
		
		val+=(ll)(n-1)*(n-1);
		swap(arr[1],arr[n]);
		ans.push_back(ii(1,n));
	
		if (n>2) rep(x,2,n){
			if (x-1>n-x){
				val+=(ll)(x-1)*(x-1);
				swap(arr[1],arr[x]);
				ans.push_back(ii(x,1));
			}
			else{
				val+=(ll)(n-x)*(n-x);
				swap(arr[n],arr[x]);
				ans.push_back(ii(x,n));
			}
		}
		
		cout<<val<<endl;
		rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
		cout<<sz(ans)<<endl;
		reverse(all(ans));
		for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
		cout<<endl;
		
		for (auto &it:ans){
			assert(arr[it.se]==it.fi);
			swap(arr[it.fi],arr[it.se]);
		}
	}
}
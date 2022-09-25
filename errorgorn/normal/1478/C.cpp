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

ll n;
ll arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		vector<ll> val;
		
		cin>>n;
		rep(x,0,2*n) cin>>arr[x];
		
		map<ll,int> cnt;
		
		rep(x,0,2*n){
			cnt[arr[x]]++;
			
			if (cnt[arr[x]]==2){
				cnt[arr[x]]=0;
				val.pub(arr[x]);
			}
		}
		
		if (sz(val)!=n){
			cout<<"NO"<<endl;
			continue;
		}
		
		sort(all(val));
		
		ll tot=0;
		ll tot2=0;
		rep(x,1,n){
			if (val[x]-val[x-1]==0 || (val[x]-val[x-1])%(2*x)!=0){
				cout<<"NO"<<endl;
				goto done;
			}
			tot+=(val[x]-val[x-1])/(2*x);
			tot2+=tot;
		}
		
		//cout<<val[0]-tot2*2<<endl;
		if (tot2*2<val[0] && (val[0]-tot2*2)%(2*n)==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
		done:;
	}
}
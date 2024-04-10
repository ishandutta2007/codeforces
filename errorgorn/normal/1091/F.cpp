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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
ll arr[100005];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	cin>>s;
	
	bool W=false; //is there water to spam?
	ll ans=0;
	ll sta1=0; //decrease to save 1 time
	ll sta2=0; //decrease to save 2 time
	
	ll temp;
	rep(x,0,n){
		if (s[x]=='L'){
			ans+=arr[x];
			
			temp=min(sta1,arr[x]);
			sta1-=temp,arr[x]-=temp;
			temp=min(sta2,arr[x]);
			sta2-=temp,arr[x]-=temp;
			
			if (W) ans+=arr[x]*3;
			else ans+=arr[x]*5;
		}
		else if (s[x]=='W'){
			sta1+=arr[x];
			ans+=arr[x]*3;
			W=true;
		}
		else{
			sta2+=arr[x];
			temp=min(arr[x],sta1);
			sta1-=temp,sta2+=temp;
			ans+=arr[x]*5;
		}
	}
	
	ans-=sta1;
	ans-=sta2*2;
	
	cout<<ans<<endl;
}
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
 
#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
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
 
 
int n;
 
int ask(int i){
	if (i==0) return 0;
	cout<<"? "<<i<<endl;
	int temp;
	cin>>temp;
	return temp;
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int lo=0,hi=5e6,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (ask(mi)==1) hi=mi;
		else lo=mi;
	}
	
	int ans=1e9;
	rep(x,1,n+1){
		int temp=ask(hi/x);
		if (temp) ans=min(ans,temp*(hi/x));
	}
	
	cout<<"! "<<ans<<endl;
}
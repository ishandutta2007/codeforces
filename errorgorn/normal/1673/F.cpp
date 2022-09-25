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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
int ham[32];
int arr[32][32];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	ham[0]=0;
	rep(x,1,32) ham[x]=ham[x-1]^(1<<(2*__builtin_ctz(x)));
	
	rep(x,0,32) rep(y,0,32) arr[x][y]=ham[x]<<1|ham[y];
	
	cin>>n>>q;
	
	rep(x,0,n){
		rep(y,0,n-1) cout<<(arr[x][y]^arr[x][y+1])<<" "; cout<<endl;
	}
	rep(x,0,n-1){
		rep(y,0,n) cout<<(arr[x][y]^arr[x+1][y])<<" "; cout<<endl;
	}
	
	int px=0,py=0;
	rep(x,0,q){
		int val;
		cin>>val;
		
		rep(x,0,n) rep(y,0,n){
			if ((arr[x][y]^arr[px][py])==val){
				px=x,py=y;
				goto done;
			}
		}
		
		done:;
		cout<<px+1<<" "<<py+1<<endl;
	}
}
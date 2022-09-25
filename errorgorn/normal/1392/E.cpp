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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
ll arr[30][30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,30){
		if (x%2==0) continue;
		
		int curr=(x/2)*2;
		rep(y,0,30){
			arr[x][y]=1LL<<curr;
			curr++;
		}
	}
	
	rep(x,0,n){
		rep(y,0,n) cout<<arr[x][y]<<" ";
		cout<<endl;
	}
	
	cin>>q;
	while (q--){
		ll val;
		cin>>val;
		
		int px=0,py=0;
		while (px!=n-1 || py!=n-1){
			cout<<px+1<<" "<<py+1<<endl;
			
			if (px==n-1) py++;
			else if (py==n-1) px++;
			else{
				if (px%2==1){
					if (val&arr[px][py+1]) py++;
					else px++;
				}
				else{
				 	if (val&arr[px+1][py]) px++;
					else py++;
				}
			}
		}
		cout<<px+1<<" "<<py+1<<endl;
	}
}
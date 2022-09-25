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

int n,l;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>l;
		rep(x,0,n) cin>>arr[x];
		
		double da=0,db=l;
		double va=1,vb=1;
		int ia=0,ib=n-1;
		double t=0;
		
		while (ia<=ib){
			if ((arr[ia]-da)/va<=(db-arr[ib])/vb){
				double dt=(arr[ia]-da)/va;
				t+=dt;
				da+=va*dt;
				db-=vb*dt;
				
				ia++;
				va++;
			}
			else{
				double dt=(db-arr[ib])/vb;
				t+=dt;
				da+=va*dt;
				db-=vb*dt;
				
				ib--;
				vb++;
			}
			//cout<<da<<" "<<db<<" "<<t<<endl;
		}
		
		t+=(db-da)/(va+vb);
		cout<<fixed<<setprecision(12)<<t<<endl;
	}
}
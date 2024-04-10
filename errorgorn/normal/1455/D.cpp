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

int n,k;
int arr[505];
int memo[505][505][505]; //pos, prev, K

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		rep(x,0,n) cin>>arr[x];
		
		vector<int> uni={k};
		rep(x,0,n) uni.push_back(arr[x]);
		
		sort(all(uni));
		uni.erase(unique(all(uni)),uni.end());
		
		map<int,int> id;
		rep(x,0,sz(uni)) id[uni[x]]=x+1;
		rep(x,0,n) arr[x]=id[arr[x]];
		k=id[k];
		
		//rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
		
		rep(x,0,n+1) rep(y,0,n+2) rep(z,0,n+2){
			memo[x][y][z]=1e9;
		}
		
		memo[0][0][k]=0;
		rep(x,0,n) rep(y,0,n+2) rep(z,0,n+2){
			if (y<=arr[x]){
				memo[x+1][arr[x]][z]=min(memo[x+1][arr[x]][z],memo[x][y][z]);
			}
			if (y<=z && z<arr[x]){
				memo[x+1][z][arr[x]]=min(memo[x+1][z][arr[x]],memo[x][y][z]+1);
			}
		}
		
		int ans=1e9;
		rep(x,0,n+2) rep(y,0,n+2) ans=min(ans,memo[n][x][y]);
		
		if (ans==1e9) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}
// Super Idol
//    
//  
//    
//  105C
// 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int n,m;
string s[1000005];
int arr[3][1000005];

int memo[8];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>s[x];
	
	if (n<=3){
		rep(x,0,n) rep(y,0,m) arr[x][y]=s[x][y]-'0';
	}
	else{
		cout<<"-1"<<endl;
		return 0;
	}
	
	rep(x,0,m){
		int temp[8];
		rep(y,0,8) temp[y]=1e9;
		
		rep(y1,0,(1<<n)) rep(y2,0,(1<<n)){
			bool can=true;
			rep(z,0,n-1)
				if (__builtin_parity((y1|(y2<<3))&(27<<z))==0) can=false;
				
			if (can){
				int cost=0;
				rep(z,0,n) if ((!!(y2&(1<<z))) != arr[z][x]) cost++;
				//cout<<x<<" "<<y2<<" "<<cost<<endl;
				temp[y2]=min(temp[y2],memo[y1]+cost);
			}
		}
		
		swap(memo,temp);
		
		//rep(x,0,8) cout<<memo[x]<<" "; cout<<endl;
	}
	
	int ans=1e9;
	rep(x,0,8) ans=min(ans,memo[x]);
	
	cout<<ans<<endl;
}
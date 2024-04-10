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

int n;
string s;

int memo[100005][2];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s;
		
		int ans=0;
		rep(x,0,n/2){
			ans+=s[x*2]!=s[x*2+1];
		}
		
		rep(x,0,n/2){
			memo[x][0]=memo[x][1]=1e9;
			
			if (s[x*2]=='0' || s[x*2+1]=='0'){
				if (x==0) memo[x][0]=1;
				else memo[x][0]=min(memo[x-1][0],memo[x-1][1]+1);
			}
			if (s[x*2]=='1' || s[x*2+1]=='1'){
				if (x==0) memo[x][1]=1;
				else memo[x][1]=min(memo[x-1][1],memo[x-1][0]+1);
			}
		}
		
		cout<<ans<<" "<<min(memo[n/2-1][0],memo[n/2-1][1])<<endl;
	}
}
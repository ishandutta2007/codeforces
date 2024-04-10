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

const int MOD=998244353;

int n;
char ch[505];
int arr[505];

int memo[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n){
		cin>>ch[x];
		if (ch[x]=='+') cin>>arr[x];
	}
	
	ll ans=0;
	
	rep(i,0,n) if (ch[i]=='+'){
		memset(memo,0,sizeof(memo));
		
		memo[0][0]=1;
		rep(x,0,n){
			if (ch[x]=='+'){
				if (ii(arr[x],x)<ii(arr[i],i)){
					rep(y,0,504){
						memo[x+1][y]=(memo[x+1][y]+memo[x][y])%MOD;
						memo[x+1][y+1]=(memo[x+1][y+1]+memo[x][y])%MOD;
					}
				}
				else{
					rep(y,0,505) memo[x+1][y]=memo[x][y];
					if (x!=i) rep(y,0,505) memo[x+1][y]=(memo[x+1][y]+memo[x][y])%MOD;
				}
			}
			else{
				rep(y,0,505){
					memo[x+1][y]=(memo[x+1][y]+memo[x][y])%MOD;
					if (y) memo[x+1][y-1]=(memo[x+1][y-1]+memo[x][y])%MOD;
					else if (x<i) memo[x+1][y]=(memo[x+1][y]+memo[x][y])%MOD;
				}
			}
			
			//cout<<memo[x+1][0]<<" "<<memo[x+1][1]<<endl;
		}
		
		ll cnt=0;
		rep(x,0,505) cnt=(cnt+memo[n][x])%MOD;
		//cout<<cnt<<endl;
		
		ans=(ans+cnt*arr[i])%MOD;
	}
	
	cout<<ans<<endl;
}
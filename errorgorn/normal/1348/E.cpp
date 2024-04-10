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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

ll n,k;
bool memo[2][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	memo[0][0]=true;
	
	ll total=0;
	ll i,j;
	
	int a=0,b=1;
	
	rep(x,0,n){
		memset(memo[b],false,sizeof(memo[b]));
		
		cin>>i>>j;
		total+=i+j;
		
		rep(x,0,min(k,j+1)){
			ll val=(i+j-x)%k;
			if (val>i) continue;
			
			//cout<<val<<" "<<x<<endl;
			
			rep(x,0,k) if (memo[a][x]){
				memo[b][(x+val)%k]=true;
			}
		}
		
		swap(a,b);
	}
	
	ll ans=0;
	
	rep(x,0,k) if (memo[a][x]){
		//cout<<x<<endl;
		ans=max(ans,(total-x)/k);
	}
	
	cout<<ans<<endl;
}
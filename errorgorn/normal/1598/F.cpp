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

int n;
string s[20];

int below[20];
int delta[20];
int cnt[20][400005];

int memo[(1<<20)+5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>s[x];
	
	rep(x,0,n){
		int curr=0;
		
		for (auto &it:s[x]){
			if (it=='(') curr++;
			else curr--;
			
			below[x]=min(below[x],curr);
			if (below[x]==curr) cnt[x][-curr]++;
		}
		
		delta[x]=curr;
	}
	
	memset(memo,-1,sizeof(memo));
	
	int ans=0;
	
	memo[0]=0;
	rep(x,0,1<<n) if (memo[x]!=-1){
		int curr=0;
		rep(y,0,n) if (x&(1<<y)) curr+=delta[y];
		
		rep(y,0,n) if ((x&(1<<y))==0){
			ans=max(ans,memo[x]+cnt[y][curr]);
			if (curr+below[y]>=0){
				memo[x|(1<<y)]=max(memo[x|(1<<y)],memo[x]+cnt[y][curr]);
			}
		}
	}
	
	cout<<ans<<endl;
}
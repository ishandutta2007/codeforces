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

int n,k;
string s;

int nxt[200005][17];
int memo[140005];

bool can(int i){
	//cout<<"bruh: "<<i<<endl;
	
	memset(nxt,63,sizeof(nxt));
	
	rep(x,0,k){
		int curr=0;
		rep(y,0,n){
			if (s[y]!=('a'+x) && s[y]!='?') curr=y+1;
			if (curr<=y-i+1) nxt[y-i+1][x]=curr;
		}
		rep(y,n,0) nxt[y][x]=min(nxt[y][x],nxt[y+1][x]);
		
		//cout<<x<<": "; rep(y,0,n) cout<<nxt[y][x]<<" "; cout<<endl;
	}
	
	memset(memo,63,sizeof(memo));
	memo[0]=0;
	
	rep(x,0,1<<k){
		//cout<<x<<" "<<memo[x]<<endl;
		if (memo[x]>n) continue;
		rep(y,0,k) if ((x&(1<<y))==0){
			memo[x|(1<<y)]=min(memo[x|(1<<y)],max(nxt[memo[x]][y],memo[x])+i);
		}
	}
	
	return memo[(1<<k)-1]<=n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	cin>>s;
	
	int lo=0,hi=1e6,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) lo=mi;
		else hi=mi;
	}
	
	cout<<lo<<endl;
}
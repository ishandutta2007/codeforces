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

int n,m,p;
string s[200005];

int memo[33000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>p;
	rep(x,0,n) cin>>s[x];
	
	vector<int> proc;
	rep(x,0,n) proc.pub(x);
	rep(x,0,n) swap(proc[x],proc[rng()%(x+1)]);
	
	ll ans=0;
	
	rep(i,0,min(n,40)){
		memset(memo,0,sizeof(memo));
		
		vector<int> idx;
		rep(x,0,m) if (s[proc[i]][x]=='1') idx.pub(x);
		
		rep(x,0,n){
			int curr=(1<<sz(idx))-1;
			rep(y,0,sz(idx)) if (s[x][idx[y]]=='1') curr^=(1<<y);
			memo[curr]++;
		}
		
		rep(y,0,sz(idx)) rep(x,0,1<<sz(idx)){
			if ((x&(1<<y))==0) memo[x^(1<<y)]+=memo[x];
		}
		
		int best=0;
		//rep(x,0,1<<sz(idx)) cout<<memo[x]<<" "; cout<<endl;
		
		rep(x,0,1<<sz(idx)) if (memo[x]>=(n+1)/2){
			int val=((1<<sz(idx))-1)^x;
			if (__builtin_popcount(val)>__builtin_popcount(best)) best=val;
		}
		
		ll curr=0;
		rep(x,0,sz(idx)) if (best&(1<<x)) curr|=(1LL<<idx[x]);
		
		if (__builtin_popcountll(curr)>__builtin_popcountll(ans)) ans=curr;
	}
	
	rep(x,0,m){
		if (ans&(1LL<<x)) cout<<"1";
		else cout<<"0";
	}
}
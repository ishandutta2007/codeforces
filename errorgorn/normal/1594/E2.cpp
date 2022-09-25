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

const int MOD=1000000007;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

map<string,int> col={
	{"white",0},
	{"yellow",1},
	{"red",2},
	{"orange",3},
	{"green",4},
	{"blue",5}
};

int trans[6][6]={
	{0,0,1,1,1,1},
	{0,0,1,1,1,1},
	{1,1,0,0,1,1},
	{1,1,0,0,1,1},
	{1,1,1,1,0,0},
	{1,1,1,1,0,0}
};

ll n,m;
map<ll,ll> val;
set<ll> impt;
map<ii,ll> memo;

ll dfs(ll i,int c){
	//cerr<<i<<" "<<c<<endl;
	
	if (val.count(i) && val[i]!=c) return 0;
	if (i>=n/2) return 1;
	if (!impt.count(i)){
		//cerr<<"d: "<<i<<" "<<__builtin_clzll(n)-__builtin_clzll(i)<<endl;
		return qexp(4,qexp(2,__builtin_clzll(i)-__builtin_clzll(n),MOD-1)-2,MOD);
	}
	if (memo.count(ii(i,c))) return memo[ii(i,c)];
	
	ll l=0,r=0;
	rep(x,0,6) if (trans[c][x]){
		l=(l+dfs(i<<1,x))%MOD;
		r=(r+dfs(i<<1|1,x))%MOD;
	}
	
	return memo[ii(i,c)]=l*r%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	n=1LL<<n;
	
	ll a; string b;
	rep(x,0,m){
		cin>>a>>b;
		
		val[a]=col[b];
	
		while (a){
			impt.insert(a);
			a>>=1;
		}
	}
	
	ll ans=0;
	rep(x,0,6) ans=(ans+dfs(1,x))%MOD;
	
	cout<<ans<<endl;
}
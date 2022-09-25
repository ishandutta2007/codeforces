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

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

int n,k;

int memo[405][405][205];
int iinv[405];

//relative factorials
ll fac[405];
ll ifac[405]; 

int dp(int i,int j,int k){ 
	//i=num we need to take
	//j=size of cycle
	//k=num of moves
	
	if (j>=205) return 0;
	if (k<0) return 0;
	if (i-k<0) return 0;
	if (i==0) return k==0;
	if (memo[i][j][k]!=-1) return memo[i][j][k];
	
	ll res=0;
	ll mul=ifac[i];
	
	rep(x,0,405){
		if (x*j>i) break;
		res=(res+dp(i-x*j,j+1,k-x*(j-1))*fac[i-x*j]%MOD
				*mul%MOD)%MOD;
		mul=mul*iinv[j]%MOD*iinv[x+1]%MOD;
	}
	
	return memo[i][j][k]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	iinv[0]=1;
	rep(x,1,405) iinv[x]=inv(x);
	
	cin>>n>>k;
	
	fac[404]=1;
	rep(x,404,0){
		fac[x]=fac[x+1]*(n-x)%MOD;
		if (x==n) fac[x]=1;
	}
	rep(x,0,405) ifac[x]=inv(fac[x]);
	
	memset(memo,-1,sizeof(memo));
	
	ll a=0,b=1;
	
	rep(x,1,k+1){
		rep(y,0,min(400,n)+1) a=(a+dp(y,2,x))%MOD;
		
		cout<<a<<" ";
		swap(a,b);
	}
}
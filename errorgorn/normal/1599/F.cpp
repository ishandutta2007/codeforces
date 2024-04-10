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

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

int n,q;
ll arr[200005];

const int S=7;
ll parr[S][200005];

ll powsum[S][200005];

int powa[S];
int powd[S];

int nCk[S][S];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	nCk[0][0]=1;
	rep(x,1,S){
		nCk[x][0]=1;
		rep(y,1,x+1) nCk[x][y]=(nCk[x-1][y-1]+nCk[x-1][y])%MOD;
	}
	
	rep(x,0,200005){
		powsum[0][x]=1;
		rep(y,1,S) powsum[y][x]=powsum[y-1][x]*x%MOD;
		if (x){
			rep(y,0,S) powsum[y][x]=(powsum[y][x]+powsum[y][x-1])%MOD;
		}
	}
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1){
		parr[0][x]=1;
		rep(y,1,S) parr[y][x]=parr[y-1][x]*arr[x]%MOD;
		rep(y,0,S) parr[y][x]=(parr[y][x]+parr[y][x-1])%MOD;
	}
	
	ll l,r,d;
	while (q--){
		cin>>l>>r>>d;
		
		ll temp=(parr[1][r]-parr[1][l-1]+MOD)%MOD;
		
		//cout<<temp<<endl;
		ll a=fix(temp-powsum[1][r-l]*d)*inv(r-l+1)%MOD;
		//cout<<a<<" "<<d<<endl;
		
		powa[0]=powd[0]=1;
		rep(x,0,S-1) powa[x+1]=powa[x]*a%MOD,powd[x+1]=powd[x]*d%MOD;
		
		bool can=true;
		rep(x,2,S){
			ll temp=0;
			rep(y,0,x+1){
				temp=(temp+powsum[y][r-l]*nCk[x][y]%MOD*powa[x-y]%MOD*powd[y])%MOD;
			}
			
			if (temp!=(parr[x][r]-parr[x][l-1]+MOD)%MOD) can=false;
			//cout<<temp<<" "<<(parr[x][r]-parr[x][l-1]+MOD)%MOD<<endl;
		}
		
		if (can) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
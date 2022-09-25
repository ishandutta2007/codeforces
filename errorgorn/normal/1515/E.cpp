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

int n,MOD;

ll nCk[405][405];

ll num[405];
ll memo[405][405];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>MOD;
	
	nCk[0][0]=1;
	rep(x,1,405){
		nCk[x][0]=1;
		rep(y,1,x+1) nCk[x][y]=(nCk[x-1][y-1]+nCk[x-1][y])%MOD;
	}
	
	num[1]=1;
	rep(x,2,402) num[x]=num[x-1]*2%MOD;
	
	memo[0][0]=1;
	
	rep(x,0,402) rep(y,0,402) rep(z,0,402){
		if (x+z+1<402 && y+z<402){
			memo[x+z+1][y+z]=(memo[x+z+1][y+z]+memo[x][y]*nCk[y+z][z]%MOD*num[z])%MOD;
		}
	}
	
	ll ans=0;
	rep(x,0,402) ans=(ans+memo[n+1][x])%MOD;
	
	cout<<ans<<endl;
}
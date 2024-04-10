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

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n,m;
string s;
string t;

int pi[505][2];

int memo[505][505][505]; //len,curr,num

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>m;
	cin>>s>>t;
	
	rep(x,0,m+1){
		rep(y,0,2){
			string temp;
			if (y==0) temp=t.substr(0,x)+"0";
			else temp=t.substr(0,x)+"1";
			
			rep(z,1,n+1) if (sz(temp)>=z){
				if (temp.substr(x+1-z,z)==t.substr(0,z)) pi[x][y]=z;
			}
		}
	}
	
	memset(memo,63,sizeof(memo));
	
	memo[0][0][0]=0;
	rep(x,0,n) rep(y,0,m+1) rep(z,0,504){
		rep(t,0,2){
			int temp=z;
			int cost=0;
			if (pi[y][t]==m) temp++;
			if (s[x]-'0'!=t) cost++;
			
			memo[x+1][pi[y][t]][temp]=min(memo[x+1][pi[y][t]][temp],memo[x][y][z]+cost);
		}
	}
	
	rep(x,0,n-m+2){
		int ans=1e9;
		rep(y,0,m+1) ans=min(ans,memo[n][y][x]);
		
		if (ans==1e9) cout<<"-1"<<" ";
		else cout<<ans<<" ";
	}
}
// Super Idol
//    
//  
//    
//  105C
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

ll n,k;
ii arr[2005];

ll memo[2][2005][2005];
ll temp[2005][2005];

#define add(a,b) a=fix(a+b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>arr[x].fi;
	rep(x,1,n+1) arr[x]={max(arr[x].fi-k,0LL),min(arr[x].fi+k,n)};
	
	//rep(x,0,n+1) cout<<arr[x].fi<<" "<<arr[x].se<<endl;
	
	int a=0,b=1;
	memo[a][0][0]=1;
	
	rep(x,0,n){
		rep(y,arr[x+1].fi,arr[x+1].se+1) rep(z,0,2001) memo[b][y][z]=0;
		
		rep(y1,arr[x].fi,arr[x].se+1) rep(z,0,2001) if (memo[a][y1][z]){
			if (arr[x+1].fi<=y1 && y1<=arr[x+1].se+1){
				int above=n-y1;
				int below=y1;
				
				add(memo[b][y1][z+1],memo[a][y1][z]);
				add(memo[b][y1][z],memo[a][y1][z]*z);
				add(memo[b][y1][z],memo[a][y1][z]*below);
			}
		}
		
		rep(y1,arr[x].fi,arr[x].se+1) rep(z,0,2001){
			temp[y1][z]=memo[a][y1][z]*fac[z]%MOD;
			if (arr[x].fi<y1) add(temp[y1][z],temp[y1-1][z+1]);
		}
			
		rep(y2,arr[x+1].fi,arr[x+1].se+1) rep(z,0,2001){
			int y1=y2-1,z1=z;
			if (arr[x].se<y1){
				z1+=y1-arr[x].se;
				y1=arr[x].se;
			}
			
			if (arr[x].fi<=y1 && z1<=2000)
				add(memo[b][y2][z],temp[y1][z1]*ifac[z]);
		}
		
		swap(a,b);
	}
	
	ll ans=0;
	rep(y,arr[n].fi,arr[n].se+1) rep(z,0,2001) if (memo[a][y][z]){
		// cout<<y<<" "<<z<<" "<<memo[a][y][z]<<endl;
		// cout<<memo[a][y][z]*fac[z]%MOD*nCk(n-y,z)%MOD<<endl;
		
		add(ans,memo[a][y][z]*fac[z]%MOD*nCk(n-y,z));
	}
	
	cout<<ans<<endl;
}
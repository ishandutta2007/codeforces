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

const int MOD=998244353;

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll memoC[2005][2005];
ll C(ll i,ll j){
	if (memoC[i][j]!=-1) return memoC[i][j];
	if (i<j) return memoC[i][j]=0;
	if (j==0) return memoC[i][j]=1;
	
	return memoC[i][j]=(C(i-1,j)+C(i-1,j-1))%MOD;
}

int n,k;
int arr[2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(memoC,-1,sizeof(memoC));
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	int same=0;
	rep(x,0,n) if (arr[x]==arr[(x+1)%n]) same++;
	n-=same;
	
	ll ans=0;
	
	rep(x,0,2005){
		rep(y,0,x){
			if (x+y<=n){
				(ans+=(C(n,x)*C(n-x,y)%MOD)*qexp(k-2,n-x-y,MOD))%=MOD;
				//cout<<x<<" "<<y<<endl;
				//cout<<(C(n,x)*C(n-x,y))%MOD*qexp(k-2,n-x-y,MOD)<<endl;
			}
		}
	}
	
	(ans*=qexp(k,same,MOD))%=MOD;
	
	cout<<ans<<endl;
}
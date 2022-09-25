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

const int MOD=1000000007;

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll fac[1000005];
ll ifac[1000005];

ll C(int i,int j){
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n;
vector<int> v;
int arr[35];

ll calc(){
	memset(arr,0,sizeof(arr));
	
	rep(x,1,n+1){
		rep(y,0,sz(v)) if (x%v[y]==0){
			arr[y]++;
			break;
		}
	}
	
	int curr=n;
	ll res=1;
	
	rep(x,0,sz(v)){
		res=res*fac[arr[x]]%MOD*C(curr-1,arr[x]-1)%MOD;
		curr-=arr[x];
	}
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=(fac[x-1]*x)%MOD;
	rep(x,0,1000005) ifac[x]=qexp(fac[x],MOD-2,MOD);
	
	cin>>n;
	
	int tk=1<<(31-__builtin_clz(n));
	
	v.push_back(tk);
	while (v.back()!=1){
		v.push_back(v.back()/2);
	}
	
	ll ans=0;
	ans=(ans+calc())%MOD;
	
	if (tk/2*3<=n){
		rep(x,0,sz(v)-1){
			v[x]=v[x]/2*3;
			ans=(ans+calc())%MOD;
		}
	}
	
	cout<<ans<<endl;
}
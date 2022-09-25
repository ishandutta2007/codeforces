#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


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
const int disc_root=3;


long long qexp(long long b,long long p,int m){
    long long res=1;
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

ll pos(ll i){
	while (i<0) i+=MOD;
	while (MOD<=i) i-=MOD;
	
	return i;
}

ll fac[200005];
ll ifac[200005];

ll C(int i,int j){
	return fac[i]*ifac[i-j]%MOD*ifac[j]%MOD;
}

long long NTT_coeff[2][20];
void NTT(vector<long long> &v, bool flag){
    if (v.size()==1) return;
    vector<long long> even;
    vector<long long> odd;
    even.reserve((v.size())>>1),odd.reserve((v.size())>>1);
    for (int x=0;x<v.size();x++){
        if (x&1) odd.push_back(v[x]);
        else even.push_back(v[x]);
    }
    NTT(even,flag);
    NTT(odd,flag);
    
    long long w=1,wn;
    if (flag) wn=NTT_coeff[0][__builtin_ctz(v.size())];
    else wn=NTT_coeff[1][__builtin_ctz(v.size())];
    for (int x=0;x<(v.size()>>1);x++){
        v[x]=(even[x]+w*odd[x])%MOD;
        w=(w*wn)%MOD;
    }
    for (int x=0;x<(v.size()>>1);x++){
        v[x+(v.size()>>1)]=(even[x]+w*odd[x])%MOD;
        w=(w*wn)%MOD;
    }
}

vector<long long> mul(vector<long long> pa, vector<long long> pb){
    int length=1<<(32-__builtin_clz(pa.size()+pb.size()-2));
    pa.insert(pa.end(),length-pa.size(),0);
    pb.insert(pb.end(),length-pb.size(),0);
    
    vector<long long> pc;
    NTT(pa,true);
    NTT(pb,true);

    int __inv=inv(length);
    for (int x=0;x<length;x++){
        pc.push_back((pa[x]*pb[x]%MOD)*__inv%MOD);
    }
    NTT(pc,false);
    return pc;
}

int n,k;
int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int x=0;x<20;x++){ ///precomp stuff
    	NTT_coeff[0][x]=qexp(disc_root,(MOD-1)>>x,MOD);
    	NTT_coeff[1][x]=inv(NTT_coeff[0][x]);
	}	
	fac[0]=1;
	rep(x,1,200005) fac[x]=(fac[x-1]*x)%MOD;
	rep(x,0,200005) ifac[x]=inv(fac[x]);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	int same=0;
	rep(x,0,n) if (arr[x]==arr[(x+1)%n]) same++;
	n-=same;
	
	ll ans=0;
	
	if (k==2){ //fucking hell
		rep(x,n/2+1,n+1){
			ans=(ans+C(n,x))%MOD;
		}
		
		ans=ans*qexp(k,same,MOD)%MOD;
		
		cout<<ans<<endl;
		return 0;
	}
	
	
	vector<ll> poly;
	rep(x,0,n+1) poly.push_back(inv(qexp(k-2,x,MOD))*ifac[x]%MOD);
	poly=mul(poly,poly);
	
	rep(x,0,n+1){
		ans=(ans+poly[x]*ifac[n-x])%MOD;
	}
	
	ans=ans*qexp(k-2,n,MOD)%MOD*fac[n]%MOD;
	
	rep(x,0,200005) if (x+x<=n){
		ans=pos(ans-C(n,x)*C(n-x,x)%MOD*qexp(k-2,n-x-x,MOD)%MOD);
	}
	
	ans=ans*qexp(k,same,MOD)%MOD*inv(2)%MOD;
	
	cout<<ans<<endl;
}
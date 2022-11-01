#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif


ll summ(ll a, ll b){return (a+b)%MOD;}

//The segement tree itself.
struct seg
{
    ll val[800001];
    ll def=0;
    ll (*merg)(ll,ll) = summ; // Merge function. It must be associative.
    void reset(ll c, ll l, ll r)
    {
        if (l<r)
        {
            ll mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
            val[c]=merg(val[(c<<1)],val[(c<<1)+1]);
        }
        else val[c]=def;
    }
    void upd(ll c, ll l, ll r, ll x, ll t)
    {
        if ((l<=x)and(x<=r))
        {
            if (l==r) val[c]=t;
            else
            {
                ll mid=(l+r)/2;
                upd((c<<1),l,mid,x,t);
                upd((c<<1)+1,mid+1,r,x,t);
                val[c]=merg(val[(c<<1)],val[(c<<1)+1]);
            }
        }
    }
    ll get(ll c, ll l, ll r, ll tl, ll tr)
    {
        if ((tl>r)or(tr<l)) return def;
        if ((tl<=l)and(tr>=r)) return val[c];
        else 
        {
            ll mid=(l+r)/2;
            ll a=get((c<<1),l,mid,tl,tr);
            ll b=get((c<<1)+1,mid+1,r,tl,tr);
            return merg(a,b);
        }
    }
};
seg stc,sts;

ll n,m,i,j,k,t,t1,u,v,a,b,res;
ll arr[200001];
ll dpc[200001];
ll dps[200001];
ll dp2[200001];
vector<ll> vec,vec2;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++) {
		cin>>n;
		vec.clear();
		for (i=1;i<=n;i++) {
			cin>>arr[i];
			vec.push_back(i);
		}
		sort(vec.begin(),vec.end(),[](ll a, ll b){
			if (arr[a]-arr[b]) return (arr[a]<arr[b]);
			return (a>b);
		});
		for (i=0;i<n;i++) arr[vec[i]]=i+1;
		stc.reset(1,1,n);
		sts.reset(1,1,n);
		res=0;
		for (i=1;i<=n;i++) {
			dpc[i]=stc.get(1,1,n,1,arr[i]-1);
			dpc[i]++;
			dps[i]=sts.get(1,1,n,1,arr[i]-1);
			dps[i]+=dpc[i];
			dps[i]%=MOD;
			dpc[i]%=MOD;
			stc.upd(1,1,n,arr[i],dpc[i]);
			sts.upd(1,1,n,arr[i],dps[i]);
			res+=dps[i];
		}
		// cout<<res<<endl;
		j=0;
		for (i=1;i<=n;i++){
			dps[i]=dpc[i];
			dpc[i]=0;
			// cout<<i<<' '<<dps[i]<<endl;
		}
		stc.reset(1,1,n);
		for (i=n;i>=1;i--) if (arr[i]>j) {
			vec2.clear();
			for (k=j;k<arr[i];k++) vec2.push_back(vec[k]);
			j=arr[i];
			sort(vec2.begin(),vec2.end(),greater<ll>());
			for (auto g : vec2) {
				// cout<<g<<' ';
				dpc[g]=stc.get(1,1,n,arr[g]+1,n);
				if (g==i) dpc[g]++;
				// cout<<dpc[g]<<' '<<dps[g]<<endl;
				res-=(dpc[g]*dps[g])%MOD;

				dpc[g]%=MOD;
				stc.upd(1,1,n,arr[g],dpc[g]);
			}
			for (auto g : vec2) {
				stc.upd(1,1,n,arr[i],0);
			}
		}
		res%=MOD;
		res+=MOD;
		res%=MOD;
		cout<<res<<endl;
	}
}
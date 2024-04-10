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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

// Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }

// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
//Constants.
#define MOD (ll(998244353))
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
vector<int> gt[300001];
ll res,n,m,i,j,k,t,t1,u,v,a,b;
vector<int> buc[300001];
vector<int> cnts;
int occ[300001],ban[300001];
map<int,int> used;
vector<int> vals;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++) {
		cin>>n>>m;
		res=0;
		for (i=0;i<=n;i++) {
			gt[i].clear();
			buc[i].clear();
			occ[i]=0;
		}
		used.clear();
		cnts.clear();
		vals.clear();
		for (i=1;i<=n;i++) {
			cin>>u;
			if (!used[u]) {
				vals.push_back(u);
				used[u]=vals.size();
			}
			occ[used[u]]++;
		}
		k=vals.size();
		vals.insert(vals.begin(),0);
		for (i=1;i<=m;i++) {
			cin>>a>>b;
			a=used[a];
			b=used[b];
			gt[a].push_back(b);
			gt[b].push_back(a);
		}
		for (i=1;i<=k;i++) gt[i].push_back(i);
		for (i=1;i<=k;i++) {
			buc[occ[i]].push_back(i);
		}
		for (i=1;i<=n;i++) if (buc[i].size()) {
			cnts.push_back(i);
			sort(buc[i].begin(),buc[i].end(),[](int a, int b){
				return (vals[a]>vals[b]);
			});
		}
		for (i=1;i<=k;i++) {
			for (auto g : gt[i]) ban[g]=1;
			for (auto g : cnts) {
				for (auto gg : buc[g]) if (!ban[gg]) {
					// cout<<g<<' '<<vals[gg]<<' '<<occ[i]<<' '<<vals[i]<<endl;
					u=vals[gg]+vals[i];
					v=g+occ[i];
					res=max(res,u*v);
                                        break;
				}
			}
			for (auto g : gt[i]) ban[g]=0;
		}
		cout<<res<<endl;
	}
}
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
int sta[200001];
struct seg {
	int val[530001],pos[530001],lz[530001];
	void reset(int c, int l, int r) {
		if (l==r) {
			val[c]=sta[l];
			pos[c]=l;
			lz[c]=0;
		}
		else {
			int mid=(l+r)/2;
			reset((c<<1),l,mid);
			reset((c<<1)+1,mid+1,r);
			if (val[(c<<1)]>val[(c<<1)+1]) {
				pos[c]=pos[(c<<1)];
				val[c]=val[(c<<1)];
			}
			else {
				pos[c]=pos[(c<<1)+1];
				val[c]=val[(c<<1)+1];
			}
		}
	}
	void flush(int c) {
		lz[(c<<1)]+=lz[c];
		lz[(c<<1)+1]+=lz[c];
		val[(c<<1)]+=lz[c];
		val[(c<<1)+1]+=lz[c];
		lz[c]=0;
	}
	void upd(int c, int l, int r, int tl, int tr, int d) {
		if (l>tr || r<tl) return;
		if (l>=tl && r<=tr) {
			val[c]+=d;
			lz[c]+=d;
		}
		else {
			int mid=(l+r)/2;
			flush(c);
			upd((c<<1),l,mid,tl,tr,d);
			upd((c<<1)+1,mid+1,r,tl,tr,d);
			if (val[(c<<1)]>val[(c<<1)+1]) {
				pos[c]=pos[(c<<1)];
				val[c]=val[(c<<1)];
			}
			else {
				pos[c]=pos[(c<<1)+1];
				val[c]=val[(c<<1)+1];
			}
		}
	}
	pii(int) get(int c, int l, int r, int tl, int tr) {
		if (l>tr || r<tl) return {-1e9,-1};
		if (l>=tl && r<=tr) {
			return {val[c],pos[c]};
		}
		else {
			int mid=(l+r)/2;
			flush(c);
			auto a = get((c<<1),l,mid,tl,tr);
			auto b = get((c<<1)+1,mid+1,r,tl,tr);
			if (a.fi>b.fi) {
				return a;
			}
			else {
				return b;
			}
		}
	}
}; seg st;
vector<int> gt[200001];
ll n,m,i,j,k,t,t1,u,v,a,b;
int mx[200001];
int banned[200001];
int tl[200001],tr[200001],par[200001];
int arr[200001];
ll res;
void dfs(int x, int p) {
	// cout<<"dfs "<<x<<' '<<p<<endl;
	t++;
	tl[x]=t;
	// cout<<"tl "<<x<<' '<<tl[x]<<endl;
	arr[t]=x;
	par[x]=p;
	if (p==-1) sta[t]=1; else sta[t]=sta[tl[p]]+1;
	for (auto g : gt[x]) if (g-p) dfs(g,x);
	tr[x]=t;
	// cout<<"tr "<<x<<' '<<tr[x]<<endl;
}
int main()
{
	fio;
	res=-1e18;
	cin>>n>>m;
	for (i=1;i<n;i++) {
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1,-1);
	st.reset(1,1,n);
	for (i=1;i<=m;i++) {
		u = arr[st.pos[1]];
		mx[i]=mx[i-1]+st.val[1];
		while(u!=-1 && !banned[u]) {
			banned[u]=1;
			// cout<<u<<' '<<tl[u]<<' '<<tr[u]<<endl;
			st.upd(1,1,n,tl[u],tr[u],-1);
			u=par[u];
		}
		// cout<<i<<' '<<mx[i]<<endl;
		b = n - mx[i];
		v = mx[i]-i;
		if (i>=b) {
			u = (i-b)*v;
		}
		else {
			a = b-i;
			// cout<<"A "<<a<<' '<<v<<endl;
			// a = available, v = advantage
			if (a>=v) {
				u = - ((a+v)/2 )* ((a+v)- (a+v)/2);
			}
			else {
				u = - a * v;
			}
		}
		res=max(res,u);
	}
	cout<<res;
}
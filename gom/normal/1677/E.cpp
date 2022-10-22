#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//#include <bits/extc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<db,db,db,db> td4;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
ll modinv(ll a,ll m){
	if(m==1) return 0;
	a%=m;
	if(a<0) a+=m;
	if(a==1) return 1;
	return m-modinv(m,a)*m/a;
}
template <int MOD_> struct modnum{
private:
	int v;
public:
	static const int MOD = MOD_;
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
	friend bool operator < (const modnum& a, const modnum& b) { return a.v < b.v; }
	friend bool operator <= (const modnum& a, const modnum& b) { return a.v <= b.v; }
	friend bool operator > (const modnum& a, const modnum& b) { return a.v > b.v; }
	friend bool operator >= (const modnum& a, const modnum& b) { return a.v >= b.v; }
 
	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}
 
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}
 
	modnum operator-() const { return modnum(-v); }
	modnum& operator++() { return *this += 1; }
	modnum operator++(int){ modnum tmp=*this; ++*this; return tmp; }
	modnum& operator--() { return *this -= 1; }
	modnum operator--(int){ modnum tmp=*this; --*this; return tmp; }
 
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
	friend modnum pow(modnum a, ll p) {
		modnum ans = 1;
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend ostream& operator<<(std::ostream& os, const modnum& o)
	{
		os << o.v;
		return os;
	}
	friend istream& operator>>(std::istream& is, modnum& o)
	{
		is >> o.v;
		return is;
	}
};
const ll mod=998244353,inf=9e18;
using mi=modnum<mod>;
const int N=2e5+5,M=1e6+5,Q=1e6+5;
int n,q,p[N],rev[N];
int stk[N],sz,lp[N],rp[N],lp2[N],rp2[N];
vector<int> lg[N],rg[N];
ll ans[M];
vector<tii> rect[N];
vector<tii> query[N];
ll T1[2*N],T2[2*N],L1[2*N],L2[2*N];
void pd(int nd,int l,int r){
	if(!L1[nd]&&!L2[nd]) return;
	T1[nd]+=L1[nd]*(r-l+1);
	T2[nd]+=L2[nd]*(r-l+1);
	if(l!=r){
		int m=(l+r)>>1;
		L1[nd+1]+=L1[nd];
		L2[nd+1]+=L2[nd];
		L1[nd+2*(m-l+1)]+=L1[nd];
		L2[nd+2*(m-l+1)]+=L2[nd];
	}
	L1[nd]=L2[nd]=0;
}
void add(int nd,int l,int r,int s,int e,ll v,ll vs){
	pd(nd,l,r);
	if(r<s||e<l) return;
	if(s<=l&&r<=e){
		L1[nd]+=v;
		L2[nd]+=vs;
		pd(nd,l,r);
		return;
	}
	int m=(l+r)>>1;
	add(nd+1,l,m,s,e,v,vs); add(nd+2*(m-l+1),m+1,r,s,e,v,vs);
	T1[nd]=T1[nd+1]+T1[nd+2*(m-l+1)];
	T2[nd]=T2[nd+1]+T2[nd+2*(m-l+1)];
}
ll qry(int nd,int l,int r,int s,int e,ll x){
	pd(nd,l,r);
	if(r<s||e<l) return 0;
	if(s<=l&&r<=e){
		//cout<<s<<" - "<<e<<": "<<T1[nd]<<" "<<T2[nd]<<endl;
		return T1[nd]*x-T2[nd];
	}
	int m=(l+r)>>1;
	return qry(nd+1,l,m,s,e,x)+qry(nd+2*(m-l+1),m+1,r,s,e,x);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		rev[p[i]]=i;
		while(stk[sz]&&p[stk[sz]]<p[i]){
			rp[stk[sz]]=i-1;
			sz--;
		}
		lp[i]=stk[sz]+1;
		stk[++sz]=i;
	}
	while(sz){
		rp[stk[sz]]=n;
		sz--;
	}
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i){
		if(i<=j/i) continue;
		int x=rev[j],y=rev[i],z=rev[j/i];
		if(y<=x&&lp[x]<=y&&z<=x&&lp[x]<=z){
			if(!lp2[x]) lp2[x]=min(y,z);
			else lp2[x]=max(lp2[x],min(y,z));
		}
		else if(x<=y&&y<=rp[x]&&x<=z&&z<=rp[z]){
			if(!rp2[x]) rp2[x]=max(y,z);
			else rp2[x]=min(rp2[x],max(y,z));
		}
		else if(y<=x&&lp[x]<=y&&x<=z&&z<=rp[x]){
			lg[x].emplace_back(y);
			rg[x].emplace_back(z);
		}
		else if(z<=x&&lp[x]<=z&&x<=y&&y<=rp[x]){
			lg[x].emplace_back(z);
			rg[x].emplace_back(y);
		}
	}	
	for(int i=1;i<=n;i++){
		sort(lg[i].begin(),lg[i].end(),greater<>());
		sort(rg[i].begin(),rg[i].end());
		int e=rp[i];
		if(rp2[i]){
			e=rp2[i];
			if(!lg[i].size()||lg[i][0]!=i){
				int ls=lp[i],le=i;
				int rs=e,re=rp[i];
				if(lg[i].size()) ls=max(ls,lg[i][0]+1);
				if(lp2[i]) ls=max(ls,lp2[i]+1);
				rect[ls].emplace_back(rs,re,1);
				if(le<n) rect[le+1].emplace_back(rs,re,-1);
			}
		}
		for(int j=0;j<lg[i].size();j++){
			if(lp2[i]&&lg[i][j]<=lp2[i]) break;
			if(i<=rev[p[i]/p[lg[i][j]]]) e=min(e,rev[p[i]/p[lg[i][j]]]);
			int ls=lp[i],le=lg[i][j];
			int rs=e,re=rp[i];
			if(j+1<lg[i].size()) ls=max(ls,lg[i][j+1]+1);
			if(lp2[i]) ls=max(ls,lp2[i]+1);
			rect[ls].emplace_back(rs,re,1);
			if(le<n) rect[le+1].emplace_back(rs,re,-1);
			//cout<<i<<": "<<ls<<" - "<<le<<" | "<<rs<<" - "<<re<<endl;
		}
		if(lp2[i]){
			int ls=lp[i],le=lp2[i];
			int rs=i,re=rp[i];
			rect[ls].emplace_back(rs,re,1);
			if(le<n) rect[le+1].emplace_back(rs,re,-1);
			//cout<<i<<": "<<ls<<" - "<<le<<" | "<<rs<<" - "<<re<<endl;
		}
	}
	for(int s,e,i=1;i<=q;i++){
		cin>>s>>e;
		if(s>0) query[s-1].emplace_back(-i,s,e);
		query[e].emplace_back(i,s,e);
	}
	for(int i=1;i<=n;i++){
		for(auto [l,r,v]: rect[i]){
			//cout<<l<<" - "<<r<<" add "<<v<<" "<<v*(i-1)<<endl;
			add(1,1,n,l,r,v,v*(i-1));
		}
		for(auto [idx,s,e]: query[i]){
			if(idx>0) ans[idx]+=qry(1,1,n,s,e,i);
			else ans[-idx]-=qry(1,1,n,s,e,i);
			//cout<<idx<<" -> "<<ans[abs(idx)]<<endl;
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
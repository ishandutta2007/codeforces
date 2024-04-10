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
const int N=2e5+5,M=4e6+5,Q=1e6+5;
int n,k,m,ans;
int a[N],b[N],cnt[N],cnt2[N],s[N];
int f1[N],f2[N];
void add(int x,int v1,int v2){
	for(int i=x;i<=n;i+=i&-i){
		f1[i]+=v1;
		f2[i]+=v2;
	}
}
int qry(int k){
	int s=0,p=0,r=0;
	for(int i=16;i>=0;i--) if(p+(1<<i)<=n&&s+f1[p+(1<<i)]<=k){
		p+=1<<i;
		s+=f1[p];
		r+=f2[p];
	}
	//cout<<"QRY "<<p<<" "<<r<<" "<<s<<" "<<cnt2[p+1]<<endl;
	if(p<n) return r+min(cnt2[p+1],k-s)/(p+1);
	return r;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	ans=n;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++) if(a[i]<=n+1) s[a[i]]=1;
	for(int i=1;i<=n;i++) cnt[lower_bound(b+1,b+1+m,a[i])-b]++;
	s[0]=1-s[0];
	for(int i=1;i<=n+1;i++) s[i]=1-s[i]+s[i-1];
	//for(int i=1;i<=m;i++) cout<<b[i]<<" "<<cnt[i]<<"\n";
	//cout<<"\n";
	for(int i=m+1,v=n+1;v>=0;v--){
		while(i-1>=1&&b[i-1]>v){
			i--;
			cnt2[cnt[i]]+=cnt[i];
			add(cnt[i],cnt[i],1);
		}
		if(i-1>=1&&b[i-1]==v){
			if(cnt[i-1]>k) continue;
			if(v>0){
				if(s[v-1]>k) continue;
				//cout<<v<<" : "<<m+1-i-qry(k-cnt[i-1])<<endl;
				ans=min(ans,m+1-i-qry(k-cnt[i-1]));
			} else{
				int val=qry(k-cnt[i-1]);
				if(val==m+1-i) val--;
				//cout<<v<<" :: "<<m+1-i-val<<endl;
				ans=min(ans,m+1-i-val);
			}
		} else{
			if(v>0){
				if(s[v-1]>k) continue;
				//cout<<v<<" ::: "<<m+1-i-qry(k)<<endl;
				ans=min(ans,m+1-i-qry(k));
			} else{
				int val=qry(k);
				if(val==m+1-i) val--;
				//cout<<v<<" :::: "<<m+1-i-val<<endl;
				ans=min(ans,m+1-i-val);
			}
		}
	}
	for(int i=0;i<=m;i++) cnt[i]=0;
	for(int i=0;i<=n+1;i++) cnt2[i]=s[i]=0;
	for(int i=0;i<=n+10;i++) f1[i]=f2[i]=0;	
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
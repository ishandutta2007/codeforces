#include<bits/stdc++.h>
using namespace std;
#define res int
#define LL long long
#define gc getchar
#define Pair pair<int,int>
#define fi first
#define eb emplace_back
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000000000ll
inline int read(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
template<int kcz>
struct ModInt {
#define T (*this)
	int x;
	ModInt() : x(0) {}
	ModInt(int y) : x(y >= 0 ? y : y + kcz) {}
	ModInt(LL y) : x(y >= 0 ? y % kcz : (kcz - (-y) % kcz) % kcz) {}
	inline int inc(const int &v) {
		return v >= kcz ? v - kcz : v;
	}
	inline int dec(const int &v) {
		return v < 0 ? v + kcz : v;
	}
	inline ModInt &operator+=(const ModInt &p) {
		x = inc(x + p.x);
		return T;
	}
	inline ModInt &operator-=(const ModInt &p) {
		x = dec(x - p.x);
		return T;
	}
	inline ModInt &operator*=(const ModInt &p) {
		x = (int)((LL)x * p.x % kcz);
		return T;
	}
	inline ModInt inverse() const {
		int a = x, b = kcz, u = 1, v = 0, t;
		while (b > 0)t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
		return u;
	}
	inline ModInt &operator/=(const ModInt &p) {
		T *= p.inverse();
		return T;
	}
	inline ModInt operator-() const {
		return -x;
	}
	inline friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) += rhs;
	}
	inline friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) -= rhs;
	}
	inline friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) *= rhs;
	}
	inline friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) /= rhs;
	}
	inline bool operator==(const ModInt &p) const {
		return x == p.x;
	}
	inline bool operator!=(const ModInt &p) const {
		return x != p.x;
	}
	ModInt qpow(LL n) const {
		ModInt ret(1), mul(x);
		while (n > 0) {
			if (n & 1)ret *= mul;
			mul *= mul, n >>= 1;
		}
		return ret;
	}
	inline friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}
	inline friend istream &operator>>(istream &is, ModInt &a) {
		LL t;
		is >> t, a = ModInt<kcz>(t);
		return is;
	}
	static int get_mod() {
		return kcz;
	}
#undef T
};

const int kcz=998244353;
using Z=ModInt<kcz>;
const int N=2e5+10;
int n,a[N];
vector<int> G[N];
vector<int> A;
Z ans;
struct Vir{
	int dfn[N],low[N],idx,F[N][21],dep[N];
	int vis[N],st[N],top,H[N],vip[N];
	vector<int> E[N];
	void dfs(int x,int fax){
		dfn[x]=++idx,F[x][0]=fax;
		for(int i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
		for(auto tox:G[x]){
			if(tox==fax)continue;
			dep[tox]=dep[x]+1,dfs(tox,x);
		}
		low[x]=idx;
	}
	inline int glca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		int d=dep[x]-dep[y];
		for(int i=20;~i;i--)if(d>>i&1)x=F[x][i];
		if(x==y)return x;
		for(int i=20;~i;i--)if(F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
		return F[x][0];
	}
	int sz[N];
	inline void solve(const vector<int> &T){
		int k=0;
		int m=(int)T.size();
		for(auto x:T)vis[x]=vip[x]=1,H[++k]=x;
		int tot=k;
		sort(H+1,H+k+1,[&](const int &x,const int &y){
			return dfn[x]<dfn[y];
		});
		for(int i=1,x;i<tot;i++){
			if(!vis[x=glca(H[i],H[i+1])])vis[H[++k]=x]=1;
		}
		if(!vis[1])H[++k]=1,vis[1]=1;
		tot=k,sort(H+1,H+tot+1,[&](const int &x,const int &y){
			return dfn[x]<dfn[y];
		});
		st[top=1]=H[1];
		for(int i=2;i<=tot;st[++top]=H[i++]){
			while(dfn[H[i]]<dfn[st[top]]||low[H[i]]>low[st[top]])top--;
			E[st[top]].pb(H[i]);
		}
		function<void(int)> dfs=[&](int x){
			sz[x]=vip[x];
			for(auto tox:E[x]){
				dfs(tox),sz[x]+=sz[tox];
				ans+=Z{sz[tox]}*(m-sz[tox])*(m-2)/2*(dep[tox]-dep[x]);
			}
		};
		dfs(1);
		for(res i=1;i<=tot;i++)vis[H[i]]=vip[H[i]]=0,vector<int>().swap(E[H[i]]);
	}
}Tree;
int vis[N];
vector<int> pos[N];
inline void solve(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]].pb(i);
	for(int i=2;i<=N-10;i++){
		if(!vis[i]){
			A.pb(i);
			for(int j=i+i;j<=N-10;j+=i)vis[j]=1;
		}
	}
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	Tree.dfs(1,0);
	for(auto x:A){
		vector<int> T;
		for(int i=x;i<=N-10;i+=x){
			for(auto y:pos[i])T.pb(y);
		}
//		printf("Case:%d\n",x);
//		for(auto y:T)printf("%d ",y);
//		puts("");
		Tree.solve(T);
	}
	printf("%d\n",ans);
}
int main(){
	int T=1;
	while(T--)solve();
}
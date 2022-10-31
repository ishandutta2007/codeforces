#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
const int BUF_SIZ=1<<18;
char ibuf[BUF_SIZ],*iS=ibuf,*iT=ibuf;
#define getchar() (iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,BUF_SIZ,stdin)),iS==iT?EOF:*iS++)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=500005,NC=(1<<20)+5;typedef long long ll;const ll INF=1e18;
ll a[N],b[N],c[N],ans;int L[N],R[N],k[N];
struct node{ll mx1,mx2,ans;}F[NC],val[N];int M;
inline node merge(const node &a,const node &b){
	return {std::max(a.mx1,b.mx1),std::max(a.mx2,b.mx2),std::max({a.ans,b.ans,a.mx1+b.mx2})};
}
void build(int n){
	for(int i=0;i<NC;++i)F[i]={-INF,-INF,-INF};
	for(M=1;M<=n+2;M<<=1);
	for(int i=1;i<=n;++i)F[i+M]={a[i]-b[i-1],b[i]+c[i],a[i]+c[i]+b[i]-b[i-1]};
	for(int i=M-1;i>=1;--i)F[i]=merge(F[i<<1],F[i<<1|1]);
}
node ask(int s,int t){
	node A={-INF,-INF,-INF},B=A;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)A=merge(A,F[s^1]);
		if(t&1)B=merge(F[t^1],B);
	}
	return merge(A,B);
}
struct atom{int ot,k,id;};
std::vector<atom> v1[N],v2[N];
namespace DS1{
ll c[N];void init(){memset(c,-63,sizeof(c));}
void clear(int x){++x;for(;x;x-=lowbit(x))c[x]=-INF;}
void add(int x,ll C){++x;for(;x;x-=lowbit(x))chmax(c[x],C);}
ll ask(int x){++x;ll ans=-INF;for(;x<N;x+=lowbit(x))chmax(ans,c[x]);return ans;}
}
namespace DS2{
ll c[N];void init(){memset(c,-63,sizeof(c));}
void clear(int x){++x;for(;x<N;x+=lowbit(x))c[x]=-INF;}
void add(int x,ll C){++x;for(;x<N;x+=lowbit(x))chmax(c[x],C);}
ll ask(int x){++x;ll ans=-INF;for(;x;x-=lowbit(x))chmax(ans,c[x]);return ans;}
}
ll f[N],g[N],V1[N],V2[N];
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;solve(l,mid),solve(mid+1,r);
	for(int i=l;i<=mid;++i)V1[i]=a[i]-b[i-1];
	for(int i=mid+1;i<=r;++i)V2[i]=b[i]+c[i];
	for(int i=mid-1;i>=l;--i)chmax(V1[i],V1[i+1]);
	for(int i=mid+2;i<=r;++i)chmax(V2[i],V2[i-1]);
	for(int i=l;i<=mid;++i){
		f[i]=-INF;
		for(const auto &it:v1[i]){
			int L=it.ot,k=it.k;
			f[i]=std::max({f[i],val[it.id].mx1-k,DS1::ask(L-1)-k});
			DS1::add(i,f[i]);
		}
	}
	for(int i=r;i>mid;--i){
		g[i]=-INF;
		for(const auto &it:v2[i]){
			int R=it.ot,k=it.k;
			g[i]=std::max({g[i],val[it.id].mx2-k,DS2::ask(R+1)-k});
			DS2::add(i,g[i]);
		}
	}
	chmax(ans,f[mid]+g[mid+1]);
	for(int i=mid+1;i<=r;++i){
		for(const auto &it:v1[i]){
			int L=std::max(l,it.ot);if(L>mid)continue;
			chmax(ans,std::max(V1[L],DS1::ask(L-1))+std::max(V2[i],DS2::ask(i+1))-it.k);
		}
	}
	for(int i=l;i<=mid;++i){
		for(const auto &it:v2[i]){
			int R=std::min(r,it.ot);if(R<=mid)continue;
			chmax(ans,std::max(V1[i],DS1::ask(i-1))+std::max(V2[R],DS2::ask(R+1))-it.k);
		}
	}
	for(int i=l;i<=mid;++i)DS1::clear(i);
	for(int i=mid+1;i<=r;++i)DS2::clear(i);
}
int main(){
	DS1::init(),DS2::init();
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;++i)read(b[i]),b[i]+=b[i-1];
	for(int i=1;i<=n;++i)read(c[i]);
	for(int i=n;i>=1;--i)c[i]+=c[i+1];
	build(n);ans=-INF;
	for(int i=1;i<=q;++i){
		read(L[i],R[i],k[i]),val[i]=ask(L[i],R[i]);
		ans=std::max(ans,val[i].ans-k[i]);
		v1[R[i]].pb({L[i],k[i],i}),v2[L[i]].pb({R[i],k[i],i});
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}
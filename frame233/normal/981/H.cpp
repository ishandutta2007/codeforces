#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int max_len=1<<18,N=max_len+5,mod=998244353,inf=0x3f3f3f3f;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>inline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
void print(const poly &a){
	for(auto it:a)printf("%d ",it);
	printf("\n");
}
inline poly operator << (poly a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator <<= (poly &a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator >> (const poly &a,uint b){return b>=a.size()?poly():poly{a.begin()+b,a.end()};}
inline poly operator >>= (poly &a,uint b){return a=b>=a.size()?poly():poly{a.begin()+b,a.end()};}
poly operator += (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i) add(a[i],b[i]);
	return a;
}
inline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i) sub(a[i],b[i]);
	return a;
}
inline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
const ull Omg=ksm(3,(mod-1)/max_len);
ull Omgs[N];
void setup(){
	Omgs[max_len/2]=1;
	for(int i=max_len/2+1;i<max_len;++i)Omgs[i]=Omgs[i-1]*Omg%mod;
	for(int i=max_len/2-1;i>0;--i)Omgs[i]=Omgs[i<<1];
}
uint rev[N];
uint getlen(uint len){
	uint limit=1;while(limit<len)limit<<=1;
	for(uint i=0;i<limit;++i)rev[i]=(rev[i>>1]>>1)|(i&1?limit>>1:0);
	return limit;
}
void dft(ull *A,uint limit){
	for(uint i=0;i<limit;++i)if(i<rev[i])std::swap(A[i],A[rev[i]]);
	for(uint len=1;len<limit;len<<=1){
		if(len==262144u)for(uint i=0;i<limit;++i)A[i]%=mod;
		for(uint i=0;i<limit;i+=len<<1){
			ull *p=A+i,*q=A+i+len,*w=Omgs+len;
			for(uint j=0;j<len;++j,++p,++q,++w){const ull tp=*q**w%mod;*q=*p+mod-tp,*p+=tp;}
		}
	}
	for(uint i=0;i<limit;++i)A[i]%=mod;
}
void idft(ull *A,uint limit){
	std::reverse(A+1,A+limit),dft(A,limit);
	ull inv=mod-(mod-1)/limit;for(uint i=0;i<limit;++i)A[i]=A[i]*inv%mod;
}
ull _f[N],_g[N],_tp[129];
poly operator * (const poly &a,const poly &b){
	uint len=a.size()+b.size()-1;
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size();++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	uint limit=getlen(len);
	memset(_f+a.size(),0,(limit-a.size())<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	memset(_g+b.size(),0,(limit-b.size())<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
	dft(_f,limit),dft(_g,limit);
	for(uint i=0;i<limit;++i)_f[i]=_f[i]*_g[i]%mod;
	idft(_f,limit);poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
poly mul(const poly &a,const poly &b,uint len,bool need=true){
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size()&&i+j<len;++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<len&&j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	int limit=getlen(len);
	memset(_f+a.size(),0,(limit-a.size())<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	dft(_f,limit);
	if(need){
		memset(_g+b.size(),0,(limit-b.size())<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
		dft(_g,limit);
	}
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
poly mulT(const poly &a,const poly &b){
	if(a.size()<=64u||b.size()<=64u){
		poly c(a.size()-b.size()+1);
		for(uint i=0;i<c.size();++i)for(uint j=0;j<b.size();++j)c[i]=(c[i]+1ULL*a[i+j]*b[j])%mod;
		return c;
	}
	int limit=getlen(a.size());
	memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
	std::reverse(_g,_g+b.size()),dft(_f,limit),dft(_g,limit);
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);poly ans(a.size()-b.size()+1);for(uint i=b.size()-1;i<a.size();++i)ans[i-b.size()+1]=_f[i];
	return ans;
}
inline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>inline poly operator *= (poly &a,const _Tp &b){
	for(auto &&it:a)it=1ULL*it*b%mod;
	return a;
}
template<typename _Tp>inline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>inline poly operator * (const _Tp &b,poly a){return a*=b;}
template<typename _Tp>inline poly operator /= (poly &a,const _Tp &b){
	ull inv=ksm(b);for(auto &&it:a)it=1ULL*it*inv%mod;
	return a;
}
template<typename _Tp>inline poly operator / (poly a,const _Tp &b){return a/=b;}
ll inv[N],ifac[N];
std::vector<int> e[N],w[N];
int siz[N],n,k,a[N],_[N];
poly f[N<<1];
void sol1(int l,int r,int u){
	if(l==r)return f[u]={1,a[l]},void();
	int mid=(l+r)>>1;
	sol1(l,mid,u<<1),sol1(mid+1,r,u<<1|1);
	f[u]=f[u<<1]*f[u<<1|1];
}
void sol2(int l,int r,int u,const poly &g){
	if(l==r)return _[l]=g[0],void();
	int mid=(l+r)>>1;
	poly tp=mulT(g,f[u<<1|1]);if(SZ(tp)>mid-l+1)tp.resize(mid-l+1);sol2(l,mid,u<<1,tp);
	tp=mulT(g,f[u<<1]);if(SZ(tp)>r-mid)tp.resize(r-mid);sol2(mid+1,r,u<<1|1,tp);
}
void ___(int x,int fa){
	std::sort(e[x].begin(),e[x].end());
	siz[x]=1;for(auto v:e[x])if(v!=fa)___(v,x),siz[x]+=siz[v];
	int pos=0;for(auto v:e[x])a[pos++]=v==fa?n-siz[x]:siz[v];
	sol1(0,pos-1,1);
	poly A(pos+1);for(int i=0;i<=pos;++i)A[i]=k-i>=0?ifac[k-i]:0;
	sol2(0,pos-1,1,A);
	w[x].resize(SZ(e[x]));for(int i=0;i<SZ(e[x]);++i)w[x][i]=_[i];
}
bool vis[N];int S,mn,rt;
int getsize(int x,int fa){int siz=1;for(auto v:e[x])if(v!=fa&&!vis[v])siz+=getsize(v,x);return siz;}
void getrt(int x,int fa){
	int tmp=0;siz[x]=1;for(auto v:e[x])if(v!=fa&&!vis[v])getrt(v,x),chmax(tmp,siz[v]),siz[x]+=siz[v];
	chmax(tmp,S-siz[x]);if(tmp<mn)mn=tmp,rt=x;
}
int QAQ,ans;
void dfs1(int x,int fa){
	add(QAQ,w[x][std::lower_bound(e[x].begin(),e[x].end(),fa)-e[x].begin()]);
	for(auto v:e[x])if(v!=fa&&!vis[v])dfs1(v,x);
}
void dfs(int x){
	S=getsize(x,0),mn=inf,getrt(x,0),vis[x=rt]=true;int sum=0;
	for(auto v:e[x])if(!vis[v])QAQ=0,dfs1(v,x),add(ans,1LL*QAQ*w[x][std::lower_bound(e[x].begin(),e[x].end(),v)-e[x].begin()]%mod),add(ans,1LL*sum*QAQ%mod),add(sum,QAQ);
	for(auto v:e[x])if(!vis[v])dfs(v);
}
int main(){
	inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	setup();read(n,k);if(k==1)ifac[0]=0;
	if(n==1)return puts("0"),0;
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	___(1,0),dfs(1);
	for(int i=1;i<=k;++i)ans=1LL*ans*i%mod*i%mod;
	printf("%d\n",ans);
	return 0;
}
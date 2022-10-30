#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int max_len=1<<18,N=max_len+5,mod=998244353,inv2=(mod+1)/2;
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
ull _f[N],_g[N],_tp[N];
poly operator * (const poly &a,const poly &b){
	if(a.empty()||b.empty())return {};
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
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
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
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
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
int a[N],b[N],c[N];
ll fac[N];
struct mat{
	poly a[2][2];
	inline mat(){a[0][0]=a[0][1]=a[1][0]=a[1][1]={0};}
	mat operator * (const mat &o)const{
		int len=0;for(int i=0;i<2;++i)for(int j=0;j<2;++j)for(int k=0;k<2;++k)len=std::max(len,SZ(a[i][k])+SZ(o.a[k][j])-1);
		uint limit=getlen(len);
		static ull F[2][2][N],G[2][2][N],H[N];
		for(int i=0;i<2;++i)for(int j=0;j<2;++j){
			for(int k=0;k<SZ(a[i][j]);++k)F[i][j][k]=a[i][j][k];
			memset(F[i][j]+a[i][j].size(),0,(limit-a[i][j].size())<<3);
		}
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)dft(F[i][j],limit);
		for(int i=0;i<2;++i)for(int j=0;j<2;++j){
			for(int k=0;k<SZ(o.a[i][j]);++k)G[i][j][k]=o.a[i][j][k];
			memset(G[i][j]+o.a[i][j].size(),0,(limit-o.a[i][j].size())<<3);
		}
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)dft(G[i][j],limit);
		mat ans;
		for(int i=0;i<2;++i)for(int j=0;j<2;++j){
			memset(H,0,limit<<3);int qwq=0;for(int k=0;k<2;++k)qwq=std::max(qwq,SZ(a[i][k])+SZ(o.a[k][j])-1);
			for(int k=0;k<2;++k)for(uint t=0;t<limit;++t)H[t]+=1ULL*F[i][k][t]*G[k][j][t];
			for(uint t=0;t<limit;++t)H[t]%=mod;
			idft(H,limit),ans.a[i][j].resize(qwq);
			for(int t=0;t<qwq;++t)ans.a[i][j][t]=H[t];
		}
		return ans;
	}
}M[N];
mat solve(int l,int r){
	if(l==r)return M[l];
	int mid=(l+r)>>1;
	return solve(mid+1,r)*solve(l,mid);
}
int main(){
	fac[0]=1;for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
	setup();
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int m=0;
	for(int i=1;i<=n;i+=a[i]){
		for(int j=0;j<a[i];++j)if(a[i+j]!=a[i])return puts("0"),0;
		b[m++]=a[i];
	}
	for(int i=0;i<m;++i){
		if(i)M[i].a[1][0]={mod-2},M[i].a[1][1]={mod-1};
		if(b[i]==1)M[i].a[0][0]={0,1},M[i].a[0][1]={0,1};
		else M[i].a[1][0]+={0,2},M[i].a[1][1]+={0,2};
	}
	mat ans=solve(0,m-1);int res=0;
	for(int a=0;a<2;++a)for(int i=0;i<SZ(ans.a[a][1]);++i)add(res,1LL*ans.a[a][1][i]*fac[i]%mod);
	printf("%d\n",res);
	return 0;
}
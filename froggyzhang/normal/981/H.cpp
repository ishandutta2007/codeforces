#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int qpow_constexpr(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
constexpr int Get_root(int p){
	if(p==998244353||p==1004535809||p==469762049)return 3;
	return 5;
}
template<int L,int mod>
class Poly_ntt{
private:
	using poly=Poly_ntt<L,mod>;
	static constexpr int G=Get_root(mod);
	static constexpr int invG=qpow_constexpr(G,mod-2,mod);
	vector<int> f;
	struct initializer{
		vector<int> GG[2][L+1];
		int inv[1<<L|233];
		initializer(){
			for(int p=1;p<=L;++p){
				int buf1=qpow(G,(mod-1)/(1<<p));
				int buf0=qpow(invG,(mod-1)/(1<<p));
				GG[0][p].resize(1<<p);
				GG[1][p].resize(1<<p);
				GG[0][p][0]=GG[1][p][0]=1;
				for(int i=1;i<(1<<p);++i){
					GG[0][p][i]=1LL*GG[0][p][i-1]*buf0%mod;
					GG[1][p][i]=1LL*GG[1][p][i-1]*buf1%mod;
				}
			}
			inv[1]=1;
			for(int i=2;i<=1<<L;++i){
				inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
			}
		}
	};
	static int qpow(int a,int b){
		int ans=1;
		while(b){
			if(b&1)ans=1LL*ans*a%mod;
			a=1LL*a*a%mod;
			b>>=1;
		}
		return ans;
	}
	static initializer init;
	static vector<int> tr;
	static int NTT_init(int n){
		int lim=1;
		while(lim<n)lim<<=1;
		tr.resize(lim);
		for(int i=0;i<lim;++i){
			tr[i]=((tr[i>>1]>>1)|(i&1?lim>>1:0));
		}
		return lim;
	}
	#define ck(x) (x>=mod?x-mod:x)
	static void NTT(poly &A,int flag,int n){
		A.resize(n);
		for(int i=0;i<n;++i){
			if(i<tr[i])swap(A.f[i],A.f[tr[i]]);
		}
		for(int p=2,j=1;p<=n;p<<=1,++j){
			int len=p>>1;
			for(int k=0;k<n;k+=p){
				int *buf=init.GG[flag][j].data();
				for(int i=k;i<k+len;++i,++buf){
					int tmp=1LL*(*buf)*A.f[i+len]%mod;
					A.f[i+len]=ck(A.f[i]-tmp+mod);
					A.f[i]=ck(A.f[i]+tmp);
				}
			}
		}
		if(!flag){
			for(int i=0;i<n;++i){
				A.f[i]=1LL*A.f[i]*init.inv[n]%mod;
			}
		}
	}
public:
	Poly_ntt(const vector<int> &_f):f(_f){}
	Poly_ntt(){}
	Poly_ntt(int _n){f.resize(_n);}
	int size()const{return f.size();}
	void resize(int _n){f.resize(_n);}
	vector<int>::reference operator [] (int x){return f[x];}
	vector<int>::const_reference operator [] (int x)const{return f[x];}
	vector<int>::iterator begin(){return f.begin();}
	vector<int>::iterator end(){return f.end();}
	vector<int>::const_iterator begin()const{return f.begin();}
	vector<int>::const_iterator end()const{return f.end();}
	friend poly Rshift(poly A,int x){
		A.resize(A.size()+x);
		for(int i=(int)A.size()-1;i>=x;--i){
			A[i]=A[i-x];
		}
		for(int i=0;i<x;++i)A[i]=0;
		return A;
	}
	friend poly Lshift(poly A,int x){
		if((int)A.size()<=x)return poly(vector<int>({0}));
		for(int i=0;i<(int)A.size()-x;++i){
			A[i]=A[i+x];
		}
		return A;
	}	
	friend poly Plus(poly A,poly B){
		int n=max(A.size(),B.size());
		A.resize(n),B.resize(n);
		for(int i=0;i<n;++i){
			A[i]=(A[i]+B[i])%mod;
		}
		return A;
	}
	friend poly Mul(poly A,poly B){
		int n=A.size()+B.size()-1;
		int lim=NTT_init(n);
		poly C(lim);
		NTT(A,1,lim),NTT(B,1,lim);
		for(int i=0;i<lim;++i){
			C[i]=1LL*A[i]*B[i]%mod;
		}
		NTT(C,0,lim);
		C.resize(n);
		return C;
	}
	friend poly Inv(poly &f,int m){
		if(m==1){
			return poly(vector<int>(1,qpow(f[0],mod-2)));
		}
		poly A(vector<int>(f.begin(),f.begin()+m));
		poly B=Inv(f,(m+1)>>1);
		int lim=NTT_init(m<<1);
		NTT(A,1,lim),NTT(B,1,lim);
		for(int i=0;i<lim;++i){
			A[i]=B[i]*(2-1LL*A[i]*B[i]%mod+mod)%mod;
		}
		NTT(A,0,lim);
		A.resize(m);
		return A;
	}
	friend poly WeiF(poly f){
		int n=f.size();
		if(n==1)return f[0]=0,f;
		for(int i=1;i<n;++i)f[i-1]=1LL*f[i]*i%mod;
		return f.resize(n-1),f;
	}
	friend poly JiF(poly f){
		int n=f.size();
		for(int i=n-1;i;--i)f[i]=1LL*f[i-1]*init.inv[i]%mod;
		return f[0]=0,f;
	}
	friend poly Ln(poly f,int n){
		f.resize(n);
		poly A=JiF(Mul(WeiF(f),Inv(f,n)));
		return A.resize(n),A;
	}
	friend poly Exp(poly &f,int m){
		if(m==1){
			return poly(vector<int>({1}));
		}
		poly B=Exp(f,(m+1)>>1);
		poly lnB=Ln(B,m);
		for(int i=0;i<m;++i){
			lnB[i]=ck(f[i]-lnB[i]+mod);
		}
		int lim=NTT_init(m<<1);
		NTT(B,1,lim),NTT(lnB,1,lim);
		for(int i=0;i<lim;++i){
			B[i]=1LL*B[i]*(1+lnB[i])%mod;
		}
		NTT(B,0,lim);
		B.resize(m);
		return B;
	}
	friend poly Sqrt(poly &f,int m){
		if(m==1){
			return poly(vector<int>({1}));
		}
		poly A(vector<int>(f.begin(),f.begin()+m));
		poly B=Sqrt(f,(m+1)>>1);
		poly iB=Inv(B,m);
		int lim=NTT_init(m<<1);
		NTT(A,1,lim),NTT(iB,1,lim);
		for(int i=0;i<lim;++i){
			A[i]=1LL*A[i]*iB[i]%mod;
		}
		NTT(A,0,lim);
		for(int i=0;i<m;++i){
			A[i]=1LL*(A[i]+B[i])*init.inv[2]%mod;
		}
		A.resize(m);
		return A;
	}
	friend poly Pow(poly f,int k){
		f=Ln(f,f.size());
		for(auto &x:f)x=1LL*x*k%mod;
		return Exp(f,f.size());
	}
private:
	#define ls u<<1
	#define rs u<<1|1
	static poly MulT(poly A,poly &B,int n){
		int lim=A.size();
		NTT_init(lim);
		for(int i=0;i<lim;++i){
			A[i]=1LL*A[i]*B[i]%mod;
		}
		NTT(A,1,lim);
		A.resize(n);
		return A;
	}
	static void build(int u,int l,int r,vector<int> &f,vector<poly> &nd){
		if(l+1==r){
			nd[u]=poly({1,mod-f[l]});
			return;
		}
		int mid=(l+r+1)>>1;
		build(ls,l,mid,f,nd),build(rs,mid,r,f,nd);
		int lim=NTT_init(r-l+1);
		NTT(nd[ls],1,lim),NTT(nd[rs],1,lim);
		nd[u].resize(lim);
		for(int i=0;i<lim;++i){
			nd[u][i]=1LL*nd[ls][i]*nd[rs][i]%mod;
		}
		NTT(nd[u],0,lim);
	}
	static void work(int u,int l,int r,poly f,vector<int> &g,vector<poly> &nd){
		if(l+1==r){
		 	g[l]=f[0];return;
		}
		int mid=(l+r+1)>>1;
		int lim=NTT_init(r-l+1);
		NTT(f,0,lim);
		work(ls,l,mid,MulT(f,nd[rs],mid-l),g,nd);
		work(rs,mid,r,MulT(f,nd[ls],r-mid),g,nd);
	}
	#undef ls
	#undef rs
public:
	friend vector<int> Evaluate(poly f,vector<int> x){
		int n=f.size(),m=x.size();
		n=max(n,m);
		f.resize(n),x.resize(n);
		vector<poly> nd((n<<4)+1);
		build(1,0,n,x,nd);
		nd[1]=Inv(nd[1],n);
		int lim=NTT_init(2*n-1);
		NTT(nd[1],1,lim);
		NTT(f,0,lim);
		vector<int> g(n);
		work(1,0,n,MulT(f,nd[1],n),g,nd);
		g.resize(m);
		return g;
	}
};
template<int L,int mod>
typename Poly_ntt<L,mod>::initializer Poly_ntt<L,mod>::init;
template<int L,int mod>
vector<int> Poly_ntt<L,mod>::tr;
const int mod=998244353;
using poly=Poly_ntt<19,mod>;
#define N 100010
int n,K,f[N],siz[N],fac[N],ifac[N],c[N],ans,s[N];
vector<int> G[N];
poly P[N];
poly Solve(int l,int r,vector<int> &A){
	if(l==r){
		return poly(vector<int>({1,A[l]}));	
	}
	int mid=(l+r)>>1;
	return Mul(Solve(l,mid,A),Solve(mid+1,r,A));
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
poly Div(poly A,int k){
	poly B((int)A.size()-1);
	int invk=qpow(k,mod-2);
	for(int i=(int)B.size()-1;i>=0;--i){
		B[i]=1LL*A[i+1]*invk%mod;
		A[i]=(A[i]-B[i]+mod)%mod;
	}
	return B;
}
int calc(const poly &A){
	int tot=0;
	for(int i=0;i<=min(A.size()-1,K);++i){
		tot=(tot+1LL*C(K,i)*A[i]%mod*fac[i]%mod)%mod;
	}
	return tot;
}
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs1(v);
		siz[u]+=siz[v];	
	}
	vector<int> A;
	for(auto v:G[u]){
		if(v==f[u])A.push_back(n-siz[u]);
		else A.push_back(siz[v]);
	}
	P[u]=Solve(0,(int)A.size()-1,A);
}
void dfs2(int u,int sum){
	if(u^1){
		ans=(ans+1LL*c[u]*(sum-s[u]+mod))%mod;
	}
	sum=(sum-c[u]+mod)%mod;
	int w=-1,las=-1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		if(siz[v]^las){
			las=siz[v];
			w=calc(Div(P[u],siz[v]));
		}
		dfs2(v,(sum+2LL*w)%mod);
	}	
}
void dfs3(int u){
	s[u]=c[u];
	for(auto v:G[u]){
		if(v==f[u])continue;
		dfs3(v);
		s[u]=(s[u]+s[v])%mod;
	}	
}
int main(){
	cin>>n>>K;
	if(K==1){
		cout<<1LL*n*(n-1)/2%mod<<'\n';
		return 0;
	}
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	init(max(n,K));
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	for(int i=1;i<=n;++i){
		sort(G[i].begin(),G[i].end(),[&](int x,int y){return siz[x]<siz[y];});
	}
	c[1]=calc(P[1]);
	for(int i=2;i<=n;++i){
		auto t=Div(P[i],n-siz[i]);
		c[i]=calc(Div(P[i],n-siz[i]));
	}
	dfs3(1);
	int sum=accumulate(c+1,c+n+1,0LL)%mod;
	dfs2(1,sum);
	ans=1LL*ans*(mod+1)/2%mod;
	cout<<ans<<'\n';
	return 0;
}//mmst
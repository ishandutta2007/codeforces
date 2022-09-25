#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 266666
const int mod=998244353;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
namespace Poly{
	typedef vector<int> poly;
	const int G=3;
	const int invG=qpow(G,mod-2);
	int tr[N],GG[2][21][N],inv[N];
	void Init(const int t){
		for(int p=1;p<=t;++p){
			int buf1=qpow(G,(mod-1)/(1<<p));
			int buf0=qpow(invG,(mod-1)/(1<<p));
			GG[0][p][0]=GG[1][p][0]=1;
			for(int i=1;i<(1<<p);++i){
				GG[0][p][i]=1LL*GG[0][p][i-1]*buf0%mod;
				GG[1][p][i]=1LL*GG[1][p][i-1]*buf1%mod;
			}
		}
		inv[1]=1;
		for(int i=2;i<=(1<<t);++i){
			inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
		}
	}
	int NTT_init(int n){
		int lim=1;
		while(lim<n)lim<<=1;
		for(int i=0;i<lim;++i){
			tr[i]=((tr[i>>1]>>1)|(i&1?lim>>1:0));
		}
		return lim;
	}
	#define ck(x) (x>=mod?x-mod:x)
	void NTT(vector<int> &f,int flag,int n){
		f.resize(n);
		for(int i=0;i<n;++i){
			if(i<tr[i])swap(f[i],f[tr[i]]);
		}
		for(int p=2,j=1;p<=n;p<<=1,++j){
			int len=p>>1;
			for(int k=0;k<n;k+=p){
				int *buf=GG[flag][j];
				for(int i=k;i<k+len;++i,++buf){
					int tmp=1LL*(*buf)*f[i+len]%mod;
					f[i+len]=ck(f[i]-tmp+mod);
					f[i]=ck(f[i]+tmp);
				}
			}
		}
		if(!flag){
			for(int i=0;i<n;++i){
				f[i]=1LL*f[i]*inv[n]%mod;
			}
		}
	}
	poly Rshift(poly A,int x){
		A.resize(A.size()+x);
		for(int i=(int)A.size()-1;i>=x;--i){
			A[i]=A[i-x];
		}
		for(int i=0;i<x;++i)A[i]=0;
		return A;
	}
	poly Lshift(poly A,int x){
		if((int)A.size()<=x)return poly(1,0);
		for(int i=0;i<(int)A.size()-x;++i){
			A[i]=A[i+x];
		}
		return A;
	}	
	poly Plus(poly A,poly B){
		int n=max(A.size(),B.size());
		A.resize(n),B.resize(n);
		for(int i=0;i<n;++i){
			A[i]=(A[i]+B[i])%mod;
		}
		return A;
	}
	poly Mul(poly A,poly B){
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
	poly Inv(poly &f,int m){
		if(m==1){
			return poly(1,qpow(f[0],mod-2));
		}
		poly A(f.begin(),f.begin()+m);
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
	poly WeiF(poly f){
		int n=f.size();
		if(n==1)return f[0]=0,f;
		for(int i=1;i<n;++i)f[i-1]=1LL*f[i]*i%mod;
		return f.resize(n-1),f;
	}
	poly JiF(poly f){
		int n=f.size();
		for(int i=n-1;i;--i)f[i]=1LL*f[i-1]*inv[i]%mod;
		return f[0]=0,f;
	}
	poly Ln(poly f,int n){
		f.resize(n);
		poly A=JiF(Mul(WeiF(f),Inv(f,n)));
		return A.resize(n),A;
	}
	poly Exp(poly &f,int m){
		if(m==1){
			return poly(1,1);
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
	poly Sqrt(poly &f,int m){
		if(m==1){
			return poly(1,1);
		}
		poly A(f.begin(),f.begin()+m);
		poly B=Sqrt(f,(m+1)>>1);
		poly iB=Inv(B,m);
		int lim=NTT_init(m<<1);
		NTT(A,1,lim),NTT(iB,1,lim);
		for(int i=0;i<lim;++i){
			A[i]=1LL*A[i]*iB[i]%mod;
		}
		NTT(A,0,lim);
		for(int i=0;i<m;++i){
			A[i]=1LL*(A[i]+B[i])*inv[2]%mod;
		}
		A.resize(m);
		return A;
	}
	poly Pow(poly f,int k){
		f=Ln(f,f.size());
		for(auto &x:f)x=1LL*x*k%mod;
		return Exp(f,f.size());
	}
	poly MulT(poly A,poly &B,int n){
		int lim=A.size();
		NTT_init(lim);
		for(int i=0;i<lim;++i){
			A[i]=1LL*A[i]*B[i]%mod;
		}
		NTT(A,1,lim);
		A.resize(n);
		return A;
	}
	#define ls u<<1
	#define rs u<<1|1
	poly nd[N<<2];
	void build(int u,int l,int r,poly &f){
		if(l+1==r){
			nd[u]=poly({1,mod-f[l]});
			return;
		}
		int mid=(l+r+1)>>1;
		build(ls,l,mid,f),build(rs,mid,r,f);
		int lim=NTT_init(r-l+1);
		NTT(nd[ls],1,lim),NTT(nd[rs],1,lim);
		nd[u].resize(lim);
		for(int i=0;i<lim;++i){
			nd[u][i]=1LL*nd[ls][i]*nd[rs][i]%mod;
		}
		NTT(nd[u],0,lim);
	}
	void work(int u,int l,int r,poly f,poly &g){
		if(l+1==r){
		 	g[l]=f[0];return;
		}
		int mid=(l+r+1)>>1;
		int lim=NTT_init(r-l+1);
		NTT(f,0,lim);
		work(ls,l,mid,MulT(f,nd[rs],mid-l),g);
		work(rs,mid,r,MulT(f,nd[ls],r-mid),g);
	}
	poly Evaluate(poly f,poly x){
		int n=f.size(),m=x.size();
		n=max(n,m);
		f.resize(n),x.resize(n);
		build(1,0,n,x);
		nd[1]=Inv(nd[1],n);
		int lim=NTT_init(2*n-1);
		NTT(nd[1],1,lim);
		NTT(f,0,lim);
		poly g(n);
		work(1,0,n,MulT(f,nd[1],n),g);
		g.resize(m);
		return g;
	}
	/*
	DON'T FORGET TO INIT !!!!!!!!!!!!!!
	*/
}
using Poly::poly;
using Poly::Mul;
int a[N],n,m,Q;
poly Solve(int L,int R,int q){
	if(L==R)return poly({1,((q-a[L])%mod+mod)%mod});
	int mid=(L+R)>>1;
	return Mul(Solve(L,mid,q),Solve(mid+1,R,q));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	Poly::Init(16);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	cin>>Q;
	while(Q--){
		int opt,x,p,l,r,d;
		cin>>opt;
		if(opt==1){
			cin>>x>>p>>d;
			swap(a[p],d);
		}
		else{
			cin>>x>>l>>r>>d;
			for(int i=l;i<=r;++i)a[i]+=d;
		}
		cout<<Solve(1,n,x)[m]<<'\n';
		if(opt==1)swap(a[p],d);
		else for(int i=l;i<=r;++i)a[i]-=d;
	}
	return 0;
}
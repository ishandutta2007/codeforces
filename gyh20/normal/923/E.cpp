#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
namespace R{
	int p,w,nn;
	struct cpp{
		int a,b;
		cpp(int a=0,int b=0):a(a),b(b){}
		cpp operator * (const cpp &x)const{
			return cpp((1ll*a*x.a%p+1ll*w*b%p*x.b)%p,(1ll*a*x.b%p+1ll*b*x.a%p)%p);
		}
	};
	inline cpp ksm(re cpp x,re int y){
		cpp ans=1;
		while(y){
			if(y&1)ans=ans*x;
			x=x*x,y>>=1;
		}
		return ans;
	}
	inline int ksm1(re int x,re int y){
		int ans=1;
		while(y){
			if(y&1)ans=1ll*ans*x%p;
			x=1ll*x*x%p,y>>=1;
		}
		return ans;
	}
	inline int c(){
		int a=1;
		while(ksm1((1ll*a*a%p-nn+p)%p,p>>1)==1)a=rand()%p;
		w=1ll*a*a%p-nn+p;
		return (ksm(cpp(a,1),(p+1)>>1).a)%p;
	}
	inline int sy(re int n,re int xx){
		p=xx;nn=n;
		nn%=p;
		if(!nn)return 0;re int xxx=(c()%p+p)%p;
		return min(xxx,p-xxx);
	}
}
namespace Poly{
	const int M=998244353;
	inline int ksm(re int x,re int y){
		re int s=1;
		while(y){
			if(y&1)s=1ll*s*x%M;
			x=1ll*x*x%M,y>>=1;
		}
		return s;
	}
	inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
	inline int Mod(re int x){return x>=M?x-M:x;}
	inline void Out(vector<int>A){
		puts("\n--------");
		printf("%d\n",A.size());
		for(re int i=0;i<A.size();++i)printf("%d ",A[i]);
		puts("");
		puts("--------\n");
	}
	int N,W[2097152],rev[2097152],wi[2097152],fac[1048576],inv[1048576],I[1048576];
	inline void pre(re int n){
		n=1<<(int)ceil(log2(n));
		re int wn=ksm(3,(M-1)/n);N=n;
		for(re int i=W[0]=1;i<n;++i)W[i]=1ll*W[i-1]*wn%M;
	}
	inline int make(re int n){
		re int l=ceil(log2(n));n=1<<l;
		for(re int i=0;i<n;++i)rev[i]=rev[i>>1]>>1|((i&1)<<(l-1));
		return n;
	}
	inline void Getfac(re int n){
		for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
		inv[n]=ksm(fac[n],M-2);
		for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	}
	inline void GetInv(re int n){
		I[1]=1;
		for(re int i=2;i<=n;++i)I[i]=1ll*I[M%i]*(M-M/i)%M;
	}
	inline void NTT(vector<int>&A,re int n,re int f){
		for(re int i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
		for(re int i=1;i<n;i<<=1){
			for(re int j=0;j<i;++j)wi[j]=W[f==1?j*(N/(i<<1)):(j?(N-j*(N/(i<<1))):j)];
			for(re int j=0;j<n;j+=i<<1)
				for(re int k=j;k<j+i;++k){
					re int x=A[k],y=1ll*A[k+i]*wi[k-j]%M;
					add(A[k],y),A[k+i]=Mod(x-y+M);
				}
		}
		if(f==-1){
			re int iv=ksm(n,M-2);
			for(re int i=0;i<n;++i)A[i]=1ll*A[i]*iv%M;
		}
	}
	inline void mul(vector<int>A,vector<int>B,vector<int>&C){
		re int k=make(A.size()+B.size()-1),o=A.size()+B.size()-1;
		A.resize(k),B.resize(k),C.resize(k);
		NTT(A,k,1),NTT(B,k,1);
		for(re int i=0;i<k;++i)C[i]=1ll*A[i]*B[i]%M;
		NTT(C,k,-1),C.resize(o);
	}
	inline void Dif(vector<int>&A){
		for(re int i=0;i+1<A.size();++i)A[i]=1ll*A[i+1]*(i+1)%M;
		A[A.size()-1]=0,A.resize(A.size()-1);
	}
	inline void Int(vector<int>&A){
		A.resize(A.size()+1);
		for(re int i=A.size()-1;i;--i)A[i]=1ll*A[i-1]*I[i]%M;
		A[0]=0;
	}
	inline void mul(vector<int>A,vector<int>B,vector<int>C,vector<int>&D){
		re int k=make(A.size()+B.size()+C.size()-2),o=A.size()+B.size()+C.size()-2;
		A.resize(k),B.resize(k),C.resize(k),D.resize(k);
		NTT(A,k,1),NTT(B,k,1),NTT(C,k,1);
		for(re int i=0;i<k;++i)D[i]=1ll*A[i]*B[i]%M*C[i]%M;
		NTT(D,k,-1),D.resize(o);
	}
	inline void Inv(vector<int>A,vector<int>&B){
		B.resize(A.size());
		if(A.size()==1){B[0]=ksm(A[0],M-2);return;}
		re int nl=A.size()+1>>1;vector<int>A0,B0;A0.resize(nl);
		for(re int i=0;i<nl;++i)A0[i]=A[i];
		Inv(A0,B0);
		mul(A,B0,B0,B),B.resize(A.size());
		for(re int i=0;i<B.size();++i)B[i]=Mod(M-B[i]);
		for(re int i=0;i<B0.size();++i)add(B[i],B0[i]),add(B[i],B0[i]);
	}
	inline void ln(vector<int>A,vector<int>&B){
		vector<int>C;
		Inv(A,C),Dif(A),mul(A,C,B);
		Int(B),B.resize(C.size());
	}
	inline void exp(vector<int>A,vector<int>&B){
		B.resize(A.size());
		if(A.size()==1){
			B[0]=1;
			return;
		}
		vector<int>A0,B0,tmp;re int nl=A.size()+1>>1;
		for(re int i=0;i<nl;++i)A0.push_back(A[i]);exp(A0,B0);B0.resize(A.size());
		ln(B0,tmp),B0.resize(A.size());
		for(re int i=0;i<tmp.size();++i)tmp[i]=M-tmp[i],add(tmp[i],A[i]);add(tmp[0],1);
		mul(B0,tmp,B),B.resize(A.size());
	}
	inline void Sqrt(vector<int>A,vector<int>&B){
		B.resize(A.size());
		if(A.size()==1){B[0]=A[0]==1?1:R::sy(A[0],M);return;}
		vector<int>A0,B0,tmp;re int nl=A.size()+1>>1;
		for(re int i=0;i<nl;++i)A0.push_back(A[i]);Sqrt(A0,B0);B0.resize(A.size());
		Inv(B0,tmp),B0.resize(A.size());
		for(re int i=0;i<tmp.size();++i)tmp[i]=1ll*tmp[i]*(M+1>>1)%M;
		mul(B0,B0,B0);
		B0.resize(A.size());
		for(re int i=0;i<B0.size();++i)add(B0[i],A[i]);
		mul(B0,tmp,B),B.resize(A.size());
	}
	inline void qpow(vector<int>A,vector<int>&B,re int k){
		ln(A,A);
		for(re int i=0;i<A.size();++i)A[i]=1ll*A[i]*k%M;
		exp(A,B);
	}
}
using namespace Poly;
vector<int>A,B,C;
int n;ll m;
int main(){
	n=read(),m=read(); 
	Getfac(n+n+1),pre(n+n+1);
	for(re int i=0;i<=n;++i)A.push_back(1ll*fac[i]*read()%M);
	for(re int i=0;i<=n;++i)B.push_back(inv[i]);
	reverse(B.begin(),B.end());
	mul(A,B,A);
	for(re int i=n;i<A.size();++i)C.push_back(A[i]);
	A.clear(),B.clear();
	for(re int i=0;i<C.size();++i)C[i]=1ll*C[i]*inv[i]%M*ksm(ksm(i+1,M-2),m%(M-1))%M;
	for(re int i=0;i<C.size();++i)C[i]=1ll*C[i]*fac[i]%M;
	for(re int i=0;i<=n;++i)B.push_back((i&1)?M-inv[i]:inv[i]);
	reverse(B.begin(),B.end()),mul(C,B,A);
	for(re int i=n;i<=n+n;++i)printf("%lld ",1ll*A[i]*inv[i-n]%M);
}
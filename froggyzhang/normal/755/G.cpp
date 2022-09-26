#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,k;
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
	#define N 266666
	typedef vector<int> poly;
	const int G=3;
	const int invG=qpow(G,mod-2);
	int tr[N],GG[2][20][N];
	int NTT_init(int n){
		int lim=1;
		while(lim<n)lim<<=1;
		for(int i=0;i<lim;++i)tr[i]=((tr[i>>1]>>1)|(i&1?lim>>1:0));
		return lim;
	}
	void Init(int t){
		for(int p=1;p<=t;++p){
			int buf1=qpow(G,(mod-1)/(1<<p));
			int buf0=qpow(invG,(mod-1)/(1<<p));
			GG[0][p][0]=GG[1][p][0]=1;
			for(int i=1;i<(1<<p);++i){
				GG[0][p][i]=1LL*GG[0][p][i-1]*buf0%mod;
				GG[1][p][i]=1LL*GG[1][p][i-1]*buf1%mod;
			}
		}
	}
	#define ck(x) ((x)>=mod?(x)-mod:(x))
	void NTT(poly &f,int flag,int n){
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
			int invn=qpow(n,mod-2);
			for(int i=0;i<n;++i){
				f[i]=1LL*f[i]*invn%mod;
			}
		}
	}
	poly Mul(poly A,poly B){
		int n=A.size()+B.size()-1;
		int lim=NTT_init(n);
		NTT(A,1,lim),NTT(B,1,lim);
		for(int i=0;i<lim;++i){
			A[i]=1LL*A[i]*B[i]%mod;
		}
		NTT(A,0,lim);
		return A;
	}
	poly Plus(poly A,poly B){
		int n=max(A.size(),B.size());
		A.resize(n),B.resize(n);
		for(int i=0;i<n;++i){
			A[i]=ck(A[i]+B[i]);
		}
		return A;
	}
	poly Rshift(poly A){
		A.push_back(0);
		for(int i=(int)A.size()-1;i>=1;--i){
			A[i]=A[i-1];
		}
		A[0]=0;
		return A;
	}
}
using Poly::poly;
using Poly::Plus;
using Poly::Mul;
using Poly::Rshift;
poly A,B,C;
int main(){
	Poly::Init(18);
	n=read(),k=read();
	A.resize(k+1),B.resize(k+1),C.resize(k+1);
	A[0]=1,B[0]=C[0]=0;
	for(int t=30;t>=0;--t){
		poly kA=Plus(Mul(A,A),Rshift(Mul(B,B)));
		poly kB=Plus(Mul(A,B),Rshift(Mul(B,C)));
		poly kC=Plus(Mul(B,B),Rshift(Mul(C,C)));
		kA.resize(k+1),kB.resize(k+1),kC.resize(k+1);
		A=kA,B=kB,C=kC;
		if(n>>t&1){
			poly D(k+1);
			for(int i=0;i<=k;++i){
				D[i]=((i>0?A[i-1]+B[i-1]:0)%mod+A[i])%mod;
			}
			C=B,B=A,A=D;
		}
	}
	for(int i=1;i<=k;++i){
		printf("%d ",A[i]);
	}
	return 0;
}
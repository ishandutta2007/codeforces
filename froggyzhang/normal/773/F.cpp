#include<bits/stdc++.h>
using namespace std;
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
int n,m,mod;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int qpow(int a,int b,const int mod){
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
	const int mod1=998244353,mod2=1004535809,mod3=469762049;
	const int inv1=qpow(mod1,mod2-2,mod2),inv2=qpow(1LL*mod1*mod2%mod3,mod3-2,mod3);
	struct Int{
		int A,B,C;
		Int(int _a=0,int _b=0,int _c=0){A=_a,B=_b,C=_c;}
		friend Int operator + (const Int &x,const Int &y){
			return Int((x.A+y.A)%mod1,(x.B+y.B)%mod2,(x.C+y.C)%mod3);
		}
		friend Int operator - (const Int &x,const Int &y){
			return Int((x.A-y.A+mod1)%mod1,(x.B-y.B+mod2)%mod2,(x.C-y.C+mod3)%mod3);
		}
		friend Int operator * (const Int &x,const Int &y){
			return Int(1LL*x.A*y.A%mod1,1LL*x.B*y.B%mod2,1LL*x.C*y.C%mod3);
		}
		inline int get(){
			ll x=1LL*(B-A+mod2)%mod2*inv1%mod2*mod1+A;
			return (x+1LL*(C-x%mod3+mod3)%mod3*inv2%mod3*(1LL*mod1*mod2%mod))%mod;
		}
	};
	const Int G=Int(3,3,3);
	const Int invG=Int(qpow(3,mod1-2,mod1),qpow(3,mod2-2,mod2),qpow(3,mod3-2,mod3));
	int tr[N];
	Int GG[2][20][N];
	int NTT_init(int n){
		int lim=1;
		while(lim<n)lim<<=1;
		for(int i=0;i<lim;++i)tr[i]=((tr[i>>1]>>1)|(i&1?lim>>1:0));
		return lim;
	}
	void Init(int t){
		for(int p=1;p<=t;++p){
			Int buf1=Int(qpow(3,(mod1-1)/(1<<p),mod1),qpow(3,(mod2-1)/(1<<p),mod2),qpow(3,(mod3-1)/(1<<p),mod3));
			Int buf0=Int(qpow(invG.A,(mod1-1)/(1<<p),mod1),qpow(invG.B,(mod2-1)/(1<<p),mod2),qpow(invG.C,(mod3-1)/(1<<p),mod3));
			GG[0][p][0]=GG[1][p][0]=Int(1,1,1);
			for(int i=1;i<(1<<p);++i){
				GG[0][p][i]=GG[0][p][i-1]*buf0;
				GG[1][p][i]=GG[1][p][i-1]*buf1;
			}
		}
	}
	void NTT(vector<Int> &f,int flag,int n){
		f.resize(n);
		for(int i=0;i<n;++i){
			if(i<tr[i])swap(f[i],f[tr[i]]);
		}
		for(int p=2,j=1;p<=n;p<<=1,++j){
			int len=p>>1;
			for(int k=0;k<n;k+=p){
				Int *buf=GG[flag][j];
				for(int i=k;i<k+len;++i,++buf){
					Int tmp=(*buf)*f[i+len];
					f[i+len]=f[i]-tmp;
					f[i]=f[i]+tmp;	
				}
			}
		}
		if(!flag){
			Int invn=Int(qpow(n,mod1-2,mod1),qpow(n,mod2-2,mod2),qpow(n,mod3-2,mod3));
			for(int i=0;i<n;++i){
				f[i]=f[i]*invn;
			}
		}
	}
	poly Mul(poly _A,poly _B){
		vector<Int> A(_A.size()),B(_B.size());
		for(int i=0;i<(int)A.size();++i)A[i]=Int(_A[i],_A[i],_A[i]);
		for(int i=0;i<(int)B.size();++i)B[i]=Int(_B[i],_B[i],_B[i]);
		int n=A.size()+B.size()-1;
		int lim=NTT_init(n);
		NTT(A,1,lim),NTT(B,1,lim);
		for(int i=0;i<lim;++i){
			A[i]=A[i]*B[i];
		}
		NTT(A,0,lim);
		_A.resize(n);
		for(int i=0;i<n;++i)_A[i]=A[i].get();
		return _A;
	}
	poly Plus(poly A,poly B){
		int n=max(A.size(),B.size());
		A.resize(n),B.resize(n);
		for(int i=0;i<n;++i)A[i]=(A[i]+B[i])%mod;
		return A;
	}
}
using Poly::poly;
using Poly::Mul;
using Poly::Plus;
poly A[2];
int ans;
int main(){
	Poly::Init(18);
	n=read(),m=read(),mod=read();
	A[0].resize(n+1);
	A[1].resize(n+1);
	for(int t=30,z=0;t>=1;--t){
		poly B[2];
		poly tmp=Plus(A[0],A[1]);
		++tmp[0];
		B[0]=Plus(A[0],Mul(A[0^(z&1)],tmp));
		B[1]=Plus(A[1],Mul(A[1^(z&1)],tmp));
		A[0]=B[0],A[1]=B[1];
		A[0].resize(n+1),A[1].resize(n+1);
		z<<=1;
		if(m>>t&1){
			for(int i=n;i>=1;--i){
				A[1][i]=((A[1][i]+A[1][i-1])%mod+A[0][i-1])%mod;
			}
			++A[1][1];
			++z;
		}
		for(int i=1;i<=n;i+=2){
			ans=(ans+A[1][i])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
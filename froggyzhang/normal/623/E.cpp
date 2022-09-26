#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
ll n;
int k;
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
}
using Poly::poly;
using Poly::Mul;
int fac[N],ifac[N],pw2[N];
void init(int n){
	fac[0]=pw2[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
		(pw2[i]=pw2[i-1]<<1)%=mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
poly A,E;
int main(){
	Poly::Init(18);
	n=read(),k=read();
	if(n>k){
		return !printf("0\n");
	}
	init(k);
	A=E=poly(k+1,0);
	A[0]=1;
	for(int i=1;i<=k;++i){
		E[i]=ifac[i];
	}
	for(int t=17,z=0;t>=0;--t){
		poly B=A;
		int c=qpow(2,z);
		for(int i=0,x=1;i<=k;++i,x=1LL*x*c%mod){
			B[i]=1LL*B[i]*x%mod;
		}
		A=Mul(A,B);
		A.resize(k+1);
		z<<=1;
		if(n>>t&1){
			B=A;
			for(int i=0;i<=k;++i){
				B[i]=1LL*B[i]*pw2[i]%mod;
			}
			A=Mul(B,E);
			A.resize(k+1);
			++z;	
		}
	}
	int ans=0;
	for(int i=1;i<=k;++i){
		ans=(ans+1LL*C(k,i)*(1LL*A[i]*fac[i]%mod))%mod;
	}
	printf("%d\n",ans);
	return 0;
}
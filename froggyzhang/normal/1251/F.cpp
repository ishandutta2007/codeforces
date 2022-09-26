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
int n,m;
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
	#define N 266666*4
	typedef vector<int> poly;
	const int G=3;
	const int invG=qpow(G,mod-2);
	int tr[N],GG[2][21][N];
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
}

using Poly::poly;
using Poly::Mul;
int fac[N],ifac[N],pw2[N],a[N],b[10],c[N],cnt[N],Q;
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
poly E[6];
int main(){
	Poly::Init(20);
	n=read(),m=read();
	init(600000);
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;++i){
		b[i]=read();
		c[i]=lower_bound(a+1,a+n+1,b[i])-a-1;
	}
	for(int k=1;k<=m;++k){
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=c[k];++i){
			++cnt[a[i]];
		}
		int la=0,lb=0;
		for(int i=1;i<=300000;++i){
			la+=cnt[i]==1;
			lb+=cnt[i]>=2;
		}
		poly A(la+1),B(lb<<1|1);
		for(int i=0;i<=la;++i)A[i]=1LL*pw2[i]*C(la,i)%mod;
		for(int i=0;i<=(lb<<1);++i)B[i]=C(lb<<1,i);
		E[k]=Mul(A,B);
		E[k].resize(600001);
	}
	Q=read();
	while(Q--){
		int x=read()/2-1;
		int ans=0;
		for(int k=1;k<=m;++k){
			if(x<b[k])continue;
			ans=(ans+E[k][x-b[k]])%mod;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
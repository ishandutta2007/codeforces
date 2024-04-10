#include<bits/stdc++.h>
using namespace std;
#define N 233333
const int lim=(1<<17);
const int mod=1e9+7;
const int inv2=(mod+1)/2;
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
int cnt[N],n,A[18][N],B[18][N],C[N],D[N],E[N],f[N],ans;
inline int bits(int x){
	return __builtin_popcount(x);
}
void FMT(int *f,int x){
	for(int i=0;i<17;++i)
		for(int j=0;j<lim;++j)
			if(j>>i&1)
				f[j]=(f[j]+(x?f[j^(1<<i)]:mod-f[j^(1<<i)]))%mod;
}
void FWT_and(int *f,int x,int n){
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				f[i]=(f[i]+(x?f[i+len]:mod-f[i+len]))%mod;
			}
		}
	}
}
void FWT_xor(int *f,int x,int n){
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				int l=(x?f[i]:1LL*f[i]*inv2%mod);
				int r=(x?f[i+len]:1LL*f[i+len]*inv2%mod);
				f[i]=(l+r)%mod,f[i+len]=(l-r+mod)%mod;
			}
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		++cnt[read()];
	}
	f[1]=1;
	for(int i=2;i<=lim;++i){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	for(int i=0;i<lim;++i){
		A[bits(i)][i]=cnt[i];
		C[i]=D[i]=cnt[i];
	}
	for(int i=0;i<=17;++i){
		FMT(A[i],1);
	}
	for(int s=0;s<lim;++s){
		for(int i=0;i<=17;++i){
			for(int j=0;j<=i;++j){
				B[i][s]=(B[i][s]+1LL*A[j][s]*A[i-j][s])%mod;
			}
		}
	}
	for(int i=0;i<=17;++i){
		FMT(B[i],0);
	}
	FWT_xor(C,1,lim);
	for(int i=0;i<lim;++i){
		C[i]=1LL*C[i]*C[i]%mod;
	}
	FWT_xor(C,0,lim);
	for(int i=0;i<lim;++i){
		C[i]=1LL*C[i]*f[i]%mod,D[i]=1LL*D[i]*f[i]%mod;
		E[i]=1LL*B[bits(i)][i]*f[i]%mod;
	}
	FWT_and(C,1,lim),FWT_and(D,1,lim),FWT_and(E,1,lim);
	for(int i=0;i<lim;++i){
		E[i]=1LL*C[i]*D[i]%mod*E[i]%mod;
	}
	FWT_and(E,0,lim);
	for(int i=0;i<17;++i){
		ans=(ans+E[1<<i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
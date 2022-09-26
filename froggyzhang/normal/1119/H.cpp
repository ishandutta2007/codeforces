#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 233333
const int mod=998244353;
const int inv2=(mod+1)/2;
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
int n,A[3][N],zyk,X,Y,Z,B[N],lim;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
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
	n=read(),lim=1<<read();
	X=read(),Y=read(),Z=read();
	for(int i=1;i<=n;++i){
		int a=read(),b=read(),c=read();
		zyk^=a,b^=a,c^=a;
		++A[0][b],++A[1][c],++A[2][b^c];
	}
	for(int i=0;i<3;++i)
		FWT_xor(A[i],1,lim);
	
	for(int i=0;i<lim;++i){
		int c1=(1LL*n+A[0][i]+A[1][i]+A[2][i])*inv2%mod*inv2%mod;
		int c2=(1LL*(n+A[0][i])*inv2%mod-c1+mod)%mod;
		int c3=(1LL*(n+A[1][i])*inv2%mod-c1+mod)%mod;
		int c4=(1LL*(n+A[2][i])*inv2%mod-c1+mod)%mod;
		B[i]=1LL*qpow(((ll)X+Y+Z)%mod,c1)
				*qpow(((ll)X+Y-Z+mod)%mod,c2) %mod
				*qpow(((ll)X-Y+Z+mod)%mod,c3) %mod
				*qpow(((ll)X-Y-Z+mod+mod)%mod,c4) %mod;
	}
	FWT_xor(B,0,lim);
	for(int i=0;i<lim;++i){
		printf("%d ",B[zyk^i]);
	}
	return 0;
}
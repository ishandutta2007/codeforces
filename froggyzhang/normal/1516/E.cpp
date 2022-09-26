#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 505
typedef vector<int> poly;
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
int n,k,S[N][N],fac[N],ifac[N],_n[N],inv[N];
poly A;
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
	S[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			S[i][j]=(S[i-1][j-1]+1LL*j*S[i-1][j])%mod;
		}
	}
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n+1;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
}
poly Exp(const poly &A,int n){
	poly B(n);
	B[0]=1;
	for(int i=1;i<n;++i){
		for(int j=1;j<=i;++j){
			B[i]=(B[i]+1LL*A[j]*j%mod*B[i-j])%mod;
		}
		B[i]=1LL*B[i]*inv[i]%mod;	
	}
	return B;
}
int main(){
	n=read(),k=read();
	init(k);
	A.resize(k+1);
	_n[0]=1;
	for(int i=1;i<=k+1;++i){
		_n[i]=1LL*_n[i-1]*(n-i+1)%mod;
	}
	for(int j=1;j<=k;++j){
		for(int p=0;p<=j;++p){
			A[j]=(A[j]+1LL*S[j][p]*_n[p+1]%mod*inv[p+1])%mod;
		}
		A[j]=1LL*inv[j]*(j&1?A[j]:mod-A[j])%mod;
		
	}
	A=Exp(A,k+1);
	int ans[2]={1,0};
	for(int i=1;i<=k;++i){
		if(i<=n)ans[i&1]=(ans[i&1]+A[i])%mod;
		printf("%d ",ans[i&1]);
	}
	return 0;
}
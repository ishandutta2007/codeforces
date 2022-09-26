#include<bits/stdc++.h>
using namespace std;
#define N 5005
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
int n,m,k,S[N][N],inv[N],fac[N];
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
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
}
int ans;
int main(){
	n=read(),m=read(),k=read();
	init(k);
	int invm=qpow(m,mod-2),zyk=1;
	for(int j=0,tp=1;j<=k;++j){
		ans=(ans+1LL*fac[j]*S[k][j]%mod*tp%mod*zyk)%mod;
		tp=1LL*tp*invm%mod;
		zyk=1LL*zyk*(n-j)%mod*inv[j+1]%mod;
	}
	printf("%d\n",ans);
	return 0;
}
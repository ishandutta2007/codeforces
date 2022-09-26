#include<bits/stdc++.h>
using namespace std;
#define N 5005
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
int S2[N][N],n_[N],n,k,ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),k=read();
	n_[0]=1;
	for(int i=1;i<=k;++i){
		n_[i]=1LL*n_[i-1]*(n-i+1)%mod;
	}
	S2[0][0]=1;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=i;++j){
			S2[i][j]=(S2[i-1][j-1]+1LL*j*S2[i-1][j])%mod;
		}
	}
	for(int j=0;j<=min(k,n);++j){
		ans=(ans+1LL*n_[j]*qpow(2,n-j)%mod*S2[k][j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
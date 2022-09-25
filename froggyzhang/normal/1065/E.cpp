#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
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
int n,m,b[N],dp[N],A;
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
	n=read(),m=read(),A=read();
	for(int i=1;i<=m;++i){
		b[i]=read();
	}
	dp[0]=1;
	for(int i=1;i<=m;++i){
		dp[i]=1LL*dp[i-1]*(qpow(A,2*(b[i]-b[i-1]))+qpow(A,b[i]-b[i-1]))%mod*inv2%mod;
	}
	int ans=1LL*dp[m]*qpow(A,n-2*b[m])%mod;
	printf("%d\n",ans);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000100
inline int read(){
	int x=0,f=1;
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
int n;
ll dp[N],r1,r2,r3,d,a[N],s[N],g[N];
int main(){
	n=read();
	r1=read(),r2=read(),r3=read();
	d=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+min(r1+r2,a[i]*r1+min(r1<<1,r3));
	}
	memset(dp,0x3f,sizeof(dp));
	memset(g,0x3f,sizeof(g));
	dp[0]=g[0]=-d;
	for(int i=1;i<=n;++i){
		if(i>1)dp[i]=g[i-2]+3LL*(i-1)*d+s[i];
		dp[i]=min(dp[i],dp[i-1]+a[i]*r1+r3)+d;
		g[i]=min(g[i-1],dp[i]-3LL*i*d-s[i]);
	}
	for(int i=0;i<n-1;++i){
		dp[n]=min(dp[n],dp[i]+2LL*(n-i)*d-d+s[n-1]-s[i]+a[n]*r1+r3);
	}
	printf("%I64d\n",dp[n]);
	return 0;
}
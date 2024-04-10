#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define N 300030
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
int n,h[N],dp[N];
int A[N],B[N],topA,topB;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		dp[i]=n;
		h[i]=read();
	}
	dp[1]=0;
	A[topA=1]=B[topB=1]=1;
	for(int i=2;i<=n;++i){
		dp[i]=dp[i-1]+1;
		while(topA&&h[i]>=h[A[topA]]){
			if(topA>1&&h[i]^h[A[topA]])dp[i]=min(dp[i],dp[A[topA-1]]+1);
			--topA;
		}
		while(topB&&h[i]<=h[B[topB]]){
			if(topB>1&&h[i]^h[B[topB]])dp[i]=min(dp[i],dp[B[topB-1]]+1);
			--topB;
		}
		A[++topA]=i,B[++topB]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
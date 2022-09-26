#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 202
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
int R,G,B,a[N],b[N],c[N],ans;
int dp[N][N][N];
int main(){
	R=read(),G=read(),B=read();
	for(int i=1;i<=R;++i){
		a[i]=read();
	}
	for(int i=1;i<=G;++i){
		b[i]=read();
	}
	for(int i=1;i<=B;++i){
		c[i]=read();
	}
	sort(a+1,a+R+1);
	sort(b+1,b+G+1);
	sort(c+1,c+B+1);
	for(int i=0;i<=R;++i){
		for(int j=0;j<=G;++j){
			for(int k=0;k<=B;++k){
				int &s=dp[i][j][k];
				if(i&&j)s=max(s,dp[i-1][j-1][k]+a[i]*b[j]);
				if(j&&k)s=max(s,dp[i][j-1][k-1]+b[j]*c[k]);
				if(i&&k)s=max(s,dp[i-1][j][k-1]+a[i]*c[k]);
				ans=max(ans,s);
			}
		}
	} 
	printf("%d\n",ans);
	return 0;
}
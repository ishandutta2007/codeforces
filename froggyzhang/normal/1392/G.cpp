#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000100
#define K 23
const int inf=0x3f3f3f3f;
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
int dp[2][1<<20];
int n,m,k,p[K],a[K],b[K],ans,L,R;
char s[K],t[K];
void Trans(int *a,char *s){
	for(int i=1;i<=k;++i){
		a[p[i]]=s[i]-'0';
	}
}
int main(){
	n=read(),m=read(),k=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=k;++i){
		p[i]=i;
	}
	memset(dp[0],0x3f,sizeof(dp[0])); //S
	memset(dp[1],~0x3f,sizeof(dp[1])); //T
	for(int i=0;i<=n;++i){
		if(i){	
			int x=read(),y=read();
			swap(p[x],p[y]);
		}
		int ga=0,gb=0;
		Trans(a,s),Trans(b,t);
		for(int j=1;j<=k;++j){
			ga=ga<<1|a[j];
			gb=gb<<1|b[j];
		}
		dp[0][ga]=min(dp[0][ga],i);
		dp[1][gb]=max(dp[1][gb],i);
	}
	ans=-inf;
	for(int i=(1<<k)-1;i>=0;--i){
		for(int j=0;j<k;++j){
			if((i>>j)&1){
				dp[0][i^(1<<j)]=min(dp[0][i^(1<<j)],dp[0][i]);
				dp[1][i^(1<<j)]=max(dp[1][i^(1<<j)],dp[1][i]);
			}
		}
		if(dp[1][i]-dp[0][i]>=m){
			if(__builtin_popcount(i)>ans){	
				ans=max(ans,__builtin_popcount(i));
				L=dp[0][i]+1,R=dp[1][i];
			}
		}
	}
	ans<<=1;
	ans+=k;
	for(int i=1;i<=k;++i){
		ans-=(s[i]=='1')+(t[i]=='1');
	}
	printf("%d\n%d %d\n",ans,L,R);
	return 0;
}
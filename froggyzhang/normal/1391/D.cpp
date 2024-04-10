#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
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
int n,m;
int a[N];
int dp[N][8],cnt[10],ans;
int main(){
	n=read(),m=read();
	if(n>=4&&m>=4){
		return !printf("-1\n");
	}
	if(n>m)swap(n,m);
	if(n==1){
		return !printf("0\n");
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c=getchar();
			while(c^'0'&&c^'1')c=getchar();
			a[j]|=((c-'0')<<(i-1));
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<(1<<n);++i){
		dp[0][i]=0;
	}
	for(int i=1;i<(1<<n);++i){
		cnt[i]=(cnt[i>>1]+(i&1));
	}
	for(int j=1;j<=m;++j){
		for(int i=0;i<(1<<n);++i){
			for(int p=0;p<(1<<n);++p){
				if(!((cnt[i&3]+cnt[p&3])&1))continue;
				if(n==3&&!((cnt[i&6]+cnt[p&6])&1))continue;
				dp[j][i]=min(dp[j][i],dp[j-1][p]+cnt[i^a[j]]);
			}
		}
	}
	int ans=inf;
	for(int i=0;i<(1<<n);++i){
		ans=min(ans,dp[m][i]);
	}
	printf("%d\n",ans);
	return 0;
}
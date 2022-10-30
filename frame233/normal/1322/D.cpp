#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=2005;
int a[N],b[N],c[N+N],dp[N+15][N];
int main(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	for(int i=1;i<=n+m;++i)read(c[i]);
	memset(dp,-63,sizeof(dp));
	for(int i=0;i<=m;++i)dp[i][0]=0;
	for(int i=n;i>=1;--i){
		for(int j=n;j>=0;--j)chmax(dp[a[i]][j+1],dp[a[i]][j]-b[i]);
		for(int j=a[i],lim=n;j<=n+15&&j<=n+m;++j,lim>>=1){
			for(int k=0;k<=lim;++k)chmax(dp[j+1][k/2],dp[j][k]+c[j]*k);
		}
	}
	int ans=0;
	for(int i=1;i<=n+m&&i<=m+15;++i)chmax(ans,dp[i][0]);
	printf("%d\n",ans);
	return 0;
}
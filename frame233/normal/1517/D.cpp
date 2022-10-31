#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int dp[12][505][505],a[505][505],b[505][505];
int main(){
	int n,m,k;read(n,m,k);
	if(k&1){
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("-1%c"," \n"[j==m]);
		return 0;
	}
	k/=2;
	for(int i=1;i<=n;++i)for(int j=1;j<m;++j)read(a[i][j]);
	for(int i=1;i<n;++i)for(int j=1;j<=m;++j)read(b[i][j]);
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)dp[0][i][j]=0;
	for(int _=1;_<=k;++_)for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)dp[_][i][j]=std::min({dp[_-1][i-1][j]+b[i-1][j],dp[_-1][i+1][j]+b[i][j],dp[_-1][i][j-1]+a[i][j-1],dp[_-1][i][j+1]+a[i][j]});
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d%c",dp[k][i][j]*2," \n"[j==m]);
	return 0;
}
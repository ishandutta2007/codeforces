#include<bits/stdc++.h>
typedef long long ll;
const int N=55;
ll dp[N][N][N][2][2],f[N][2],c[N],L[N],R[N];
inline void chmin(ll &a,ll b){(b<a)&&(a=b);}
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&L[i],&R[i]);
	for(int i=0;i<k;++i)scanf("%lld",&c[i]);
	memset(dp,63,sizeof(dp));
	for(int l=0;l<=n+1;++l)for(int a=0;a<2;++a)for(int b=0;b<2;++b) dp[k][l][l+1][a][b]=0;
	for(int i=k-1;i>=0;--i)for(int l=0;l<=n;++l)for(int a=0;a<2;++a)
	{
		memset(f,63,sizeof(f)),f[l][a]=0;
		for(int r=l+1;r<=n+1;++r)for(int b=0;b<2;++b)for(int p=l;p<r;++p)for(int s=0;s<2;++s)
		{
			chmin(dp[i][l][r][a][b],f[p][s]+dp[i+1][p][r][s][b]+((p==l?((a?R[p]:L[p])>>i&1):!s)!=((b?R[r]:L[r])>>i&1)&&p&&r!=n+1?c[i]:0));
			if(b==((b?R[r]:L[r])>>i&1)&&((L[r]^R[r])>>(i+1)))chmin(f[r][b],f[p][s]+dp[i+1][p][r][s][b]+(b==(p==l?((a?R[p]:L[p])>>i&1):!s)&&p&&r!=n+1?c[i]:0));
		}
	}
	memset(f,63,sizeof(f)),f[0][0]=f[0][1]=0;
	for(int r=1;r<=n+1;++r)for(int b=0;b<2;++b)for(int p=0;p<r;++p)for(int s=0;s<2;++s) chmin(f[r][b],f[p][s]+dp[0][p][r][s][b]);
	printf("%lld\n",f[n+1][0]);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int Mo=1000000007;
int f[2010][2010];
int dp(int n,int m)
{
	if (m==0) return 1;
	LL ans=0;
	if (f[n][m]) return f[n][m];
	for (int i=1;i<=n;i++)
		ans+=(LL)dp(n/i,m-1);
	ans%=Mo;
	f[n][m]=ans;
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",dp(n,m));
	return 0;
}
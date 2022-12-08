#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl;
const int sz = 1002, m=1e8;

int n1, n2, k1, k2, dp[sz][sz];
int main()
{
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	rep(i,0,n1+1)
		dp[i][0]=0;
	rep(i,0,n2+1)
		dp[0][i]=0;
	dp[0][0]=1;
	rep(i,1,n1+1)
	{
		rep(j,1,n2+1)
		{
			for(int ki=1;ki<=k1 && i-ki>=0;++ki)
				for(int kj=1;kj<=k2 && j-kj>=0;++kj)
					dp[i][j]=(dp[i][j]+dp[i-ki][j-kj])%m;
		}
	}
	int ans=0;
	for(int ki=1;ki<=k1 && n1-ki>=0;++ki)
		ans=(ans+dp[n1-ki][n2])%m;
	for(int kj=1;kj<=k2 && n2-kj>=0;++kj)
		ans=(ans+dp[n1][n2-kj])%m;
	for(int ki=1;ki<=k1 && n1-ki>=0;++ki)
		for(int kj=1;kj<=k2 && n2-kj>=0;++kj)
			ans=(ans+2*dp[n1-ki][n2-kj])%m;
	printf("%d\n",ans);
}
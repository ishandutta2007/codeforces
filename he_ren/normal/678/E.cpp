#include<cstdio>
#include<algorithm>
typedef long double db;
const int MAXN = 18 + 5;
const int MAXS = (1<<18) + 5;
using namespace std;

inline void chk_max(db &a,db b){ if(a<b) a=b;}

int n,maxs;
db a[MAXN][MAXN];

db dp[MAXS][MAXN];
db gao(int s,int i)
{
	if(dp[s][i]>=-0.5) return dp[s][i];
	if(s==maxs) return dp[s][i]=!i;
	
	db &res=dp[s][i];
	for(int j=0; j<n; ++j)
		if(((s>>j)&1)==0)
			chk_max(res, a[i][j]*gao(s|(1<<j), i)+a[j][i]*gao(s|(1<<j), j));
	return res;
}

int main(void)
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			double p;
			scanf("%lf",&p);
			a[i][j]=p;
		}	
	
	maxs=(1<<n)-1;
	for(int s=0; s<=maxs; ++s)
		for(int i=0; i<n; ++i)
			dp[s][i]=-1;
	
	db ans=0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<i; ++j)
		{
			int s=(1<<i)|(1<<j);
			chk_max(ans, a[i][j]*gao(s,i)+a[j][i]*gao(s,j));
		}
	
	printf("%.20lf",(double)ans);
	return 0;
}
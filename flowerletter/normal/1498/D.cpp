#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxM=500000+5,Inf=(1LL<<30)-1,Error=-1;
const float Eps=5.0e-14;
int dp[MaxM],Next[MaxM],dis[MaxM];
signed main()
{
	register int n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,1,m)
		dp[i]=Inf;
	register int cmd,x,y;
	register long double val;
	rep(i,1,n)
	{
		scanf("%lld%lld%lld",&cmd,&x,&y);
		val=((double)x)/100000.0;
		if(cmd==1)
		{
			rep(j,0,m)
			{
				Next[j]=(int)(ceil(j+val-Eps)+0.5);
				if(Next[j]>m)
					Next[j]=Error;
			}
		}
		else //if(cmd==2)
		{
			rep(j,0,m)
			{
				Next[j]=(int)(ceil(j*val-Eps)+0.5);
				if(Next[j]>m)
					Next[j]=Error;
			}
		}
		rep(j,0,m)
			dis[j]=Inf;
		rep(j,0,m)
		{
			if(dp[j]!=Inf)
				dis[j]=0;
			if(Next[j]==Error)
				continue;
			dis[Next[j]]=min(dis[Next[j]],dis[j]+1);
		}
		rep(j,1,m)
			if(dis[j]<=y&&dp[j]==Inf)
				dp[j]=i;
	}
	rep(j,1,m)
	{
		if(dp[j]==Inf)
			printf("%lld ",-1LL);
		else
			printf("%lld ",dp[j]);
	}
	printf("\n");
	return 0;
}
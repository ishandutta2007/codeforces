#include <cstdio>
#include <cmath>
#include <cstring>
int n;
double l,r,dp[1<<21],x[21],y[21],deg[21];
double min(double x,double y) { return x<y?x:y;}
double max(double x,double y) { return x>y?x:y;}
double val(double cur,double x,double y,double deg)
{
	double deg2=atan2(-y,cur-x);
	deg2+=deg;
	if(deg2>-1e-7) return r;
	return min(r,x-y/tan(deg2));
}
double mem(int mask)
{
	if(dp[mask]>-0.1) return dp[mask];
	dp[mask]=0.0;
	for(int i=0;i<n;i++)
	{
		if(((mask>>i)&1))
		{
			double a=mem(mask^(1<<i));
			dp[mask]=max(dp[mask],val(a,x[i],y[i],deg[i]));
		}
	}
	return dp[mask];
}
int main()
{
	scanf("%d %lf %lf",&n,&l,&r);
	r-=l;
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf %lf",&x[i],&y[i],&deg[i]);
		x[i]-=l;
		deg[i]*=(3.14159265358979/180.0);
	}memset(dp,-1,sizeof(dp));
	printf("%.10lf%c",mem((1<<n)-1),10);
}
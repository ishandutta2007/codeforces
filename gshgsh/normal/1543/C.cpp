#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define eps 1e-12
double dfs2(double a,double b,double c,double p,int x)
{
	if(p<eps)return 0;
	double tmp=min(a,c),ans=0;return a-tmp>eps?dfs2(a-tmp,b+tmp,c,p*a,x+1)+p*b*(x+1):p*a*(x+2)+p*b*(x+1);
}
double dfs(double a,double b,double c,double d,double p,int x)
{
	if(p<eps)return 0;
	double tmp=min(a,d),ans=0;if(a-tmp>eps)ans+=dfs(a-tmp,b+tmp/2,c+tmp/2,d,p*a,x+1);else ans+=dfs2(b+tmp/2,c+tmp/2,d,p*a,x+1);
	tmp=min(b,d);if(b-tmp>eps)ans+=dfs(a+tmp/2,b-tmp,c+tmp/2,d,p*b,x+1);else ans+=dfs2(a+tmp/2,c+tmp/2,d,p*b,x+1);
	ans+=p*c*(x+1);return ans;
}
int main()
{
	int T;cin>>T;
	while(T--)
	{
		double a,b,c,d;cin>>a>>b>>c>>d;
		printf("%.12lf\n",dfs(a,b,c,d,1,0));
	}
	return 0;
}
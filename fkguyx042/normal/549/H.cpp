#include<cmath>
#include<cstdio>
#include<algorithm>
#define eps 1e-10
using namespace std;
double L,r,Mid,ans,a1,a2,a3,a4,Minn,maxx,Min14,Min233,max14,max233;
bool check(double x)
{
	Min14=a1*a4;
	Min14=min(Min14,min((a1-x)*(a4+x),min(min(Min14,(a1-x)*(a4-x)),min(Min14,(a1+x)*(a4+x)))));
	Min14=min(Min14,(a1+x)*(a4-x)); max14=a1*a4;
	max14=max(max14,(a1-x)*(a4+x)); max14=max(max14,(a1-x)*(a4-x)); max14=max(max14,(a1+x)*(a4+x)); max14=max(max14,(a1+x)*(a4-x));	 Min233=a2*a3;
	Min233=min(Min233,(a2-x)*(a3+x)); Min233=min(Min233,(a2-x)*(a3-x)); Min233=min(Min233,(a2+x)*(a3+x));
	Min233=min(Min233,(a2+x)*(a3-x)); max233=a2*a3;
	max233=max(max233,(a2-x)*(a3+x)); max233=max(max233,(a2-x)*(a3-x)); max233=max(max233,(a2+x)*(a3+x)); max233=max(max233,(a2+x)*(a3-x));
	Minn=Min14-max233; maxx=max14-Min233;
	if(Minn<=0&&maxx>=0)return 1;
	return 0;
}

int main()
{
	int Sm=0;
	L=0;r=10000000000.0;
	scanf("%lf%lf%lf%lf",&a1,&a2,&a3,&a4);
	while(L+eps<=r&&Sm<=500)
	{
		Mid=(L+r)/2.;
		if(check(Mid))ans=Mid,r=Mid-eps; else L=Mid+eps;
		Sm++;
	}
	printf("%.9lf\n",ans);
}
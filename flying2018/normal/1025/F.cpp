#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 2010
const double pi=acos(-1);
using namespace std;
struct node{
	double x,y;
}p[N];
double num[N];
int main()
{
	int n;
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)
	{
		int tot=0,l=1;
		for(int j=1;j<=n;j++)
		if(i!=j) num[++tot]=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
		sort(num+1,num+tot+1);
		for(int j=1;j<=tot && num[j]<=0;j++)
		{
			while(l<=tot && num[l]-num[j]<pi) l++;
			ans+=1ll*(l-j-1)*(l-j-2)/2*(tot-l+j)*(tot-l+j-1)/2;
		}
	}
	printf("%lld",ans);
	return 0;
}
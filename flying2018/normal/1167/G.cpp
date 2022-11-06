#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define db double
#define N 200010
using namespace std;
const db pi=acos(-1);
int num[N];
int main()
{
	int n,m,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	scanf("%d",&m);
	int u=0;
	while(m--)
	{
		int x;
		scanf("%d",&x);
		for(;u<n && num[u+1]<x;u++) ;
		if(num[u]==x-1 && num[u+1]==x){printf("%.11lf\n",pi); continue; }
        else if(num[u]==x-1 || num[u+1]==x){printf("%.11lf\n",pi/2);continue;}
        int l=u;
        double res=max(u<n?atan2(1,num[u+1]-x):0,u>0?atan2(1,x-num[u]-1):0);
        int d=min(num[u+1]-x,x-num[u]-1);
        int r=u+1;
        while(l>=1 && r<=n && num[r]-num[l]<=(d+5)*4)
        {
            int dis1=num[r]-x,dis2=x-num[l]-1;
            if(abs(dis1-dis2)<=1)
            {
                res=max(res,atan2(1.0,max(dis1,dis2))*2);
            	break;
			}
			if(dis1<dis2) r++;
			else l--;
		}
		printf("%.10f\n",res);
	}
	return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010;
int m,h,a,x,y;
int v[N];
int k1,k2,b1,b2;
int main()
{
	scanf("%d",&m);
	scanf("%d%d",&h,&a);
	scanf("%d%d",&x,&y);
	for (int i=0;i<m;i++) v[i]=0;
	b1=b2=-1;
	for (int i=1;i<=m+10;i++)
	{
		h=(1LL*h*x+y)%m;
		if (h==a&&b1==-1) b1=i;
		if (v[h]==0) v[h]=i;else 
		{
			if (v[h]>b1) k1=0;else k1=i-v[h];
			break;
		}
	}
	
	scanf("%d%d",&h,&a);
	scanf("%d%d",&x,&y);
	for (int i=0;i<m;i++) v[i]=0;
	for (int i=1;i<=m+10;i++)
	{
		h=(1LL*h*x+y)%m;
		if (h==a&&b2==-1) b2=i;
		if (v[h]==0) v[h]=i;else 
		{
			if (v[h]>b2) k2=0;else k2=i-v[h];
			break;
		}
	}
	
	if (b1==-1||b2==-1) 
	{
		printf("-1\n");
		return 0;
	}
	
	if (k2==0)
	{
		if (k1==0)
		{
			if (b1==b2) printf("%d\n",b2);else printf("-1\n");
			return 0;
		}
		if (b2>=b1&&(b2-b1)%k1==0) printf("%d\n",b2);else printf("-1\n");
		return 0;
	}
	for (int i=0;i<=m;i++)
	if ((1LL*k1*i+b1-b2)%k2==0&&(1LL*k1*i+b1-b2)/k2>=0)
	{
		printf("%I64d\n",1LL*k1*i+b1);
		return 0;
	}
	printf("-1\n");
	return 0;
}
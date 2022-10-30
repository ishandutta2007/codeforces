#include<cstdio>
#include<iostream>
using namespace std;
int a[101000],b[100010];
int n,p,q;
int check(int mid)
{
	int j=1;
	for (int i=1;i<=p;i++)
	{
		int k=j;
		while (j<=q) 
		{
			if (b[j]<=a[i]) 
			{
				if (a[i]-b[k]>mid) break;
			}
			else if (b[k]<a[i])
			{
				if (a[i]-b[k]+b[j]-b[k]>mid&&b[j]-a[i]+b[j]-b[k]>mid) break;
			}
			else
			{
				if (b[j]-a[i]>mid) break;
			}
			j++;
		}
		if (j>q) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char ch;
		while ((ch=getchar())<=32);
		if (ch=='*') b[++q]=i;
		if (ch=='P') a[++p]=i;
	}
	int l=0,r=n*2+10;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
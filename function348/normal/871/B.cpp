#include<cstdio>
#include<iostream>
using namespace std;
const int N=5010;
int n,ans;
int a[N],b[N],c[N],d[N],u[N];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("? %d %d\n",0,i);
		fflush(stdout);
		scanf("%d",&b[i]);
	}
	for (int i=1;i<n;i++)
	{
		printf("? %d %d\n",i,0);
		fflush(stdout);
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++)
	{
		c[0]=i;
		for (int j=0;j<n;j++) d[j]=c[0]^b[j];
		for (int j=1;j<n;j++) c[j]=d[0]^a[j];
		int t=1;
		for (int j=0;j<n;j++)
			if (d[c[j]]!=j) t=0;
		if (t) 
		{
			ans++;
			if (ans==1) 
				for (int j=0;j<n;j++) u[j]=c[j];
		}
	}
	printf("!\n");
	printf("%d\n",ans);
	for (int i=0;i<n;i++) printf("%d ",u[i]);
	return 0;
}
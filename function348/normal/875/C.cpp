#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
struct Edge{int y,ne;};
int n,m,num,len1,len2,flag;
int a[N],b[N],c[N],v[N];
Edge e[N*10];int last[N];
void add(int x,int y)
{
	e[++num]=(Edge){y,last[x]};last[x]=num;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&len1);
	for (int i=1;i<=len1;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) c[i]=-1;
	for (int j=2;j<=n;j++)
	{
		scanf("%d",&len2);
		for (int i=1;i<=len2;i++) scanf("%d",&b[i]);
		int t=0;
		for (int i=1;i<=min(len1,len2);i++)
		if (a[i]!=b[i]) 
		{
			if (a[i]<b[i]) add(a[i],b[i]);
			else 
			{
				if (c[a[i]]==0||c[b[i]]==1) flag=1;
				else c[a[i]]=1,c[b[i]]=0;
			}
			t=1;break;
		}
		if (!t) 
		if (len1>len2) flag=1;
		len1=len2;
		for (int i=1;i<=len2;i++) a[i]=b[i];
	}
	if (flag) printf("No\n");else
	{
		for (int i=1;i<=m;i++)
		{
			if (c[i]==-1) c[i]=1;
			if (c[i]==0)
			{
				for (int j=last[i];j;j=e[j].ne)
				if (c[e[j].y]==1) flag=1;else c[e[j].y]=0;
			}
		}
		if (flag) printf("No\n");
		else
		{
			int k=0;
			for (int i=1;i<=m;i++) 
			if (c[i]==1) k++;
			printf("Yes\n%d\n",k);
			for (int i=1;i<=m;i++) 
			if (c[i]==1) printf("%d ",i);
		}
	}
	return 0;
}
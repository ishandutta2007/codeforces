#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000000;
typedef long long LL;
struct Edge {int x,y,z,ne;};
Edge e[N*2];int last[N];
int a[N],b[N];
int n;
int t1,t2,t3;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char ch;
		while ((ch=getchar())<=32);
		if (ch=='|') a[i]=0;
		if (ch=='&') a[i]=1;
		if (ch=='^') a[i]=2;
		scanf("%d",&b[i]);
	}
	for (int j=0;j<=9;j++)
	{
		int k1=-1,k2=0;
		for (int i=1;i<=n;i++)
		if (a[i]==0)
		{
			if (b[i]&(1<<j)) k1=1,k2=0;
		}
		else if (a[i]==1)
		{
			if ((b[i]&(1<<j))==0) k1=0,k2=0;
		}
		else k2^=(b[i]>>j)&1;
		if (k1==-1) t2|=1<<j;else
		if (k1==1) t1|=1<<j,t2|=1<<j;
		if (k2) t3|=1<<j;
	}
	printf("3\n| %d\n& %d\n^ %d\n",t1,t2,t3);
	return 0;
}
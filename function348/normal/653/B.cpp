#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,q;
int c[100][100];
int f[100],g[100];
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		char ch;
		int x,y,z;
		while ((ch=getchar())<=32);x=ch-'a';
		while ((ch=getchar())<=32);y=ch-'a';
		while ((ch=getchar())<=32);z=ch-'a';
		c[z][x]++;
	}
	f[0]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<6;j++)
		for (int k=0;k<6;k++)
			g[k]+=f[j]*c[j][k];
		for (int j=0;j<6;j++) f[j]=g[j],g[j]=0;
	}
	int ans=0;
	for (int i=0;i<6;i++) ans+=f[i];
	printf("%d\n",ans);
	return 0;
}
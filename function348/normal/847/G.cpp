#include<cstdio>
#include<iostream>
using namespace std;
int a[1000],c[1000],v[1000];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=7;j++)
	{
		char ch;
		while ((ch=getchar())<=32);
		c[j]+=ch-48;
	}
	int ans=0;
	for (int i=1;i<=7;i++) ans=max(ans,c[i]);
	printf("%d\n",ans);
}
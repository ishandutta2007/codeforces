#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,k;
char buf[233];
int fl[233];
int pa[233];
int find(int x)
{
	return pa[x]?pa[x]=find(pa[x]):x;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=k;i<=n;i++)
	{
		scanf(" %s",buf);
		if(buf[0]=='N')pa[i]=i-k+1;
	}
	for(int i=1;i<=n;i++)
	{
		int p=find(i);
		printf("%c%c ",p/10+'A',p%10+'a');
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n,m,ans,i,j;

struct node{
	int a;
	int q[27];
	int mmax;
}b[1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("\n");
		for(j=0;j<m;j++)
		{
			char c;
			scanf("%c",&c);
			b[j].q[c-'A']++;
			b[j].mmax=max(b[j].mmax,b[j].q[c-'A']);
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i].a);
		ans+=b[i].a*b[i].mmax;
	}
	printf("%d",ans);
	return 0;
}
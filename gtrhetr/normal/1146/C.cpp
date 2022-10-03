#include<bits/stdc++.h>
using namespace std;

int h1[110],h2[110],t,n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();
		int ans=0;
		for (int i=0;i<7;i++)
		{
			int t1=0,t2=0;
			for (int j=1;j<=n;j++) if ((j>>i)&1) h1[++t1]=j;else h2[++t2]=j;
			if (!t1||!t2) continue;
			printf("%d %d ",t1,t2);
			for (int j=1;j<=t1;j++) printf("%d ",h1[j]);
			for (int j=1;j<=t2;j++) printf("%d ",h2[j]);
			puts("");
			fflush(stdout);
			int hh=rd();
			ans=max(ans,hh);
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return 0;
}
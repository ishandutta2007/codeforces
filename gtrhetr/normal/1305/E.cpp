#include<bits/stdc++.h>
using namespace std;
 
int f[5010];
int n,m;
 
int main()
{
	scanf("%d%d",&n,&m);
	if (!m)
	{
		for (int i=1;i<=n;i++) printf("%d ",n+i);
		puts("");
		return 0;
	}
	for (int i=1;i<=n;i++) f[i]=f[i-1]+((i-1)>>1);
	if (f[n]<m) { puts("-1");return 0; }
	for (int i=1;i<=n;i++) if (f[i]>=m)
	{
		for (int j=1;j<i;j++) printf("%d ",j);
		for (int j=i;;j++)
		{
			int hh=(i-1)-(j-i);
			if (hh/2+f[i-1]==m)
			{
				printf("%d ",j);
				break;
			}
		}
		for (int j=i+1;j<=n;j++) printf("%d ",1000000000-(n-j)*n*2);
		puts("");
		return 0;
	}
	return 0;
}
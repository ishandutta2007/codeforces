#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,a[111111],cnt[111111],num;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		cnt[a[i]]++;
		if (cnt[a[i]]==1) num++;
		if (num==n)
		{
			printf("1");
			for (int j=1;j<=n;j++)
			{
				cnt[j]--;
				if (!cnt[j]) num--;
			}
		}
		else printf("0");
	}
	printf("\n");
	return Accepted;
}
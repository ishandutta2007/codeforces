#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333

int mn[100010],mx[100010];
int num[100010],n,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=k;i++) num[i]=rd();
	for (int i=1;i<=n;i++) mn[i]=inf;
	for (int i=1;i<=k;i++) mn[num[i]]=min(mn[num[i]],i),mx[num[i]]=i;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (!mx[i]) { ans+=(i==1||i==n)?2:3;continue; }
		if (i>1&&mn[i]>mx[i-1]) ans++;
		if (i<n&&mn[i]>mx[i+1]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
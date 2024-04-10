#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n,m,d;
int a[N],v[N*12],cnt[N];
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		while (x--)
		{
			int y;scanf("%d",&y);
			a[y]=i;
		}
	}
	
	int p=0,k=1<<m,ans=m+1;
	for (int i=0;i<k;i++) v[i]=1;
	for (int i=1;i<=n;i++)
	{
		if (i>=d) { cnt[a[i-d]]--;if (cnt[a[i-d]]==0) p^=1<<(a[i-d]-1);}
		cnt[a[i]]++;if (cnt[a[i]]==1) p^=1<<(a[i]-1);
		if (i>=d) v[k-1-p]=0;
	}
	for (int i=k-1;i>=0;i--)
	if (!v[i])
	{
		for (int j=0;j<m;j++)
		if ((i|(1<<j))==i) v[i-(1<<j)]=0;
	}
	else
	{
		int tmp=0;
		for (int j=0;j<m;j++)
		if ((i|(1<<j))==i) tmp++;
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
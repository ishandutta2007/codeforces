#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define MP make_pair
using namespace std;
const int N=11100;
typedef pair<int,int> PII;
int n,m,k,a,cnt,tot;
int c[N],last[N],id[N],ans[N];
int cmp(int i,int j) { return c[i]>c[j]||(c[i]==c[j]&&last[i]<last[j]);}
int main()
{
	scanf("%d%d%d%d",&n,&k,&m,&a);
	for (int i=1;i<=a;i++) 
	{
		int x;
		scanf("%d",&x);
		c[x]++;last[x]=i;
	}
	if (n==1)
	{
		printf("1\n");
		return 0;
	}
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++) ans[i]=2;
	if (a==m)
	{
		for (int i=1;i<=k;i++)
		if (c[id[i]]>0) ans[id[i]]=1;else ans[id[i]]=3;
		for (int i=k+1;i<=n;i++) ans[id[i]]=3;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			c[i]+=m-a;
			cnt=0;
			for (int j=1;j<=n;j++)
			if (c[j]>=c[i]) cnt++;
			if (cnt>k) ans[i]=3;
			c[i]-=m-a;
		}
		for (int i=1;i<=n;i++)
		if (c[i]>0)
		{
			cnt=tot=0;
			if (k==n) { ans[i]=1;continue;}
			for (int j=1;j<=n;j++)
			{
				if (id[j]==i) continue;
				tot++;
				if (last[id[j]]<=last[i])
				{
					if (c[id[j]]<c[i]) cnt+=c[i]+1-c[id[j]];
				}
				else
				{
					if (c[id[j]]<=c[i]) cnt+=c[i]+1-c[id[j]];
				}
				if (tot==k) break;
			}
			if (cnt>m-a) ans[i]=1;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
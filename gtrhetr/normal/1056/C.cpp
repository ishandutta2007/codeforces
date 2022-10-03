#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

pii h[1010];

int num[2010],val[2010],from[2010],to[2010],n,m,tt;
bool bo[2010],vis[2010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n*2;i++) num[i]=rd();
	for (int i=1;i<=m;i++)
	{
		h[i].first=rd(),h[i].second=rd(),bo[h[i].first]=bo[h[i].second]=true;
		to[h[i].first]=h[i].second;
		to[h[i].second]=h[i].first;
	}
	int t=rd(),lst=0;
	if (t==2) { lst=rd();vis[lst]=true; }
	for (int hhh=t;hhh<=n*2;hhh++)
	{
		if ((hhh-t)&1) { lst=rd();vis[lst]=true;continue; }
		if (lst&&to[lst]&&!vis[to[lst]])
		{
			int x=to[lst];
			vis[x]=true;printf("%d\n",x);
			fflush(stdout);
			continue;
		}
		int mx=0,id=0;
		for (int i=1;i<=n*2;i++) if (!vis[i])
		{
			if (to[i]&&vis[to[i]]) continue;
			if (to[i])
			{
				if (num[i]<num[to[i]]) continue;
				id=i;break;
			}
		}
		if (!id)
		{
			for (int i=1;i<=n*2;i++) if (!to[i]&&!vis[i])
			{
				if (num[i]>mx) mx=num[i],id=i;
			}
		}
		printf("%d\n",id);vis[id]=true;
		fflush(stdout);
	}
	return 0;
}
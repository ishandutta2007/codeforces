#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct node { int t,id,next; }a[1000010];

pii h[300010];

int head[100010],d[100010],col[300010],num[300010],n,m,tt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].id=z;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x)
{
	for (int &i=head[x];i;i=a[i].next)
	{
		int now=a[i].id;
		if (col[now]) continue;
		col[now]=(x==h[now].first)?1:2;
		dfs(a[i].t);num[++tt]=now;
	}
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();h[i]=pii(x,y);
		add(x,y,i);add(y,x,i);
		d[x]++;d[y]++;
	}
	int lst=0;
	for (int i=1;i<=n;i++) if (d[i]&1)
	{
		if (!lst) lst=i;
		else
		{
			h[++m]=pii(lst,i);
			add(lst,i,m);add(i,lst,m);
			lst=0;
		}
	}
	if (m&1) h[++m]=pii(1,1),add(1,1,m),add(1,1,m);
	tt=0;dfs(1);
	for (int i=1;i<=tt;i+=2) col[num[i]]=((col[num[i]]-1)^1)+1;
	printf("%d\n",m);
	for (int i=1;i<=m;i++)
	{
		if (col[i]==1) printf("%d %d\n",h[i].first,h[i].second);
		else printf("%d %d\n",h[i].second,h[i].first);
	}
	return 0;
}
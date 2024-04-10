#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[2010];

int head[1010],num[1010],t,n,k1,k2,tot;
bool bo[1010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline int dfs(int x,int y)
{
	if (bo[x]) return x;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		int res=dfs(t,x);
		if (res) return res;
	}
	return 0;
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();tot=0;
		memset(head,0,sizeof(head));
		for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
		k1=rd();
		memset(bo,false,sizeof(bo));
		for (int i=1;i<=k1;i++) bo[rd()]=true;
		k2=rd();
		for (int i=1;i<=k2;i++) num[i]=rd();
		printf("B %d\n",num[1]);
		fflush(stdout);
		int hh=rd();
		if (bo[hh]) { printf("C %d\n",hh);fflush(stdout);continue; }
		int now=dfs(hh,0);
		printf("A %d\n",now);
		fflush(stdout);
		int x=rd();
		bool flag=false;
		for (int i=1;i<=k2;i++) if (x==num[i]) flag=true;
		if (flag) printf("C %d\n",now);
		else printf("C -1\n");
		fflush(stdout);
	}
	return 0;
}
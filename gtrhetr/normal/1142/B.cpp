#include<bits/stdc++.h>
using namespace std;

int mx[800010];
int fa[200010][20],id[200010];
int lst[200010],pos[200010],dep[200010];
int p[200010],num[200010],n,m,q;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int jump(int x,int y)
{
	for (int i=19;~i;i--) if ((y>>i)&1) x=fa[x][i];
	return x;
}

inline void build(int o,int l,int r)
{
	if (l==r) { mx[o]=id[l];return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}

inline int query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mx[o];
	int mid=(l+r)>>1,res=0;
	if (x<=mid) res=max(res,query(o<<1,l,mid,x,y));
	if (y>mid) res=max(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}

inline void pre_gao()
{
	for (int i=1;i<=n;i++) pos[p[i]]=i;
	for (int i=1;i<=m;i++)
	{
		int hh=pos[num[i]];
		int pre=(hh==1)?p[n]:p[hh-1];
		if (lst[pre]) fa[i][0]=lst[pre];
		dep[i]=dep[fa[i][0]]+1;
		lst[num[i]]=i;
	}
	for (int i=1;i<=m;i++) for (int j=1;j<20;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=1;i<=m;i++) if (dep[i]>=n) id[i]=jump(i,n-1);
	build(1,1,m);
}

int main()
{
	n=rd();m=rd();q=rd();
	for (int i=1;i<=n;i++) p[i]=rd();
	for (int i=1;i<=m;i++) num[i]=rd();
	pre_gao();
	while (q--)
	{
		int x=rd(),y=rd();
		if (query(1,1,m,x,y)>=x) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}
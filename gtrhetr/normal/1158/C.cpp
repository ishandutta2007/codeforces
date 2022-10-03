#include<bits/stdc++.h>
using namespace std;

int mx[2000010];
int to[500010],ans[500010],t,n;
bool bo[500010];

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void build(int o,int l,int r)
{
	mx[o]=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}

inline void modify(int o,int l,int r,int x,int y)
{
	mx[o]=max(mx[o],y);
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y);
	else modify(o<<1|1,mid+1,r,x,y);
}

inline int query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mx[o];
	int mid=(l+r)>>1,res=0;
	if (x<=mid) res=max(res,query(o<<1,l,mid,x,y));
	if (y>mid) res=max(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();
		for (int i=1;i<=n;i++) to[i]=rd();
		for (int i=1;i<=n;i++) if (to[i]==-1) to[i]=i+1;
		build(1,1,n);
		for (int i=1;i<=n;i++) modify(1,1,n,i,to[i]);
		bool flag=true;
		for (int i=1;i<=n;i++) if (query(1,1,n,i,to[i]-1)>to[i]) { flag=false;break; }
		if (!flag) { puts("-1");continue; }
		int now=n;
		for (int i=1;i<=n;i++) bo[i]=false;bo[n+1]=true;
		for (int i=1;i<=n;i++) if (!bo[i])
		{
			int tt=0;
			for (int j=i;!bo[j];j=to[j]) tt++;
			int hh=tt;
			for (int j=i;!bo[j];j=to[j]) ans[j]=now-hh+1,hh--,bo[j]=true;
			now-=tt;
		}
		for (int i=1;i<=n;i++) print(ans[i]);
		putchar('\n');
	}
	return 0;
}
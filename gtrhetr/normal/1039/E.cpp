#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct hhhh { int x,id; }a[100010];

const int SIZE=50;

pii h[6000010];

int mx[100010][20],mn[100010][20],minn[100010],maxn[100010];
int num[100010],r[100010],ans[100010],n,w,m,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }
inline int max(const int &x,const int &y) { return (x>y)?x:y; }

namespace lct
{

int ch[100010][2],fa[100010],size[200010];

inline bool isroot(const int &x) { return (ch[fa[x]][0]!=x)&&(ch[fa[x]][1]!=x); }

inline void pushup(const int &x) { size[x]=size[ch[x][0]]+size[ch[x][1]]+1; }

inline void rotate(int x)
{
	int y=fa[x],z=fa[y],l=(ch[y][1]==x);
	if (!isroot(y)) ch[z][ch[z][1]==y]=x;
	ch[y][l]=ch[x][l^1];ch[x][l^1]=y;
	fa[ch[y][l]]=y;fa[y]=x;fa[x]=z;
	pushup(y);pushup(x);
}

inline void splay(int x)
{
	while (!isroot(x))
	{
		int y=fa[x],z=fa[y];
		if (!isroot(y))
		{
			if ((ch[y][0]==z)^(ch[z][0]==y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}

inline void access(int x) { for (int y=0;x;y=x,x=fa[x]) splay(x),ch[x][1]=y,pushup(x); }

inline void link(int x,int y) { access(x);splay(x);fa[x]=y; }

inline void cut(int x)
{
	access(x);splay(x);
	fa[ch[x][0]]=0;ch[x][0]=0;
	pushup(x);
}

inline pii query(int x)
{
	access(x);splay(x);
	for (;ch[x][0];x=ch[x][0]);
	splay(x);
	return pii(x,size[x]);
}

}

inline void pre_gao()
{
	for (int i=1;i<=n;i++) mx[i][0]=mn[i][0]=num[i];
	for (int j=1;j<17;j++) for (int i=1;i<=n;i++)
	{
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
	}
	tt=0;
	for (int i=1;i<=n;i++)
	{
		int h1=num[i],h2=num[i];
		minn[i]=maxn[i]=num[i];
		for (int j=i+1;j<=n&&j<=i+SIZE+1;j++)
		{
			h1=min(h1,num[j]);
			h2=max(h2,num[j]);
			h[++tt]=pii(h2-h1,i);
		}
	}
	for (int i=1;i<=n;i++) lct::size[i]=1,r[i]=i;
	for (int i=1;i<n;i++) lct::fa[i]=i+1;
}

inline int jump(int x,int y)
{
	for (int j=16;~j;j--) if (r[x]+(1<<j)<=n)
	{
		int h1=min(minn[x],mn[r[x]+1][j]),h2=max(maxn[x],mx[r[x]+1][j]);
		if (h2-h1<=y) minn[x]=h1,maxn[x]=h2,r[x]+=(1<<j);
	}
	return r[x]+1;
}

inline bool cmp(const hhhh &x,const hhhh &y) { return x.x<y.x; }

inline int gao(int now)
{
	int x=1,res=0;
	while (x<=n)
	{
		pii hh=lct::query(x);
		if (hh.first!=x) res+=hh.second-1,x=hh.first;
		else x=jump(x,now),res++;
	}
	return res-1;
}

int main()
{
	n=rd();w=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	pre_gao();
	sort(h+1,h+tt+1);
	for (int i=1;i<=m;i++) a[i]=(hhhh){w-rd(),i};
	sort(a+1,a+m+1,cmp);
	int now=1;
	for (int i=1;i<=m;i++)
	{
		for (;now<=tt&&h[now].first<=a[i].x;now++)
		{
			int x=h[now].second;
			r[x]++;
			minn[x]=min(minn[x],num[r[x]]);
			maxn[x]=max(maxn[x],num[r[x]]);
			lct::cut(x);
			if (r[x]<=n&&r[x]-x<=SIZE) lct::link(x,r[x]+1);
		}
		ans[a[i].id]=gao(a[i].x);
	}
	for (int i=1;i<=m;i++) print(ans[i]);
	return 0;
}
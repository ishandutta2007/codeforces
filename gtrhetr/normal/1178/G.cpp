#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define inf 2333333333333333333LL

vector<int> v[200010];

ll h1[200010],h2[200010];
int fa[200010],dfn[200010],out[200010],pid[200010],n,m,cl;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline ll abs1(const ll &x) { return (x<0)?-x:x; }

struct point
{
	ll x,y;
	point(ll xx=0,ll yy=0):x(xx),y(yy) {}
};

inline point operator -(const point &x,const point &y) { return point(x.x-y.x,x.y-y.y); }
inline lll cross(const point &x,const point &y) { return (lll)x.x*y.y-(lll)x.y*y.x; }
inline ll calc(const point &x,const ll &y) { return x.x*y+x.y; }

inline void pre_dfs(int x)
{
	dfn[x]=++cl;pid[cl]=x;
	for (int t:v[x]) h1[t]+=h1[x],h2[t]+=h2[x],pre_dfs(t);
	out[x]=cl;
}

point st1[510][510],st2[510][510];

int top1[510],top2[510],now1[510],now2[510];

ll mn[510],tag[510];
int h[510][510],len[510];
int st[510],ed[510],from[200010],sq,block;

inline bool cmp(const int &x,const int &y) { return h2[x]<h2[y]; }

inline void build(int *h,int len,point *st1,int &top1,point *st2,int &top2,int &now1,int &now2)
{
	top1=top2=0;
	for (int i=1;i<=len;i++)
	{
		int x=h[i];
		if (h1[x]<0)
		{
			point hh(h2[x],-h1[x]*h2[x]);
			if (top1&&hh.x==st1[top1].x) { hh.y=max(st1[top1].y,hh.y);top1--; }
			while (top1>1&&cross(st1[top1]-st1[top1-1],hh-st1[top1-1])>=0) top1--;
			st1[++top1]=hh;
		}
		else
		{
			point hh(h2[x],h1[x]*h2[x]);
			if (top2&&hh.x==st2[top2].x) { hh.y=max(st2[top2].y,hh.y);top2--; }
			while (top2>1&&cross(st2[top2]-st2[top2-1],hh-st2[top2-1])>=0) top2--;
			st2[++top2]=hh;
		}
	}
	now1=top1;
	while (now1-1>0&&st1[now1-1].y>=st1[now1].y) now1--;
	now2=1;
	while (now2+1<=top2&&st2[now2+1].y>=st2[now2].y) now2++;
}

inline void rebuild(int id)
{
	for (int i=st[id];i<=ed[id];i++) h1[pid[i]]+=tag[id];
	mn[id]=inf;tag[id]=0;
	for (int i=st[id];i<=ed[id];i++) if (h1[pid[i]]<0) mn[id]=min(mn[id],-h1[pid[i]]);
	build(h[id],len[id],st1[id],top1[id],st2[id],top2[id],now1[id],now2[id]);
}

inline void modify(int id,int l,int r,ll y)
{
	for (int i=max(st[id],l);i<=min(ed[id],r);i++) h1[pid[i]]+=y;
	rebuild(id);
}

inline ll query(int id,int l,int r)
{
	ll res=0;
	for (int i=max(st[id],l);i<=min(ed[id],r);i++) res=max(res,abs1(h1[pid[i]]+tag[id])*h2[pid[i]]);
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=2;i<=n;i++) v[fa[i]=rd()].push_back(i);
	for (int i=1;i<=n;i++) h1[i]=rd();
	for (int i=1;i<=n;i++) h2[i]=rd();
	cl=0;pre_dfs(1);
	for (int i=1;i<=n;i++) h2[i]=abs1(h2[i]);
	sq=sqrt(n);block=0;
	for (int i=1;i<=n;i+=sq)
	{
		st[++block]=i;ed[block]=min(i+sq-1,n);
		for (int j=st[block];j<=ed[block];j++) from[j]=block;
	}
	for (int i=1;i<=block;i++)
	{
		len[i]=0;
		for (int j=st[i];j<=ed[i];j++) h[i][++len[i]]=pid[j];
		sort(h[i]+1,h[i]+len[i]+1,cmp);
		mn[i]=inf;tag[i]=0;
		for (int j=st[i];j<=ed[i];j++) if (h1[pid[j]]<0) mn[i]=min(mn[i],-h1[pid[j]]);
		build(h[i],len[i],st1[i],top1[i],st2[i],top2[i],now1[i],now2[i]);
	}
	while (m--)
	{
		int p=rd(),x=rd();
		if (p==1)
		{
			ll y=rd();int l=from[dfn[x]],r=from[out[x]];
			if (l==r) modify(l,dfn[x],out[x],y);
			else
			{
				modify(l,dfn[x],out[x],y);
				modify(r,dfn[x],out[x],y);
				for (int i=l+1;i<r;i++)
				{
					tag[i]+=y;
					if (tag[i]>=mn[i]) rebuild(i);
					else
					{
						while (now1[i]-1>0&&calc(st1[i][now1[i]-1],-tag[i])>=calc(st1[i][now1[i]],-tag[i])) now1[i]--;
						while (now2[i]+1<=top2[i]&&calc(st2[i][now2[i]+1],tag[i])>=calc(st2[i][now2[i]],tag[i])) now2[i]++;
					}
				}
			}
		}
		else
		{
			int l=from[dfn[x]],r=from[out[x]];ll ans=0;
			if (l==r) ans=query(l,dfn[x],out[x]);
			else
			{
				ans=max(ans,query(l,dfn[x],out[x]));
				ans=max(ans,query(r,dfn[x],out[x]));
				for (int i=l+1;i<r;i++)
				{
					if (top1[i]) ans=max(ans,calc(st1[i][now1[i]],-tag[i]));
					if (top2[i]) ans=max(ans,calc(st2[i][now2[i]],tag[i]));
				}
			}
			print(ans);
		}
	}
	return 0;
}
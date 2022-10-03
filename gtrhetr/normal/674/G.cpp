#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int num[150010],n,q,p;

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

pii res[600010][6],ans[6];
int tag[600010];

inline void merge(pii *res,pii *b)
{
	for (int i=1;i<=p;i++) if (b[i].second)
	{
		int id=0;
		for (int j=1;j<=p;j++) if (res[j].second&&res[j].first==b[i].first) { id=j;break; }
		if (id) res[id].second+=b[i].second;
		else
		{
			int mn=b[i].second;
			for (int j=1;j<=p;j++) mn=min(mn,res[j].second);
			for (int j=1;j<=p;j++) res[j].second-=mn;
			if (mn<b[i].second) for (int j=1;j<=p;j++) if (!res[j].second) { res[j]=pii(b[i].first,b[i].second-mn);break; }
		}
	}
}

inline void pushup(const int &o)
{
	for (int i=1;i<=p;i++) res[o][i]=res[o<<1][i];
	merge(res[o],res[o<<1|1]);
}

inline void gao(const int &o,const int &l,const int &r,const int &hh)
{
	tag[o]=hh;
	for (int i=1;i<=p;i++) res[o][i]=pii(0,0);
	res[o][1]=pii(hh,r-l+1);
}

inline void pushdown(const int &o,const int &l,const int &r)
{
	if (!tag[o]) return;
	int mid=(l+r)>>1;
	gao(o<<1,l,mid,tag[o]);
	gao(o<<1|1,mid+1,r,tag[o]);
	tag[o]=0;
}

inline void build(int o,int l,int r)
{
	if (l==r) { res[o][1]=pii(num[l],1);return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { gao(o,l,r,hh);return; }
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) { merge(ans,res[o]);return; }
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if (x<=mid) query(o<<1,l,mid,x,y);
	if (y>mid) query(o<<1|1,mid+1,r,x,y);
}

int main()
{
	n=rd();q=rd();p=100/rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	build(1,1,n);
	while (q--)
	{
		int op=rd(),l=rd(),r=rd();
		if (op==1) { int x=rd();modify(1,1,n,l,r,x); }
		else
		{
			for (int i=1;i<=p;i++) ans[i]=pii(0,0);
			query(1,1,n,l,r);
			int tt=0;
			for (int i=1;i<=p;i++) if (ans[i].second) tt++;
			print(tt);
			for (int i=1;i<=p;i++) if (ans[i].second) print(ans[i].first);
			putchar('\n');
		}
	}
	return 0;
}
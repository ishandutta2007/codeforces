#include<bits/stdc++.h>
using namespace std;

set<int> st[200010];

int num[200010],n,q;

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

int mn[800010],mx[800010],smn[800010],sl[800010],sr[800010],tag[800010];

inline void pushup(const int &o)
{
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
	if (mn[o<<1]<mn[o<<1|1])
	{
		mn[o]=mn[o<<1];smn[o]=smn[o<<1];
		sl[o]=sl[o<<1];sr[o]=max(sr[o<<1],mx[o<<1|1]);
	}
	else if (mn[o<<1|1]<mn[o<<1])
	{
		mn[o]=mn[o<<1|1];smn[o]=smn[o<<1|1];
		sl[o]=max(mx[o<<1],sl[o<<1|1]);sr[o]=sr[o<<1|1];
	}
	else
	{
		mn[o]=mn[o<<1];smn[o]=smn[o<<1]+smn[o<<1|1]+max(sr[o<<1],sl[o<<1|1]);
		sl[o]=sl[o<<1];sr[o]=sr[o<<1|1];
	}
}

inline void gao(const int &o,const int &hh) { mn[o]+=hh;tag[o]+=hh; }

inline void pushdown(const int &o)
{
	if (!tag[o]) return;
	gao(o<<1,tag[o]);gao(o<<1|1,tag[o]);
	tag[o]=0;
}

inline void update(int o,int l,int r,int x,int y)
{
	if (l==r) { mx[o]+=y;sl[o]+=y;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) update(o<<1,l,mid,x,y);
	else update(o<<1|1,mid+1,r,x,y);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { gao(o,hh);return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void del(int x,int y)
{
	if (st[y].size()==1)
	{
		update(1,1,n,*st[y].begin(),-1);
		st[y].clear();
		return;
	}
	if (x==*st[y].begin())
	{
		set<int>::iterator it=st[y].begin();it++;
		modify(1,1,n,x,(*it)-1,-1);
		update(1,1,n,x,-st[y].size());
		update(1,1,n,*it,st[y].size()-1);
		st[y].erase(x);
		return;
	}
	if (x==*st[y].rbegin())
	{
		set<int>::iterator it=st[y].find(x);it--;
		modify(1,1,n,*it,x-1,-1);
		update(1,1,n,*st[y].begin(),-1);
		st[y].erase(x);
		return;
	}
	update(1,1,n,*st[y].begin(),-1);
	st[y].erase(x);
}

inline void add(int x,int y)
{
	if (!st[y].size())
	{
		update(1,1,n,x,1);
		st[y].insert(x);
		return;
	}
	if (x<*st[y].begin())
	{
		set<int>::iterator it=st[y].begin();
		modify(1,1,n,x,(*it)-1,1);
		update(1,1,n,x,st[y].size()+1);
		update(1,1,n,*it,-st[y].size());
		st[y].insert(x);
		return;
	}
	if (x>*st[y].rbegin())
	{
		set<int>::reverse_iterator it=st[y].rbegin();
		modify(1,1,n,*it,x-1,1);
		update(1,1,n,*st[y].begin(),1);
		st[y].insert(x);
		return;
	}
	update(1,1,n,*st[y].begin(),1);
	st[y].insert(x);
}

int main()
{
	n=rd();q=rd();
	for (int i=1;i<=n;i++) num[i]=rd(),st[num[i]].insert(i);
	for (int i=1;i<=200000;i++) if (!st[i].empty())
	{
		update(1,1,n,*st[i].begin(),st[i].size());
		if ((*st[i].begin())!=(*st[i].rbegin())) modify(1,1,n,*st[i].begin(),*st[i].rbegin()-1,1);
	}
	print(n-smn[1]-sl[1]);
	while (q--)
	{
		int x=rd(),y=rd();
		del(x,num[x]);
		add(x,y);num[x]=y;
		print(n-smn[1]-sl[1]);
	}
	return 0;
}
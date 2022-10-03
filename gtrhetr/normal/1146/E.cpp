#include<bits/stdc++.h>
using namespace std;

struct hhhh { int x,id; }h1[100010],h2[100010];
struct tree { int ls,rs,sum; }t[10000010];

vector<int> v1[200010],v2[200010];

int num[100010],rt1[200010],rt2[200010],n,m,t1,t2,tot;
char s[233];

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
	if (x<0) putchar('-'),x=-x;
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void modify(int &o,int l,int r,int x)
{
	int now=++tot;t[now]=t[o];o=now;
	t[o].sum++;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) modify(t[o].ls,l,mid,x);
	else modify(t[o].rs,mid+1,r,x);
}

inline int query(int o,int pre,int l,int r)
{
	if (l==r)
	{
		if (l==1&&t[o].sum-t[pre].sum==0) return 0;
		return l;
	}
	int mid=(l+r)>>1;
	if (t[t[o].rs].sum-t[t[pre].rs].sum>0) return query(t[o].rs,t[pre].rs,mid+1,r);
	return query(t[o].ls,t[pre].ls,l,mid);
}

inline int querysum(int o,int pre,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return t[o].sum-t[pre].sum;
	int mid=(l+r)>>1,res=0;
	if (x<=mid) res+=querysum(t[o].ls,t[pre].ls,l,mid,x,y);
	if (y>mid) res+=querysum(t[o].rs,t[pre].rs,mid+1,r,x,y);
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		int x=rd();
		if (s[1]=='<') v1[x+100000].push_back(i);
		else v2[x+100000].push_back(i);
	}
	for (int i=0;i<=200000;i++)
	{
		if (i>0) rt1[i]=rt1[i-1];
		for (int j=0;j<v1[i].size();j++) modify(rt1[i],1,m,v1[i][j]);
	}
	for (int i=200000;i>=0;i--)
	{
		rt2[i]=rt2[i+1];
		for (int j=0;j<v2[i].size();j++) modify(rt2[i],1,m,v2[i][j]);
	}
	for (int i=1;i<=n;i++)
	{
		if (num[i]==0) continue;
		int mn,mx;
		if (num[i]>0) mn=-num[i],mx=num[i];
		else mn=num[i],mx=-num[i];
		int h1=query(rt1[mx+100000],rt1[mn+100000],1,m),h2=query(rt2[mn+100000],rt2[mx+100000],1,m);
		int now;
		if (!h1&&!h2) now=num[i];
		else if (h1>h2) now=mx;
		else now=mn;
		int hh=max(h1,h2)+1;
		if (hh<=m)
		{
			int s1=querysum(rt1[200000],rt1[mx+100000],1,m,hh,m),s2=querysum(rt2[0],rt2[mn+100000],1,m,hh,m);
			if ((s1+s2)&1) now=-now;
		}
		num[i]=now;
	}
	for (int i=1;i<=n;i++) print(num[i]);
	putchar('\n');
	return 0;
}
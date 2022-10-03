#include<bits/stdc++.h>
using namespace std;

struct cloud { int l,r,c; }c[300010];
struct node { int x,p,id; }a[600010];
struct hhhh { int k,id; }h[300010];

unordered_map<int,int> mp[300010];
set<int> st;

int ans[300010],len[300010],mx[300010],n,m,q,tt;
bool vis[300010];

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

namespace sgt
{

int mx[1200010];

inline void modify(int o,int l,int r,int x,int hh)
{
	mx[o]=max(mx[o],hh);
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,hh);
	else modify(o<<1|1,mid+1,r,x,hh);
}

inline int query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mx[o];
	int mid=(l+r)>>1,res=0;
	if (x<=mid) res=max(res,query(o<<1,l,mid,x,y));
	if (y>mid) res=max(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}

}

inline bool operator <(const cloud &x,const cloud &y) { return x.c<y.c; }
inline bool operator <(const node &x,const node &y) { return x.x<y.x; }
inline bool operator <(const hhhh &x,const hhhh &y) { return x.k<y.k; }

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) c[i].l=rd(),c[i].r=rd(),c[i].c=rd();
	sort(c+1,c+n+1);
	tt=0;
	for (int i=1;i<=n;i++) a[++tt]=(node){c[i].l,1,i},a[++tt]=(node){c[i].r,0,i};
	sort(a+1,a+tt+1);
	a[++tt]=(node){2000000000,1,0};
	q=rd();
	for (int i=1;i<=q;i++) h[i].k=rd(),h[i].id=i;
	sort(h+1,h+q+1);
	int now=1,all=0,emp=0,del=0;
	for (int i=1;i<=tt;i++)
	{
		int hh=a[i].x-all;all=a[i].x;
		if (st.empty()) emp+=hh;
		else if (st.size()==1)
		{
			int x=*st.begin();
			len[x]+=hh;mx[x]+=hh;
			sgt::modify(1,1,n,x,len[x]);
			if (!vis[x]&&c[x].c<=m)
			{
				int l=1,r=upper_bound(c+1,c+n+1,(cloud){0,0,m-c[x].c})-c-1;
				int res=0;
				if (x>=l&&x<=r)
				{
					if (l<x) res=max(res,sgt::query(1,1,n,l,x-1));
					if (r>x) res=max(res,sgt::query(1,1,n,x+1,r));
				}
				else if (l<=r) res=max(res,sgt::query(1,1,n,l,r));
				mx[x]=max(mx[x],res+len[x]);
				vis[x]=true;
			}
			if (c[x].c<=m) del=max(del,mx[x]);
		}
		else if (st.size()==2)
		{
			int x=*st.begin(),y=*st.rbegin();
			if (c[x].c+c[y].c<=m)
			{
				mp[x][y]+=hh;
				int res=len[x]+len[y]+mp[x][y];
				mx[x]=max(mx[x],res);
				mx[y]=max(mx[y],res);
				del=max(del,res);
			}
		}
		for (;now<=q&&emp+del>=h[now].k;now++) ans[h[now].id]=h[now].k+(all-emp-del);
		if (a[i].p==1) st.insert(a[i].id);
		else st.erase(a[i].id);
	}
	for (int i=1;i<=q;i++) print(ans[i]);
	return 0;
}
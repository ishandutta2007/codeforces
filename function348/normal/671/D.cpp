#include<bits/stdc++.h>
#define pb push_back
typedef long long LL;
using namespace std;
const int N=1000010;
const LL inf=1e+18;
struct Edge {int y,ne;};
int n,m,num;
LL s[N*4],tag[N*4],f[N];
int dfn[N],ed[N],t[N],c[N];
Edge e[N*2];int last[N];
vector<int> ins[N],del[N];
void change(int i,int l,int r,int k,LL d)
{
	if (l==r) { s[i]=min(s[i]+d,inf);return;}
	int mid=(l+r)>>1;
	if (k<=mid) change(i*2,l,mid,k,d);
	if (k> mid) change(i*2+1,mid+1,r,k,d);
	s[i]=min(min(s[i*2],s[i*2+1])+tag[i],inf);
}
void change(int i,int l,int r,int ll,int rr,LL d)
{
	if (ll>rr) return;
	if (ll<=l&&r<=rr) { tag[i]=min(tag[i]+d,inf);s[i]=min(s[i]+d,inf);return;}
	int mid=(l+r)>>1;
	if (ll<=mid) change(i*2,l,mid,ll,rr,d);
	if (rr> mid) change(i*2+1,mid+1,r,ll,rr,d);
	s[i]=min(min(s[i*2],s[i*2+1])+tag[i],inf);
}
LL query(int i,int l,int r,int ll,int rr)
{
	if (ll>rr) return inf;
	if (ll<=l&&r<=rr) return s[i];
	int mid=(l+r)>>1;
	LL res=inf;
	if (ll<=mid) res=min(res,query(i*2,l,mid,ll,rr));
	if (rr> mid) res=min(res,query(i*2+1,mid+1,r,ll,rr));
	return min(res+tag[i],inf);
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs(int i,int fa)
{
	dfn[i]=num+1;
	for (vector<int>::iterator j=ins[i].begin();j!=ins[i].end();j++) t[*j]=++num;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)	dfs(e[j].y,i);
	ed[i]=num;
}
void dp(int i,int fa)
{
	LL all=0;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
	{
		dp(e[j].y,i);
		all=min(all+f[e[j].y],inf);
	}
	if (i==1) { f[i]=all;return;}
	if (all==inf) { f[i]=inf;return;}
	for (vector<int>::iterator j=ins[i].begin();j!=ins[i].end();j++) change(1,1,m,t[*j],all+c[*j]);
	for (vector<int>::iterator j=del[i].begin();j!=del[i].end();j++) change(1,1,m,t[*j],inf);
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa) change(1,1,m,dfn[e[j].y],ed[e[j].y],all-f[e[j].y]);
	f[i]=query(1,1,m,dfn[i],ed[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d%d",&x,&y,&c[i]);
		ins[x].pb(i);
		del[y].pb(i);
	}
	num=0;
	dfs(1,0);
	dp(1,0);
	printf("%lld\n",f[1]!=inf?f[1]:-1);
	return 0;
}
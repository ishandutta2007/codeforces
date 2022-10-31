#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010,p=1000000007;
struct Edge {int y,ne;};
int u[N*4],t[N*4];
int n,m,num;
Edge e[N*2];int last[N];
int dfn[N],size[N],d[N],fa[N];
int kd[N],q[N],v[N];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
int exp(int a,int b,int c)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		b>>=1;a=1LL*a*a%c;
	}
	return d;
}
void dfs(int i)
{
	dfn[i]=++num;size[i]=1;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa[i]) 
	{
		fa[e[j].y]=i;
		dfs(e[j].y);
		size[i]+=size[e[j].y];
	}
}
void down(int i)
{
	if (u[i]==1) return;
	int j=i*2;
	t[j]=1LL*t[j]*u[i]%p;
	u[j]=1LL*u[j]*u[i]%p;
	j=i*2+1;
	t[j]=1LL*t[j]*u[i]%p;
	u[j]=1LL*u[j]*u[i]%p;
	u[i]=1;
}
void build(int i,int l,int r)
{
	t[i]=0;u[i]=1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}
void change1(int i,int l,int r,int ll,int rr,int k)
{
	if (ll<=l&&r<=rr)
	{
		t[i]=1LL*t[i]*k%p;
		u[i]=1LL*u[i]*k%p;
		return;
	}
	down(i);
	int mid=(l+r)>>1;
	if (ll<=mid) change1(i*2,l,mid,ll,rr,k);
	if (rr> mid) change1(i*2+1,mid+1,r,ll,rr,k);
	t[i]=(t[i*2]+t[i*2+1])%p;
}
void change2(int i,int l,int r,int k,int d)
{
	if (l==r)
	{
		t[i]=d;u[i]=1;
		return;
	}
	int mid=(l+r)>>1;
	down(i);
	if (k<=mid) change2(i*2,l,mid,k,d);
	if (k> mid) change2(i*2+1,mid+1,r,k,d);
	t[i]=(t[i*2]+t[i*2+1])%p;
}
int query(int i,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return t[i];
	int res=0,mid=(l+r)>>1;
	down(i);
	if (ll<=mid) res+=query(i*2,l,mid,ll,rr);
	if (rr> mid) res+=query(i*2+1,mid+1,r,ll,rr);
	res%=p;
	return res;
}
int get(int i,int l,int r,int k)
{
	if (l==r) return t[i];
	int mid=(l+r)>>1;
	down(i);
	if (k<=mid) return get(i*2,l,mid,k);
	if (k> mid) return get(i*2+1,mid+1,r,k);
}
int main()
{
	scanf("%d%d",&v[1],&m);
	n=1;
	num=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&kd[i]);
		if (kd[i]==1) 
		{
			n++;
			scanf("%d%d",&q[i],&v[n]);
			add(q[i],n);
		}
		if (kd[i]==2) scanf("%d",&q[i]);
	}
	num=0;
	dfs(1);
	int now=1;
	build(1,1,n);
	change2(1,1,n,dfn[1],v[1]);
	for (int i=1;i<=m;i++)
	{
		
		if (kd[i]==1)
		{
			int j=q[i],kk=1LL*(d[j]+2)*exp(d[j]+1,p-2,p)%p;
			now++;
			change1(1,1,n,dfn[j],dfn[j]+size[j]-1,kk);
			int tmp=1LL*get(1,1,n,dfn[j])*exp(v[j],p-2,p)%p;
			tmp=1LL*tmp*v[now]%p;
			change2(1,1,n,dfn[now],tmp);
			d[j]++;
		}
		if (kd[i]==2)
		{
			int j=q[i];
			int tmp=1LL*v[fa[j]]*exp(get(1,1,n,dfn[fa[j]]),p-2,p)%p;
			if (j==1) tmp=1;
			tmp=1LL*query(1,1,n,dfn[j],dfn[j]+size[j]-1)*tmp%p;
			if (tmp<0) tmp+=p;
			printf("%d\n",tmp);
		}
	}
	return 0;
}
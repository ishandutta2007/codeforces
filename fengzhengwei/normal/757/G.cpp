#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0');if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=7e5+5;//, 
int p[xx];
struct nod{int next,to,v;}e[xx<<1];
int cnt=1,h[xx];// 
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}
vector<pair<int,int> >v[xx];
#define fi first
#define se second
int cst;
void dfs(int x,int y)
{
	int last=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i].fi==y)continue;
		dfs(v[x][i].fi,x);
		if(!last)
		{
			last=x;
			add(last,v[x][i].fi,v[x][i].se);
			add(v[x][i].fi,last,v[x][i].se);
		}
		else 
		{
			cst++;
			add(last,cst,0);
			add(cst,last,0);
			last=cst;
			add(last,v[x][i].fi,v[x][i].se);
			add(v[x][i].fi,last,v[x][i].se);
		}
	}
}
int vis[xx<<1],size[xx],cur,mx,A,B,tt;
void findc(int x,int y)
{
	size[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[i])continue;
		findc(e[i].to,x);
		size[x]+=size[e[i].to];
		if(!cur||mx>max(size[e[i].to],tt-size[e[i].to]))
		{
			mx=max(size[e[i].to],tt-size[e[i].to]);
			A=x,B=e[i].to;
			cur=i;
		}
	}
}
int val[xx*18],op,c[xx*18][2],sz[xx*18][2];
ll V[xx*18][2];//szsigma dis 
vector<pair<int,ll> >s[xx];//0~size 
void get(int x,int y,ll ds)
{
	size[x]=1;s[x].push_back(make_pair(op,ds));
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[i])continue;
		get(e[i].to,x,ds+e[i].v);
		size[x]+=size[e[i].to];
	}
}
int root[xx];
int bfz(int x,int y)
{
//	cout<<x<<" "<<tt<<"\n";
	if(tt==1)return x;
	cur=0,mx=0;
	findc(x,y);
	vis[cur]=vis[cur^1]=1;
	cst++;
	val[cst]=e[cur].v;
	op=0;get(A,B,0);
	op=1;get(B,A,0);
	int a=A,b=B;
	int now=cst;
	tt=size[a];
	c[now][0]=bfz(a,b);
	tt=size[b];
	c[now][1]=bfz(b,a);
	return now;
}
void get(int &w)
{
	cst++;sz[cst][0]=sz[w][0];sz[cst][1]=sz[w][1];
	val[cst]=val[w];V[cst][0]=V[w][0],V[cst][1]=V[w][1];
	c[cst][0]=c[w][0];c[cst][1]=c[w][1];
	w=cst;
}
void insert(int x,int *y)
{
	int *now=y;
//	cout<<now<<"\n";
	for(int i=0;i<s[x].size();i++)
	{
		get(*now);
		sz[*now][s[x][i].fi]++;
		V[*now][s[x][i].fi]+=s[x][i].se;
//	cout<<now<<"\n";
		now=&c[*now][s[x][i].fi];
	}
}
ll ask(int x,int y)
{
	int now=y;
	ll ans=0;
	for(int i=0;i<s[x].size();i++)
	{
		ans+=1ll*(val[now]+s[x][i].se)*(sz[now][s[x][i].fi^1]);
		ans+=V[now][s[x][i].fi^1];
		now=c[now][s[x][i].fi];
	}
	return ans;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		a=read();
		b=read();
		c=read();
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	cst=n;
	dfs(1,0);
	tt=n;
	root[0]=bfz(1,0);
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		insert(p[i],&root[i]);
//		cout<<root[i]<<"ss \n";
//		return 0;
	}
	ll last=0;
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			int a,b,c;
			a=read()^(last%(1<<30));
			b=read()^(last%(1<<30));
			c=read()^(last%(1<<30));
			cout<<(last=(ask(c,root[b])-ask(c,root[a-1])))<<"\n";
		}
		if(op==2)
		{
			int a=read()^(last%(1<<30));
			swap(p[a],p[a+1]);
			root[a]=root[a-1];
			insert(p[a],&root[a]);
			root[a+1]=root[a];
			insert(p[a+1],&root[a+1]);
		}
	}
	return 0;
}
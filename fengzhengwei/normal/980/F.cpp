#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=1e6+5;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
//EB 
// 
int dfn[xx],low[xx],scc,cst,stk[xx],top,bel[xx],n,m;
vector<int>s[xx];// 
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst,stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])tj(e[i].to,i),low[x]=min(low[x],low[e[i].to]);
		else if(i!=(y^1))low[x]=min(low[x],dfn[e[i].to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		while(stk[top]!=x)s[scc].push_back(stk[top]),bel[stk[top--]]=scc;
		s[scc].push_back(stk[top]),bel[stk[top--]]=scc;
	}
}
int vis[xx],id;
void dfS(int x)// 
{
	vis[x]=0;s[id].push_back(x);
	for(int i=h[x];i;i=e[i].next)
		if(vis[e[i].to]){dfS(e[i].to);break;}
}
int f[xx],ds[xx];
// 
void dfs(int x,int y)
{
	f[x]=y;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(bel[e[i].to]==bel[x])continue;
		dfs(e[i].to,x);
		ds[x]=max(ds[x],ds[e[i].to]+1);
	}
	int id=0;
	int len=s[bel[x]].size();
//	cout<<bel[x]<<" "<<s[bel[x]].size()<<"\n";
	for(int i=0;i<len;i++)
	{
		int it=s[bel[x]][i];
		if(it==x)id=i;
		else 
		{
			for(int i=h[it];i;i=e[i].next)//(f0) 
			{
				if(bel[it]!=bel[e[i].to])
				{
					dfs(e[i].to,it);
//					assert(it!=9);
					ds[it]=max(ds[it],ds[e[i].to]+1);// 
				}
			}
		}
	}
	//ds=0 
	for(int i=0;i<len;i++)
	{
		int it=s[bel[x]][i];
		if(it!=x)
		{
			ds[x]=max(ds[x],ds[it]+min(max(i-id,id-i),min(len-i+id,len-id+i)));// 
		}
	}
//	cout<<x<<" !!! "<<ds[x]<<" "<<ds[6]<<" "<<ds[9]<<" "<<ds[8]<<" "<<"\n";
}
// 
int fa[xx];//x() 
struct nod{int mx,se;nod(){mx=se=0;}}G[xx];
//void init(nod &w){w.mx=w.se=-1e9;}init0 
nod upd(nod a,int x)
{
	if(a.mx<x)a.se=a.mx,a.mx=x;
	else a.se=max(a.se,x);
	return a;
}
int get(nod a,int v)
{
	if(a.mx==v)return a.se;
	return a.mx;
}
int ans[xx],val[xx],v[xx],q[xx];//Id 
int Id[xx*3],N;// 
int g(int x,int op)
{
	if(!op)return val[Id[x]]-x;
	return val[Id[x]]+x;
}
int ad(int x,int len,int op)
{
	if(op==0)return x-1;
	return x+(len-1)/2;
}
int er(int x,int len,int op)
{
	if(op==0)return x-len/2;
	return x+1;
}
void run(int len,int op)//op=0=1 
{
	int l=1,r=0;
	for(int i=1;i<=N/3*2;i++)
	{
		//i-1(0) 
		while(l<=r&&g(q[r],op)<g(ad(i,len,op),op))r--;
		q[++r]=ad(i,len,op);
		while(l<=r&&q[l]<er(i,len,op))l++;
		if(l<=r&&i<=N/3*2&&i>N/3)v[Id[i]]=max(v[Id[i]],g(q[l],op)+(!op?i:-i));// 
	}
}
//valxfa+dsds 
void getG(int x)
{
	G[x]=upd(G[x],fa[x]);//Gxfa 
//	if(x==1)
//	{
//		cout<<x<<" qwewqe "<<fa[x]<<"!!!\n";
//	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||bel[e[i].to]==bel[x])continue;
		G[x]=upd(G[x],ds[e[i].to]+1);
	}
}
void getfa(int x)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||bel[e[i].to]==bel[x])continue;
//		if(e[i].to==2)
//		{
//			cout<<G[x].mx<<" "<<G[x].se<<" qweqe "<<get(G[x],ds[e[i].to]+1)<<"\n";
//		}
		fa[e[i].to]=get(G[x],ds[e[i].to]+1)+1;
	}
}
void dp(int x,int y)
{
	int len=s[bel[x]].size();
	//ans 
	//() 
	int V=-1e9;//ds 
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(bel[e[i].to]==bel[x])continue;
		V=max(V,ds[e[i].to]+1);
	}
	//x-len/2~x-1
	//x+1~x+(len-1)/2 
	N=0;//val 
	for(auto it:s[bel[x]])Id[++N]=it;
	for(auto it:s[bel[x]])Id[++N]=it;
	for(auto it:s[bel[x]])Id[++N]=it;
	for(auto it:s[bel[x]])
	{
		if(it==x)val[it]=max(V,fa[x]);
		else val[it]=ds[it];
	}
	run(len,0),run(len,1);// 
	for(auto it:s[bel[x]])
	{
		if(it!=x)fa[it]=v[it];//xv x 
//		cout<<it<<"!@#!#\n";
		ans[it]=max(fa[it],ds[it]);
		fa[it]=max(fa[it],v[it]);//xfa 
		getG(it);
		getfa(it);
	}
	for(auto it:s[bel[x]])
	{
		for(int i=h[it];i;i=e[i].next)
		{
			if(e[i].to==f[it]||bel[e[i].to]==bel[it])continue;
			dp(e[i].to,it);
		}
	}
//	cout<<x<<" qweqwe "<<fa[x]<<"\n";
}
int main(){
	n=read(),m=read();
	vector<pair<int,int> >v;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
		v.push_back(make_pair(a,b));
	}
	tj(1,0);
	for(int i=1;i<=scc;i++)
	{
		for(auto it:s[i])vis[it]=1;
		int st=s[i][0];
//		cerr<<st<<"qweqe \n";
		s[i].clear();
		id=i;dfS(st);
	}
	dfs(1,0);
	dp(1,0);
//	for(int i=1;i<=n;i++)cout<<i<<" "<<ds[i]<<"\n";
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	pc('1',1);
	return 0;
}
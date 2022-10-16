#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=100005;
struct node{int next,to;}e[xx<<1];
int h[xx],cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int vis[xx];
map<pair<int,int> ,vector<int> >mp;
vector<pair<int,int> >ans;
int wr,op,size[xx],U,V;// 
int f[xx],dep[xx],rt[xx];
vector<int>v;
void dfs(int x,int y)
{
	v.push_back(x);
	f[x]=y;dep[x]=dep[y]+1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to]!=-1)
		{
			if(e[i].to==y)continue;
			if(dep[e[i].to]>dep[x])continue;
			if(vis[e[i].to]==(vis[x]^1))rt[x]++,rt[e[i].to]--;
			else 
			{
				U=x,V=e[i].to;
				wr++;size[x]++;size[e[i].to]--;
			}
		}
		else 
		{
			vis[e[i].to]=vis[x]^1;
			dfs(e[i].to,x);
			size[x]+=size[e[i].to];
			rt[x]+=rt[e[i].to];
		}
	}
}
signed main(){
	memset(vis,-1,sizeof(vis));
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if(a>b)swap(a,b);
		mp[make_pair(a,b)].push_back(i);
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==-1)
		{
			vis[i]=0;
			v.clear();
			dfs(i,0);
			op+=wr!=0;
			if(wr)
			{
//				cout<<wr<<'\n';
				if(wr==1)ans.push_back(make_pair(U,V));
				for(auto it:v)
					if(size[it]==wr&&!rt[it])ans.push_back(make_pair(it,f[it]));
			}
			wr=0;
		}
	}
	if(op==0)
	{
		cout<<m<<"\n";
		for(int i=1;i<=m;i++)cout<<i<<" ";exit(0);
	}
	if(op>=2)puts("0"),exit(0);
	vector<int>res;
	for(auto it:ans)
	{
		if(it.first>it.second)swap(it.first,it.second);
		for(auto p:mp[it])res.push_back(p);
	}
	cout<<res.size()<<"\n";
	sort(res.begin(),res.end());
	for(auto it:res)cout<<it<<" ";
	return 0;
}
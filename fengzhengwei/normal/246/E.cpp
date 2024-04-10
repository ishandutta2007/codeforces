#include<bits/stdc++.h>
using namespace std;
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
const int xx=5e5+5;
struct node
{
	int next,to;
}e[xx];
int cnt;
int h[xx];
void add(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
char s[xx];
int dep[xx];
int size[xx];
int son[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;
	size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxx)maxx=size[e[i].to],son[x]=e[i].to;
	}
}
string a[xx];
vector<int>id[xx];
vector<int>v[xx];
int ans[xx];
int res[xx];
map<string,int>mp[xx];
void adds(int x,int op)
{
	mp[dep[x]][a[x]]+=op;
	if(mp[dep[x]][a[x]]==1&&op==1)res[dep[x]]++;
	if(mp[dep[x]][a[x]]==0&&op==-1)res[dep[x]]--;
//	cout<<a[x]<<" "<<op<<" "<<res[dep[x]]<<" "<<mp[dep[x]][a[x]]<<"\n";
	for(int i=h[x];i;i=e[i].next)adds(e[i].to,op);
}
void dfss(int x)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==son[x])continue;
		dfss(e[i].to);
		adds(e[i].to,-1);
	}
//	for(int i=1;i<=n;i++)cout<<res[i]<<"\n";
//	cout<<x<<" "<<dep[x]<<endl;
	if(son[x])dfss(son[x]);
	if(x)
	{
		mp[dep[x]][a[x]]+=1;
		if(mp[dep[x]][a[x]]==1)res[dep[x]]++;
//	cout<<a[x]<<" "<<1<<" "<<res[dep[x]]<<" "<<mp[dep[x]][a[x]]<<"\n";
	}
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=son[x])adds(e[i].to,1);
	for(int i=0;i<id[x].size();i++)ans[id[x][i]]=res[v[x][i]];
	
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=s;
		add(read(),i);
	}
	dfs(0,0);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=read();
		b=read();
		id[a].push_back(i);
		v[a].push_back(dep[a]+b);
//		cout<<dep[a]+b<<endl;
	}
	dfss(0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}
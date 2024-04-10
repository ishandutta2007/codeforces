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
bitset<27>bit[xx];
vector<int>id[xx];
vector<int>v[xx];
int ans[xx];
void add(int x)
{
	bit[dep[x]][s[x]-'a']=bit[dep[x]][s[x]-'a']^1;
	for(int i=h[x];i;i=e[i].next)add(e[i].to);
}
bool check(int s)
{
	return bit[s].count()<=1;
}
void dfss(int x)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==son[x])continue;
		dfss(e[i].to);
		add(e[i].to);
	}
	if(son[x])dfss(son[x]);
	bit[dep[x]][s[x]-'a']=bit[dep[x]][s[x]-'a']^1;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=son[x])add(e[i].to);
	for(int i=0;i<id[x].size();i++)ans[id[x][i]]=check(v[x][i]);
//	cout<<x<<"\n";
//	for(int i=1;i<=3;i++)cout<<bit[i]<<"\n";
//	puts("");
}
int main(){
	n=read();
	m=read();
	for(int i=2;i<=n;i++)add(read(),i);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=read();
		b=read();
		id[a].push_back(i);
		v[a].push_back(b);
	}
	dfs(1,0);
	dfss(1);
	for(int i=1;i<=m;i++)if(ans[i])puts("Yes");else puts("No");
	return 0;
}
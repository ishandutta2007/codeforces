#include<bits/stdc++.h>
#define ll long long
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
int n,m,mod;
const int xx=1e5+5;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int vis[xx],res;
void dfs(int x,int y)
{
	vis[x]=1;res++;
	for(int i=h[x];i;i=e[i].next)if(!vis[e[i].to])dfs(e[i].to,x);
}
int main(){
	n=read();
	m=read();
	mod=read();
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	vector<int>v;
	for(int i=1;i<=n;i++)if(!vis[i])res=0,dfs(i,0),v.push_back(res);
	ll ans=1;
	if(v.size()==1)return cout<<ans%mod<<"\n",0;
	for(int i=0;i<v.size();i++)ans*=v[i],ans%=mod;
	for(int i=1;i<=v.size()-2;i++)ans*=n,ans%=mod;
	cout<<ans%mod<<"\n";
	return 0;
}
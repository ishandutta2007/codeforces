#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx],ds[xx],D[xx];
void add(int x,int y)
{
	ds[y]++;D[y]++;
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int n,m;
int dep[xx],vis[xx<<1];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	set<pair<int,int> >s;
	for(int i=1;i<=n;i++)s.insert(make_pair(D[i],i));
	int o=n;
	while(o--)
	{
		int x=s.begin()->second;
		s.erase(s.begin());
		vector<pair<int,pair<int,int> > >re;
		for(int i=h[x];i;i=e[i].next)
			re.push_back(make_pair(-D[e[i].to],make_pair(e[i].to,i)));
		sort(re.begin(),re.end());
		for(auto it:re)
		{
			int to=it.second.first;
			if(D[x]>(ds[x]+1)/2)
			if(D[to]>(ds[to]+1)/2)
			{
				if(s.find(make_pair(D[to],to))!=s.end())
				{
					vis[it.second.second]=1;
					vis[it.second.second^1]=1;
					s.erase(s.find(make_pair(D[to],to)));
					D[to]--;
					s.insert(make_pair(D[to],to));
					D[x]--;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)if(!dep[i])dfs(i,0);
	vector<pair<int,int> >v;
	for(int i=2;i<=cnt;i+=2)
	{
		if(vis[i])continue;
		v.push_back(make_pair(e[i].to,e[i^1].to));
	}
	cout<<v.size()<<"\n";
	for(auto it:v)
	{
		cout<<it.first<<" "<<it.second<<"\n";
	}
	return 0;
}
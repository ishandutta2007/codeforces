#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
//10n^2ibitset10000
bitset<10005>bit[100005];
map<pair<int,int>,int>mp;//n^2 
const int xx=1e5+5;
int n,m,fa[xx],vis[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct node{int a,b,c;bool operator<(const node&w)const{return c<w.c;};}e[xx];
vector<int>v[xx];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)e[i].a=read(),e[i].b=read(),e[i].c=read();
	sort(e+1,e+m+1);
	int tt=0;
	for(int i=1;i<=m;i++)
	{
		int l=i,r=i;
		while(r<m&&e[r+1].c==e[r].c)r++;
		vector<int>use;
		for(int j=l;j<=r;j++)
		{
			if(!vis[e[j].a])use.push_back(e[j].a),vis[e[j].a]=1;
			if(!vis[e[j].b])use.push_back(e[j].b),vis[e[j].b]=1;
		}
		for(auto it:use)vis[it]=0,fa[it]=it;
		for(int j=l;j<=r;j++)fa[find(e[j].a)]=find(e[j].b);
		for(auto it:use)v[find(it)].push_back(it);
		for(auto it:use)
		{
			if(v[it].size())
			{
				if(v[it].size()<=10)
				{
					for(auto a:v[it])
					{
						for(auto b:v[it])
						{
							if(a>=b)continue;
							mp[make_pair(a,b)]++;
						}
					}
				}
				else 
				{
					tt++;
					for(auto a:v[it])bit[a][tt]=1;
				}
				v[it].clear();
			}
		}
		i=r;
	}
	int q=read();
	while(q--)
	{
		int a=read(),b=read();
		if(a>b)swap(a,b);
//		cout<<mp[make_pair(a,b)]<<"\n";
		cout<<mp[make_pair(a,b)]+(bit[a]&bit[b]).count()<<"\n";
	}
	return 0;
}
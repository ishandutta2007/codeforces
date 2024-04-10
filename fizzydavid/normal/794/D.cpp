//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m,tot,id[300111];
vector<int>con[300111];
int bs,mod1=1e9+7,mod2=1e9+9;
map<pair<int,int>,int > mp;
int getid(pair<int,int> hs)
{
	int &v=mp[hs];
	if(v==0)v=++tot;
	return v;
}
vector<int>v;
pair<int,int> geths(int x)
{
	v.clear();
	v.PB(x);
	for(int i=0;i<con[x].size();i++)
	{
		v.PB(con[x][i]);
	}
	sort(v.begin(),v.end());
	int hs1=1,hs2=1;
	for(int i=0;i<v.size();i++)
	{
		hs1=(1ll*hs1*bs+v[i])%mod1;
		hs2=(1ll*hs2*bs+v[i])%mod2;
	}
	return MP(hs1,hs2);
}
vector<int> nc[300111];
int ans[300111];
bool vis[300111];
int cnt;
int go(int x)
{
	vis[x]=1;
	for(int i=0;i<nc[x].size();i++)
	{
		if(!vis[nc[x][i]])return go(nc[x][i]);
	}
	return x;
}
bool dfs(int x,int p=-1,int lv=1)
{
//	cout<<"dfs:"<<x<<endl;
	if(nc[x].size()>2)return false;
	vis[x]=1;cnt++;ans[x]=lv;
	for(int i=0;i<nc[x].size();i++)
	{
		int u=nc[x][i];
		if(u==p)continue;
		if(vis[u])return false;
		return dfs(u,x,lv+1);
	}
	return true;
}
int main()
{
	srand(time(NULL));
	bs=23333333+rand();
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)
	{
		id[i]=getid(geths(i));
//		cout<<id[i]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<con[i].size();j++)
		{
			int u=con[i][j];
			if(id[u]!=id[i])
			{
				nc[id[i]].PB(id[u]);
//				cout<<id[i]<<" "<<id[u]<<endl;
			}
		}
	}
	for(int i=1;i<=tot;i++)
	{
		sort(nc[i].begin(),nc[i].end());
		nc[i].erase(unique(nc[i].begin(),nc[i].end()),nc[i].end());
	}
	int rt=go(1);
	memset(vis,0,sizeof(vis));
	if(dfs(rt))
	{
		if(cnt==tot)
		{
			puts("YES");
			for(int i=1;i<=n;i++)puti(ans[id[i]]);
		}
		else puts("NO");
	}
	else puts("NO");
	return 0;
}
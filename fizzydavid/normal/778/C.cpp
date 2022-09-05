//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
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
int n;
vector<pair<int,char> >con[300111];
vector<int>son[300111][26];
int go[600111][26],tot,sz[300111];
void init(int x,int pre=-1)
{
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int y=con[x][i].FF;
		if(y==pre)continue;
		go[x][con[x][i].SS-'a']=y;
//		cout<<x<<","<<con[x][i].SS<<" "<<y<<endl;
		init(y,x);
		sz[x]+=sz[y];
	}
	for(int i=0;i<con[x].size();i++)
	{
		int y=con[x][i].FF;
		if(y==pre)continue;
		for(int j=0;j<con[y].size();j++)
		{
			int z=con[y][j].FF;
			if(z==x)continue;
			son[x][con[y][j].SS-'a'].PB(z);
		}
	}
}
int tmp[600111],tmpsz;
int add(int x,int y)
{
	int ret=1;
	for(int i=0;i<26;i++)
	{
		if(go[x][i])
		{
			if(go[y][i])ret+=add(go[x][i],go[y][i]);
			else
			{
				go[y][i]=++tot;
				tmp[tmpsz++]=y;
				tmp[tmpsz++]=i;
				add(go[x][i],go[y][i]);
			}
		}
	}
	return ret;
}
void clear()
{
	tot=n;
	for(int i=0;i<tmpsz;i+=2)
	{
		go[tmp[i]][tmp[i+1]]=0;
	}
	tmpsz=0;
}
int ans[300111];
void dfs(int x,int lv,int pre=-1)
{
//	cout<<"dfs:"<<x<<" "<<lv<<endl;
	for(int i=0;i<con[x].size();i++)
	{
		int y=con[x][i].FF;
		if(y==pre)continue;
		ans[lv]++;
		dfs(y,lv+1,x);
	}
	for(int i=0;i<26;i++)
	{
		if(!son[x][i].size())continue;
		clear();
		int mxj=0;
		for(int j=0;j<son[x][i].size();j++)
		{
			if(sz[son[x][i][j]]>sz[son[x][i][mxj]])mxj=j;
		}
		for(int j=0;j<son[x][i].size();j++)
		{
			if(j==mxj)continue;
			ans[lv]+=add(son[x][i][j],son[x][i][mxj]);
		}
	}
}

int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		char c;
		getii(x,y);
		c=mygetchar();
		con[x].PB(MP(y,c));
		con[y].PB(MP(x,c));
	}
	init(1);
	dfs(1,1);
	int mx=1;
	for(int i=1;i<=n;i++)if(ans[i]>ans[mx])mx=i;
	cout<<n-ans[mx]<<endl<<mx<<endl;
	return 0;
}
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
int c[100111],dfn[100111],dfnr[100111],dfntot,tc[100111],par[100111];
int son[100111];
vector<int>con[100111];
void dfs(int x,int pre=-1)
{
	dfn[x]=++dfntot;
	tc[dfntot]=c[x];
	par[x]=pre;
	son[x]=c[x];
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==pre)continue;
		dfs(con[x][i],x);
		if(son[x]!=0&&son[con[x][i]]!=son[x])son[x]=-1;
		else son[x]=son[con[x][i]];
	}
	dfnr[x]=dfntot;
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)geti(c[i]);
	dfs(1);
	int l=1,r=n;
	while(tc[l]==tc[1]&&l<=n)l++;l--;
	while(tc[r]==tc[n]&&r>=1)r--;r++;
	for(int i=1;i<=n;i++)
	{
		bool ok=1;
		for(int j=0;j<con[i].size();j++)
		{
			if(con[i][j]==par[i])continue;
			ok&=(son[con[i][j]]!=-1);
		}
		if(ok)
		{
			if(par[i]==-1||dfn[i]==1&&dfnr[i]+1>=r||dfn[i]-1<=l&&dfnr[i]==n||dfn[i]-1<=l&&dfnr[i]+1>=r&&tc[1]==tc[n])
			{
				puts("YES");
				cout<<i<<endl;
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}
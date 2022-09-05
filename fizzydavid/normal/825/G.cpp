//by yjz
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
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
int n,q;
bool flag[1000111];
int MN,mn[1000111];
vector<int>con[1000111];
void dfs(int x,int pre=-1)
{
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==pre)continue;
		mn[con[x][i]]=min(mn[x],con[x][i]);
		dfs(con[x][i],x);
	}
}
int main()
{
	getii(n,q);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	int last=0,rt=-1;
	while(q--)
	{
		int cmd,x;
		getii(cmd,x);
		x=(x+last)%n+1;
		if(rt==-1)
		{
			rt=x;
			MN=mn[rt]=rt;
			dfs(rt);
		}
		if(cmd==1)
		{
			if(!flag[x])
			{
				flag[x]=1;
				MN=min(MN,mn[x]);
			}
		}
		else
		{
			int ans=min(MN,mn[x]);
			putsi(ans);
			last=ans;
		}
	}
	return 0;
}
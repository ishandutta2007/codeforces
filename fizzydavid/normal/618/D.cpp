//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
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
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
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
int n,x,y,ans;
vector<int> con[200111];
int dfs(int u,int pre)
{
	int sum=0;
	for(int i=0;i<con[u].size();i++)
	{
		if(con[u][i]==pre)continue;
		sum+=dfs(con[u][i],u);
	}
	if(sum<2)return 1;
	else
	{
		ans+=sum-1;
		return 0;
	}
}
int main()
{
	getiii(n,x,y);
	for(int i=1;i<n;i++)
	{
		int u,v;
		getii(u,v);
		con[u].PB(v);
		con[v].PB(u);
	}
	for(int i=1;i<=n;i++)if(con[i].size()==1)
	{
		dfs(i,-1);
		break;
	}
	if(x<=y)
	{
		cout<<1ll*ans*y+1ll*(n-ans-1)*x;
	}
	else
	{
		bool ok=0;
		for(int i=1;i<=n;i++)if(con[i].size()==n-1)ok=1;
		if(ok)cout<<1ll*(n-2)*y+x;
		else cout<<1ll*(n-1)*y;
	}
	return 0;
}
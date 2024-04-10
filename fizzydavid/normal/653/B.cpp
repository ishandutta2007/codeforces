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
ll dp[7][7];
bool vis[7][7][7];
int trans[7][7];
int n,q;
int main()
{
	getii(n,q);
	for(int i=1;i<=q;i++)
	{
		char c1,c2,c3;
		c1=mygetchar();
		c2=mygetchar();
		c3=mygetchar();
		int t1=c1-'a',t2=c2-'a',t3=c3-'a';
		if(!vis[t3][t1][t2])
		{
			vis[t3][t1][t2]=1;
			trans[t3][t1]++;
		}
	}
	dp[0][0]=1;
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<6;j++)
		{
			for(int k=0;k<6;k++)
			{
				dp[i][j]+=dp[i-1][k]*trans[k][j];
			}
			if(i==n-1)ans+=dp[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
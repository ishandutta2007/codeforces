//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int dis[2011][2011];
int n,m,R,C,X,Y;
const int maxq=2011*2011*2;
int q[maxq],qb,qn;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char s[2011][2011];
int main()
{
	getii(n,m);
	getii(R,C);
	getii(X,Y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)s[i][j]=getreal();
	}
	memset(dis,-1,sizeof(dis));
	dis[R][C]=0;
	q[qn++]=R;
	q[qn++]=C;
	while(qb!=qn)
	{
		int x=q[qb],y=q[qb+1];
		qb+=2;
		if(qb>=maxq)qb=0;
		for(int d=0;d<4;d++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='.'&&dis[nx][ny]==-1)
			{
				if(d<2)
				{
					dis[nx][ny]=dis[x][y];
					if(qb==0)qb=maxq-2;else qb-=2;
					q[qb]=nx;q[qb+1]=ny;
				}
				else
				{
					dis[nx][ny]=dis[x][y]+1;
					q[qn++]=nx;q[qn++]=ny;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(dis[i][j]!=-1)
			{
				int diff=j-C;
				int rc=(dis[i][j]+diff)/2;
				int lc=(dis[i][j]-diff)/2;
				if(lc<=X&&rc<=Y)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
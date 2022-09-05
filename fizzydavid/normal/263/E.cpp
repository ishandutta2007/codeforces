//while(true)rp++;
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
ll a[1011][1011];
int n,m,k;
int abs(int x)
{
	return x<0?-x:x;
}
int main()
{
	getiii(n,m,k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			geti(a[i][j]),a[i][j]+=a[i][j-1];
	ll ans=0,ansi=k,ansj=k;
	for(int i=k;i<=n-k+1;i++)
	{
		ll sum=0;
		for(int j=i-k+1;j<=i+k-1;j++)
		{
			for(int l=1;l<=k-abs(i-j);l++)
			{
				sum+=a[j][k+l-1]-a[j][k-l];
			}
		}
		for(int j=k;j<=m-k+1;j++)
		{
			if(sum>ans)ans=sum,ansi=i,ansj=j;
			for(int l=i-k+1;l<=i+k-1;l++)
			{
				sum+=a[l][j+k-abs(l-i)]-a[l][j]+a[l][j-k+abs(l-i)]-a[l][j];
			}
		}
	}
	putsii(ansi,ansj);
	return 0;
}
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
int n,a,b,c,d,k;
int id[1011];
bool vis[1011];
int main()
{
	getii(n,k);
	if(k<n+1)
	{
		puts("-1");
		return 0;
	}
	getii(a,b);
	getii(c,d);
	if(n==4)
	{
		puts("-1");
		return 0;
	}
	id[1]=a;
	id[2]=d;
	id[n]=c;
	id[n-1]=b;
	vis[a]=vis[b]=vis[c]=vis[d]=1;
	int it=1;
	for(int i=3;i<=n-2;i++)
	{
		while(vis[it])it++;
		vis[it]=1;
		id[i]=it;
	}
	for(int i=1;i<=n-2;i++)puti(id[i]);
	putii(id[n],id[n-1]);
	puts("");
	for(int i=n;i>=3;i--)puti(id[i]);
	putii(id[1],id[2]);
	return 0;
}
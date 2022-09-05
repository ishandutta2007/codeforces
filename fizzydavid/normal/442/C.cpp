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
int n,nxt[500111],pre[500111],a[500111];
bool f[500111];
void del(int x)
{
	f[x]=1;
	nxt[pre[x]]=nxt[x];
	pre[nxt[x]]=pre[x];	
}
ll check(int x)
{
	if(!f[x]&&x!=1&&x!=n&&a[pre[x]]>=a[x]&&a[x]<=a[nxt[x]])
	{
		del(x);
		return min(a[nxt[x]],a[pre[x]])+check(pre[x])+check(nxt[x]);
	}
	return 0;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]),nxt[i]=i+1,pre[i]=i-1;
	ll ans=0;
	for(int i=2;i<n;i++)
	{
		if(!f[i])ans+=check(i);
	}
	int p=1;
	while(p>=1&&p<=n)ans+=min(a[pre[p]],a[nxt[p]]),p=nxt[p];
	cout<<ans<<endl;
	return 0;
}
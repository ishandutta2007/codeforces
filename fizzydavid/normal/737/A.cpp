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
int n,m;
ll s,t,pos[200111];
ll tc[200111],tv[200111];
bool check(ll x)
{
	ll ti=0;
	for(int i=0;i<=m;i++)
	{
		ll len=pos[i+1]-pos[i];
		if(len>x)return false;
		if(len<=x/2)
		{
			ti+=len;
		}
		else
		{
			ti+=(x-len)+2*(len-(x-len));
		}
	}
	return ti<=t;
}
int main()
{
	getii(n,m);
	getii(s,t);
	for(int i=1;i<=n;i++)getii(tc[i],tv[i]);
	for(int i=1;i<=m;i++)
	{
		geti(pos[i]);
	}
	sort(pos+1,pos+m+1);
	pos[0]=0;pos[m+1]=s;
	ll l=1,r=1ll<<50;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	ll ans=1ll<<50;
	for(int i=1;i<=n;i++)
	{
		if(tv[i]<l)continue;
		ans=min(ans,tc[i]);
	}
	if(ans==(1ll<<50))puts("-1");else cout<<ans<<endl;
	return 0;
}
//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
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
int n,mxb,K,t;
int a[200111];
int v[100111],vn;
int b[5000];
int maxi(int x,int y)
{
	for(int i=x;i<=4555;i+=i&(-i))b[i]=max(b[i],y);
}
int query(int x)
{
	int ret=0;
	for(int i=x;i>0;i-=i&(-i))ret=max(ret,b[i]);
	return ret;
}
int main()
{
	getii(K,n);
	getii(mxb,t);
	while(K--)
	{
		vn=0;
		for(int i=1;i<=n;i++)
		{
			geti(a[i]);
			v[vn++]=a[i];
		}
		sort(v,v+vn);
		vn=unique(v,v+vn)-v;
		for(int i=1;i<=n;i++)
		{
			a[i]=lower_bound(v,v+vn,a[i])-v+1;
		}
		t=min(t,vn);
		memset(b,0,sizeof(b));
		int ans=0;
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x=query(a[j]-1)+1;
				maxi(a[j],x);
				ans=max(ans,x);
				if(x==vn)break;
			}
		}
		putsi(ans);
	}
	return 0;
}
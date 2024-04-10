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
int n,p[1000111],mx[1000111],mxcnt[1000111],v[1000111];
int main()
{
	geti(n);
	v[1]=1;
	for(int i=2;i<=n+1;i++)
	{
//		cout<<"i="<<i<<endl;
		geti(p[i]);
		int x=i;
		v[x]=1;
		while(x!=1)
		{
			if(v[x]>mx[p[x]])
			{
				mx[p[x]]=v[x],mxcnt[p[x]]=1;
				if(v[p[x]]==mx[p[x]])break;
				v[p[x]]=mx[p[x]];
			}
			else if(v[x]==mx[p[x]])
			{
				if((++mxcnt[p[x]])==2)v[p[x]]++;
				else break;
			}
			else break;
			x=p[x];
		}
//		for(int j=1;j<=n;j++)cout<<v[j]<<" ";cout<<endl;
//		for(int j=1;j<=n;j++)cout<<mx[j]<<" ";cout<<endl;
//		for(int j=1;j<=n;j++)cout<<mxcnt[j]<<" ";cout<<endl;
		
		puti(mx[1]);
	}
	return 0;
}
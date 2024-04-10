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
int n,f[2000111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
char s[2000111],ans[2000111];
int main()
{
	geti(n);
	for(int i=1;i<=2000011;i++)f[i]=i;
	while(n--)
	{
		scanf("%s",s);
		int l=strlen(s);
		int k;
		geti(k);
		while(k--)
		{
			int x;
			geti(x);
			for(int i=x;i<x+l;i=gf(i))
			{
				ans[i]=s[i-x];
				f[gf(i)]=gf(i+1);
			}
		}
	}
	int nn=2000011;
	while(!ans[nn])nn--;
	for(int i=1;i<=nn;i++)
	{
		if(!ans[i])putchar('a');
		else putchar(ans[i]);
	}
	return 0;
}
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
char a[4],b[4];
string sa,sb;
int main()
{
	for(int i=0;i<4;i++)a[i]=mygetchar();swap(a[2],a[3]);
	for(int i=0;i<4;i++)b[i]=mygetchar();swap(b[2],b[3]);
	for(int i=0;i<4;i++)
	{
		if(a[i]=='A')
		{
			for(int j=0;j<4;j++)
			{
				if(a[(i+j)%4]>='A'&&a[(i+j)%4]<='C')
				{
					sa+=a[(i+j)%4];
				}
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		if(b[i]=='A')
		{
			for(int j=0;j<4;j++)
			{
				if(b[(i+j)%4]>='A'&&b[(i+j)%4]<='C')
				{
					sb+=b[(i+j)%4];
				}
			}
		}
	}
	if(sa==sb)puts("YES");else puts("NO");
	return 0;
}
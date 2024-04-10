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
int n,a,b,k;
char s[200111];
int l[200111],ln;
int dis[200111];
int main()
{
	geti(n);
	getiii(a,b,k);
	int tot=0;
	scanf("%s",s);
	int pre=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			l[ln++]=pre;
			pre=0;
		}
		else pre++;
		dis[i]=pre;
	}
	l[ln++]=pre;
	for(int i=0;i<ln;i++)tot+=l[i]/b;
	int ans=tot-a+1;
	printf("%d\n",ans);
	for(int i=0;i<n&&ans>0;i++)
	{
		if(dis[i]!=0&&dis[i]%b==0)printf("%d ",i+1),ans--;
	}
	return 0;
}
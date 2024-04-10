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
char s[30],ans[3][20];
int hs[256];
void nxt(int &x)
{
	x=x%27+1;
}
int main()
{
	scanf("%s",s+1);
	int x,y;
	for(int i=1;i<=27;i++)
	{
		if(hs[s[i]]>0)
		{
			x=hs[s[i]];
			y=i;
		}
		hs[s[i]]=i;
	}
//	cout<<x<<" "<<y<<endl;
	if(abs(x-y)==1)
	{
		puts("Impossible");
		return 0;
	}
	else
	{
		if((y-x)&1)
		{
			int t=(y-x)/2,j=x;
			for(int i=13-t;i<=13;i++,nxt(j))
			{
				ans[2][i]=s[j];
			}
			for(int i=13;i>13-t;i--,nxt(j))
			{
				ans[1][i]=s[j];
			}
			nxt(j);
			for(int i=13-t;i>=1;i--,nxt(j))
			{
				ans[1][i]=s[j];
			}
			for(int i=1;i<13-t;i++,nxt(j))
			{
				ans[2][i]=s[j];
			}
		}
		else
		{
			int t=(y-x)/2-1,j=x;
			for(int i=13-t;i<=13;i++,nxt(j))
			{
				ans[2][i]=s[j];
			}
			for(int i=13;i>=13-t;i--,nxt(j))
			{
				ans[1][i]=s[j];
			}
			nxt(j);
			for(int i=13-t-1;i>=1;i--,nxt(j))
			{
				ans[1][i]=s[j];
			}
			for(int i=1;i<13-t;i++,nxt(j))
			{
				ans[2][i]=s[j];
			}
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=13;j++)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
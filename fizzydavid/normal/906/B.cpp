//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
/*
n<=m
if n=1
	if m<=3 false
	else 3 1 4 2
if n=2
	if m<=3 false
	else 3 1 4 2\n2 4 1 3
if n>=3
	if n==3&&m==3
		5 1 9
		3 7 2
		8 6 4
	else ...
*/
bool F;
int n,m;
vector<int> a[100111];
bool check(int x,int y)
{
	return abs(x-y)!=m&&(abs(x-y)!=1||x%m==0||y%m==0);
}
void check()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j<m&&!check(a[i][j],a[i][j+1])||i<n&&!check(a[i][j],a[i+1][j]))
			{
				cerr<<"WA "<<i<<" "<<j<<endl;
				exit(-1);
			}
		}
	}
}
void outans()
{
	check();
	puts("YES");
	if(!F)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				puti(a[i][j]);
			}
			puts("");
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x=(a[j][i]-1)/m+1,y=a[j][i]-(x-1)*m;
				puti((y-1)*n+x);
			}
			puts("");
		}
	}
}
int b[100111];
int main()
{
	cin>>n>>m;
	if(n>m)
	{
		swap(n,m);
		F=1;
	}
	if(m==1)
	{
		puts("YES");
		puts("1");
		return 0;
	}
	if(m>=4)
	{
		if(m%2==0)
		{
			for(int i=1;i<=n;i++)
			{
				a[i].resize(m+2);
				int bs=(i-1)*m;
				int bn=0;
				for(int j=m-1;j>=1;j-=2)
				{
					b[++bn]=bs+j;
				}
				for(int j=m;j>=1;j-=2)
				{
					b[++bn]=bs+j;
				}
				if(i&1)for(int j=1;j<=m;j++)a[i][j]=b[j];
				else for(int j=1;j<=m;j++)a[i][j]=b[m-j+1];
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				a[i].resize(m+2);
				int bs=(i-1)*m;
				int bn=0;
				for(int j=m;j>=1;j-=2)
				{
					b[++bn]=bs+j;
				}
				for(int j=m-1;j>=1;j-=2)
				{
					b[++bn]=bs+j;
				}
				for(int j=1;j<=m;j++)a[i][j]=b[(j+i)%m+1];
			}
		}
		outans();
	}
	else
	{
		if(n<=2)
		{
			puts("NO");
			return 0;
		}
		else
		{
			assert(n==3&&m==3);
			puts("YES");
			puts("5 1 9");
			puts("3 7 2");
			puts("8 6 4");
			return 0;
		}
	}
	return 0;
}
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
int n;
vector<vector<int> >v;
int main()
{
	cin>>n;
	if(n%2==1)
	{
		v.PB({1,2,3});
		v.PB({1,2,3});
		for(int i=3;i<n;i+=2)
		{
			int p=i+1,q=i+2;
			v.PB({1,p,q});
			for(int x=2;x<=i;x+=2)v.PB({x,p,x+1,q});
			v.PB({1,p,q});
			for(int x=2;x<=i;x+=2)v.PB({x,p,x+1,q});
		}
	}
	else
	{
		v.PB({1,2,3});
		v.PB({2,3,4});
		v.PB({3,4,1});
		v.PB({4,1,2});
		for(int i=4;i<n;i+=2)
		{
			int p=i+1,q=i+2;
			v.PB({1,p,q});
			for(int x=1;x<=i;x+=2)v.PB({x,p,x+1,q});
			v.PB({2,p,q});
			for(int x=3;x<=i;x+=2)v.PB({x,p,x+1,q});
		}
	}
	putsi(v.size());
	for(int i=0;i<v.size();i++)
	{
		puti(v[i].size());
		for(int j=0;j<v[i].size();j++)
		{
			puti(v[i][j]);
		}
		puts("");
	}
	return 0;
}
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
const ll Lbg=2e18;
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
struct matrix
{
	bitset<512> a[512];
	void rotate()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i<j)
				{
					int t=a[i][j];
					a[i][j]=a[j][i];
					a[j][i]=t;
				}
			}
		}
	}
	matrix multi(matrix t)
	{
		matrix ret;
		t.rotate();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)ret.a[i][j]=(a[i]&t.a[j]).any();
		}
		return ret;
	}
	bool check()
	{
		for(int i=0;i<n;i++)
		{
			if(a[i].any())return true;
		}
		return false;
	}
	void out()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	void init()
	{
		for(int i=0;i<n;i++)a[i][i]=1;
	}
}A,a[60],b[60];
int m;
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y,t;
		getiii(x,y,t);
		x--;
		y--;
		if(t==0)a[0].a[x][y]=1;
		else b[0].a[x][y]=1;
	}
	for(int i=1;i<60;i++)
	{
//		cout<<i<<endl;
		a[i]=a[i-1].multi(b[i-1]);
		b[i]=b[i-1].multi(a[i-1]);
/*		if(i<4)
		{
			a[i].out();
			b[i].out();
		}*/
	}
	ll ans=0;
	bool t=0;
	A.init();
	for(int i=59;i>=0;i--)
	{
		if(t==0)
		{
			matrix tmp=A.multi(a[i]);
			if(tmp.check())
			{
				ans|=(1ll<<i);
				t^=1;
				A=tmp;
			}
		}
		else
		{
			matrix tmp=A.multi(b[i]);
			if(tmp.check())
			{
				ans|=(1ll<<i);
				t^=1;
				A=tmp;
			}
		}
	}
	if(ans>1000000000000000000ll)puts("-1");
	else cout<<ans<<endl;
	return 0;
}
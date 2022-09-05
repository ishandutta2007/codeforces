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
struct matrix
{
	int a[31][31];
	void set0(){memset(a,0,sizeof(a));}
	void set1(){set0();for(int i=0;i<=30;i++)a[i][i]=1;}
	matrix(){set0();}
	matrix operator*(const matrix &t)const
	{
		matrix ret;
		for(int i=0;i<=30;i++)
		{
			for(int j=0;j<=30;j++)
			{
				if(!a[i][j])continue;
				for(int k=0;k<=30;k++)
				{
					ret.a[i][k]=(ret.a[i][k]+1ll*a[i][j]*t.a[j][k])%mod;
				}
			}
		}
		return ret;
	}
	matrix shift(int x,int n)
	{
		matrix ret;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				ret.a[i==n?n:(i+x)%n][j==n?n:(j+x)%n]=a[i][j];
			}
		}
		return ret;
	}
	void out(int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
ll n;
int m,k;
matrix kissme(matrix x,int y)
{
	assert(y>0);
	if(y==1)return x;
	if(y&1)return kissme(x,y-1)*x.shift(y-1,k);
	else
	{
		matrix t=kissme(x,y>>1);
		return t*t.shift(y>>1,k);
	}
}
matrix pw[70];
int a[70];
int main()
{
	getii(n,k);
	ll t=n;
	pw[0].set1();
	for(int i=0;i<=k;i++)pw[0].a[i][0]=1;
	while(t)
	{
		a[m]=t%k;
		m++;
		pw[m]=kissme(pw[m-1],k);
		t/=k;
	}
	matrix ans;
	ans.set1();
	int pre=0;
	for(int i=m-1;i>=0;i--)
	{
		if(a[i]==0)continue;
		ans=ans*kissme(pw[i].shift(pre,k),a[i]);
		pre=(pre+a[i])%k;
	}
	ll ret=0;
	for(int i=0;i<=k;i++)ret=(ret+ans.a[k][i])%mod;
	cout<<ret<<endl;
	return 0;
}
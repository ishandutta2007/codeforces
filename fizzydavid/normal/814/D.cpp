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
double r[1011],rx[1011],ry[1011];
vector<int> con[1011];
double ans=0;
void dfs(int x,int l=0)
{
	if(l>0)
	{
		if(l==1||(l%2==0))
		{
			ans+=r[x]*r[x];
		}
		else ans-=r[x]*r[x];
	}
	for(int u:con[x])
	{
		dfs(u,l+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&rx[i],&ry[i],&r[i]);
	}
	for(int i=1;i<=n;i++)
	{
		double mnr=1e100;
		int mnid=0;
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(r[i]+(1e-7)<r[j]&&r[j]*r[j]>(rx[i]-rx[j])*(rx[i]-rx[j])+(ry[i]-ry[j])*(ry[i]-ry[j]))
				{
					if(r[j]<mnr)
					{
						mnid=j;
						mnr=r[j];
					}
				}
			}
		}
		con[mnid].PB(i);
	}
	dfs(0);
	cout<<fixed<<setprecision(10)<<ans*acos(-1)<<endl;
	return 0;
}
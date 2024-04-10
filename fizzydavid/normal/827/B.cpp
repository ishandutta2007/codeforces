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
int n,k;
bool check(int d)
{
	ll mx;
	if(d%2==0)
	{
		mx=1ll*(d/2-1)*k+1;
	}
	else
	{
		mx=1ll*(d/2-1)*(k-1)+d/2+1;
	}
	return n-k<=mx;
}
void build(int d)
{
	int rt=1,sum=1;
	vector<int> v;
	for(int i=0;i<k;i++)
	{
		v.PB(d/2-1);
		sum+=d/2-1;
	}
	if(d&1)v[0]++,sum++;
	sum-=n-k;
	int it=0;
	while(sum--)
	{
		while(v[it]==0)it++;
		v[it]--;
	}
	int tot=1;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<v[i]+1;j++)
		{
			if(j==0)putsii(rt,tot+1);
			else putsii(tot,tot+1);
			tot++;
		}
	}
}
int main()
{
	getii(n,k);
	int l=2,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(check(m))r=m-1;
		else l=m+1;
	}
	putsi(l);
//	return 0
	build(l);
	return 0;
}
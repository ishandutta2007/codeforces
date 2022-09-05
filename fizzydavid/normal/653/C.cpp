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
int n,a[150111];
bool f[150111];
vector<int> id;
bool checkid(int x)
{
	if(x<n&&x>=1)
	{
		if(x&1)return a[x]<a[x+1];
		else return a[x]>a[x+1];
	}
	return 1;
}
bool check(int t)
{
	bool ok=1;
	ok&=checkid(t-1)&checkid(t)&checkid(t+1);
	for(int i=0;i<id.size();i++)
	{
		int x=id[i];
		ok&=checkid(x-1)&checkid(x)&checkid(x+1);
	}
	return ok;
}
set<pair<int,int> >ans;
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(i<n)
		{
			if(i&1)
			{
				if(a[i]>=a[i+1])f[i]=f[i+1]=1;
			}
			else
			{
				if(a[i]<=a[i+1])f[i]=f[i+1]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)if(f[i])id.PB(i);
	if(id.size()>20)puts("0");
	else
	{
		for(int i=0;i<id.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(id[i]==j)continue;
				swap(a[id[i]],a[j]);
				if(check(j))
				{
					ans.insert(MP(min(id[i],j),max(id[i],j)));
				}
				swap(a[id[i]],a[j]);
			}
		}
		cout<<ans.size()<<endl;
	}
	return 0;
}
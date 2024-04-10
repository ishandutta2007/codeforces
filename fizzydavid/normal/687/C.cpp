//while(true)rp++;
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
int n,k;
int a[511];
bool dp[511][511];
vector<int>v;
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int t1=500;t1>=0;t1--)
		{
			for(int t2=500;t2>=0;t2--)
			{
				if(t1+a[i]<=500)dp[t1+a[i]][t2]|=dp[t1][t2];
				if(t2+a[i]<=500)dp[t1][t2+a[i]]|=dp[t1][t2];
			}
		}
	}
	for(int i=0;i<=k;i++)
		if(dp[i][k-i])
			v.PB(i);
	putsi(v.size());
	for(int i=0;i<v.size();i++)puti(v[i]);
	return 0;
}
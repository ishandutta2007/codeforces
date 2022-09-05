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
char p[200111];
char t[200111];
int n,m,w[200111];
bool check(int x)
{
	int it=1;
	for(int i=1;i<=n;i++)
	{
		if(w[i]<=x)continue;
		if(p[i]==t[it])
		{
			it++;
		}
		if(it>m)return true;
	}
	return false;
}
int main()
{
	scanf("%s",p+1);
	scanf("%s",t+1);
	n=strlen(p+1);
	m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		w[x]=i;
	}
	int l=0,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(check(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<endl;
	return 0;
}
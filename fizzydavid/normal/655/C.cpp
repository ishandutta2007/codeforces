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
int n,k;
char s[100111];
int pre[100111];
int getpre(int x)
{
	if(x<0)return 0;
	else if(x>=n)return pre[n-1];
	else return pre[x];
}
bool check(int x)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'&&getpre(i+x)-getpre(i-x-1)>=k)return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);k++;
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')pre[i]++;
		if(i>0)pre[i]+=pre[i-1];
	}
	int l=0,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(check(m))r=m-1;else l=m+1;
	}
	cout<<l<<endl;
	return 0;
}
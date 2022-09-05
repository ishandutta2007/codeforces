//while(true)rp++;
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
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
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
int n,k,c1,c2,x;
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(x),c1+=x&1;
	c2=n-c1;
	if(n==k)
	{
		if(c1&1)puts("Stannis");else puts("Daenerys");
		return 0;
	}
	if((n-k)&1)//S is the last
	{
		int pos=c1-(n-k-1)/2;
		if(pos<1)puts("Daenerys");
		else if(pos>=k+1)
		{
			if(k&1)puts("Stannis");else puts("Daenerys");
		}
		else
		{
			puts("Stannis");
		}
		
	}
	else//D is the last
	{
		int pos=c1-(n-k-1)/2;
		if(pos>=k+1)
		{
			if(k&1)puts("Stannis");else puts("Daenerys");
		}
		else
		{
			puts("Daenerys");
		}
	}
	return 0;
}
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
int n,A,B,an,bn;
pair<int,int> a[100111];
int mxa[100111];
pair<int,int> b[100111];
int mxb[100111];
int main()
{
	getiii(n,A,B);
	for(int i=1;i<=n;i++)
	{
		char t;
		int x,y;
		getii(x,y);
		t=mygetchar();
		if(t=='C')
		{
			a[++an]=MP(y,x);
		}
		else
		{
			b[++bn]=MP(y,x);
		}
	}
	sort(a+1,a+an+1);
	sort(b+1,b+bn+1);
	int ma=0,mb=0,cnt=0;
	for(int i=1;i<=an;i++)
	{
		mxa[i]=max(mxa[i-1],a[i].SS);
		if(a[i].FF<=A)ma=max(ma,a[i].SS),cnt++;
	}
	for(int i=1;i<=bn;i++)
	{
		mxb[i]=max(mxb[i-1],b[i].SS);
		if(b[i].FF<=B)mb=max(mb,b[i].SS),cnt++;
	}
	if(cnt<2)
	{
		puts("0");
		return 0;
	}
	int ans=ma+mb;
	if(ma==0||mb==0)ans=0;
	int it=1;
	for(int i=an;i>=2;i--)
	{
		while(it<i&&a[it+1].FF+a[i].FF<=A)it++;
		it=min(it,i-1);
		if(a[it].FF+a[i].FF<=A)ans=max(ans,a[i].SS+mxa[it]);
	}
	it=1;
	for(int i=bn;i>=2;i--)
	{
		while(it<i&&b[it+1].FF+b[i].FF<=B)it++;
		it=min(it,i-1);
		if(b[it].FF+b[i].FF<=B)ans=max(ans,b[i].SS+mxb[it]);
	}
	cout<<ans<<endl;
	return 0;
}
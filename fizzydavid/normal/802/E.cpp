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
int Tn;
double a[255],ia[255];
int cnt[1011];
void solve()
{
	memset(cnt,0,sizeof(cnt));
	double mn=0,mx=0;
	for(int i=1;i<=250;i++)
	{
		geti(a[i]);
//		a[i]=rand()%1235;
		ia[i]=a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=250;i++)a[i]=1.0*a[i]/mx;
	double av=0,sum=0;
	for(int i=1;i<=250;i++)av+=a[i];
	av/=250;
	for(int i=1;i<=250;i++)sum+=(a[i]-av)*(a[i]-av)*(a[i]-av)*(a[i]-av);
//	cerr<<sum<<endl;
	if(sum<1.8)
	{
//		puts("poisson");
/*		av=0;
		for(int i=1;i<=250;i++)av+=ia[i];
		av/=250;
		sum=0;
		for(int i=1;i<=250;i++)sum+=1.0*(ia[i]-av)*(ia[i]-av);
		cout<<int(sum/250)<<endl;*/
		sort(ia+1,ia+251);
		cout<<int((ia[125]+ia[126])/2)<<endl;
	}
	else
	{
//		puts("uniform");
/*		double s=0;
		for(int i=1;i<=250;i++)s+=ia[i];
		cout<<int(s/250)<<endl ;*/
		cout<<int(mx/2.0)<<endl;
	}
}
int main()
{
	geti(Tn);
	while(Tn--)
	{
		solve();
	}
	return 0;
}
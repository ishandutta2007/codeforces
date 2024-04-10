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
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t){return point(x+t.x,y+t.y);}
	point operator-(const point &t){return point(x-t.x,y-t.y);}
	point operator*(const point &t){return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point operator*(const double &t){return point(x*t,y*t);}
	point conj(){return point(x,-y);}
};
const int FFTmx=1100000;
int FFTsz;
point _w[FFTmx];
void init(int n)
{
	FFTsz=1;
	while(FFTsz<n)FFTsz<<=1;
	double pi=acos(-1);
	for(int i=0;i<=FFTsz;i++)_w[i]=point(cos(2.0/FFTsz*i*pi),sin(2.0/FFTsz*i*pi));
}
void FFT(point a[],int coef)
{
	for(int i=0,j=0;i<FFTsz;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=FFTsz>>1;(j^=t)<t;t>>=1);
	}
	for(int l=1;l<FFTsz;l<<=1)
	{
		int l2=l<<1;
		for(int i=0;i<FFTsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+l+j]*(coef==1?_w[FFTsz/l2*j]:_w[FFTsz-FFTsz/l2*j]);
				a[i+l+j]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*(1.0/FFTsz);
	}
}
point _al[FFTmx],_ar[FFTmx],_bl[FFTmx],_br[FFTmx],_ta[FFTmx],_tb[FFTmx];
void FFTfor2(point a[],point b[],int coef)
{
	for(int i=0;i<FFTsz;i++)a[i]=a[i]+b[i]*point(0,1);
	if(coef==1)
	{
		FFT(a,1);
		for(int i=0;i<FFTsz;i++)_ta[i]=a[i];
		_ta[FFTsz]=a[0];
		for(int i=0;i<FFTsz;i++)a[i]=(_ta[i]+_ta[FFTsz-i].conj())*0.5;
		for(int i=0;i<FFTsz;i++)b[i]=(_ta[i]-_ta[FFTsz-i].conj())*point(0,-0.5);
	}
	else 
	{
		FFT(a,-1);
		for(int i=0;i<FFTsz;i++)b[i]=a[i].y;
		for(int i=0;i<FFTsz;i++)a[i]=a[i].x;
	}
}
ll ceill(double x){return x>0?ll(x+0.5):-ll(-x+0.5);}
int n;
point a[FFTmx],b[FFTmx];
int A[FFTmx];
char s[FFTmx];
bool f[FFTmx];
int main()
{
	int Tn;
	geti(Tn);
	while(Tn--)
	{
		geti(n);
		scanf("%s",s);
		init(2*n);
		for(int i=1;i<=n;i++)f[i]=1;
		
		for(int i=0;i<FFTsz;i++)a[i]=point(0,0),b[i]=point(0,0);
		for(int i=0;i<n;i++)
		{
			if(s[i]=='K')a[i]=1;
			else if(s[i]=='V')b[n-i-1]=1;
		}
		FFTfor2(a,b,1);
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*b[i];
		FFTfor2(a,b,-1);
		for(int i=0;i<FFTsz;i++)A[i]=ceill(a[i].x);
		for(int i=0;i<n;i++)
		{
			int x=A[n+i];
			f[i+1]&=(x==0);
		}
		
		for(int i=0;i<FFTsz;i++)a[i]=point(0,0),b[i]=point(0,0);
		for(int i=0;i<n;i++)
		{
			if(s[i]=='V')a[i]=1;
			else if(s[i]=='K')b[n-i-1]=1;
		}
		FFTfor2(a,b,1);
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*b[i];
		FFTfor2(a,b,-1);
		for(int i=0;i<FFTsz;i++)A[i]=ceill(a[i].x);
		
		for(int i=0;i<n;i++)
		{
			int x=A[n+i];
			f[i+1]&=(x==0);
		}
		
		
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+i;j<=n;j+=i)
			{
				f[i]&=f[j];
			}
			cnt+=f[i];
		}
		putsi(cnt);
		for(int i=1;i<=n;i++)if(f[i])puti(i);puts("");
	}
	return 0;
}
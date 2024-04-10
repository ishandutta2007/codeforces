//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
const double pi=acos(-1);
const int mxn=1024;
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point operator*(const double &t)const{return point(x*t,y*t);}
};
point makeunit(double x){return point(cos(x),sin(x));}
int sz;
point w[400111];
void init(int n)
{
	if(sz==n)return;
	sz=1;
	while(sz<n)sz<<=1;
	w[0]=point(1,0);
	point tw=makeunit(2*pi/sz);
	for(int i=1;i<=sz;i++)w[i]=w[i-1]*tw;
}
void FFT(point a[],bool rev)
{
	for(int i=0,j=0;i<sz;i++)
	{
		if(i>j)swap(a[i],a[j]);
		for(int l=sz>>1;(j^=l)<l;l>>=1);
	}
	for(int l=1;l<sz;l<<=1)
	{
		int l2=l<<1;
		for(int i=0;i<sz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				point t=a[i+j+l]*w[rev?sz-sz/l2*j:sz/l2*j];
				a[i+j+l]=a[i+j]-t;
				a[i+j]=a[i+j]+t;
			}
		}
	}
	if(rev)for(int i=0;i<sz;i++)a[i]=a[i]*(1.0/sz);
}
void FFT2(point (&a)[mxn][mxn],bool rev)
{
	for(int i=0;i<sz;i++)FFT(a[i],rev);
	for(int i=0;i<sz;i++)for(int j=i;j<sz;j++)swap(a[i][j],a[j][i]);
	for(int i=0;i<sz;i++)FFT(a[i],rev);
};
void make(char (&s)[mxn][mxn],point (&a)[mxn][mxn],int r,int c,int coef)
{
	for(int i=0;i<r;i++)for(int j=0;j<c;j++)
	{
		if(s[i][j]>='a'&&s[i][j]<='z')
		{
			a[i][j]=makeunit(coef*2*pi/26*(s[i][j]-'a'));
		}
	}
}
char s[mxn][mxn],t[mxn][mxn];
int n,m,r,c;
point A[mxn][mxn],B[mxn][mxn];
int main()
{
	init(mxn);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	scanf("%d%d",&r,&c);
	for(int i=0;i<n+r;i++)for(int j=0;j<m+c;j++)s[i][j]=s[i%n][j%m];
	for(int i=0;i<r;i++)scanf("%s",t[i]),reverse(t[i],t[i]+c);
	for(int j=0;j<c;j++)for(int i=0;i<r-i-1;i++)swap(t[i][j],t[r-i-1][j]);
	int cnt=0;
	for(int i=0;i<r;i++)for(int j=0;j<c;j++)cnt+=(t[i][j]!='?');
	make(s,A,n+r,m+c,1);
	make(t,B,r,c,-1);
	FFT2(A,0);FFT2(B,0);
	for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)A[i][j]=A[i][j]*B[i][j];
	FFT2(A,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			putchar('0'+((A[i+r-1][j+c-1].x+(1e-4))>cnt));
		}
		puts("");
	}
	return 0;
}
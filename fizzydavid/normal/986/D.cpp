//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;

const int FFTbitn=20;
const int FFTpmx=1<<FFTbitn;
const int FFTmx=FFTpmx+233;
const int FFTbit=15;//for FFT only  max_value=2^(2*FFTbit)
const double pi=acos(-1);
const int base=10000;
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point conj()const{return point(x,-y);}
};
int fsz;
void FFTinit(int n)
{
	fsz=1;
	while(fsz<n)fsz<<=1;
}
point w_pre[FFTmx];
void FFTprecalc()
{
	for(int i=0;i<=FFTpmx;i++)w_pre[i]=point(cos(2.0/FFTpmx*i*pi),sin(2.0/FFTpmx*i*pi));
}
void FFT(point a[],int coef)
{
	static point w[FFTmx];
	for(int i=0,j=0;i<fsz;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int l=fsz>>1;(j^=l)<l;l>>=1);
	}
	for(int l=1;l<fsz;l<<=1)
	{
		int l2=l<<1,u=FFTpmx/l2;
		if(coef==1)for(int j=0,j2=0;j<l;j++,j2+=u)w[j]=w_pre[j2];
		else for(int j=0,j2=FFTpmx;j<l;j++,j2-=u)w[j]=w_pre[j2];
		for(int i=0;i<fsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+l+j]*w[j];
				a[i+l+j]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<fsz;i++)a[i]=a[i]*(1.0/fsz);
	}
}
int multi(int a[],int an,int b[],int bn,int c[])
{
	static point mul_a[FFTmx],mul_b[FFTmx];
	FFTinit(an+bn);
	for(int i=0;i<fsz;i++)mul_a[i]=point(i<an?a[i]:0,0);
	for(int i=0;i<fsz;i++)mul_b[i]=point(i<bn?b[i]:0,0);
	FFT(mul_a,1);
	FFT(mul_b,1);
	for(int i=0;i<fsz;i++)mul_a[i]=mul_a[i]*mul_b[i];
	FFT(mul_a,-1);
	ll r=0;
	int ret=0;
	for(int i=0;i<fsz;i++)
	{
		ll cur=ll(mul_a[i].x+0.5)+r;
		if(cur>0)ret=max(ret,i+1);
		c[i]=cur%base;
		r=cur/base;
	}
	return ret;
}
int multinum(int a[],int an,int x,int b[])
{
	ll r=0;
	for(int i=0;i<=an;i++)
	{
		ll cur=(i<an?a[i]:0)*x+r;
		b[i]=cur%base;
		r=cur/base;
	}
	return an+(b[an]!=0);
}
char s[1500111];
int n;
int A[FFTmx];
int a[FFTmx],a2[FFTmx],a4[FFTmx],pw[FFTmx];
bool smaller(int a[],int an,int b[],int bn)
{
	for(int i=max(an,bn);i>=0;i--)
	{
		int x=i<an?a[i]:0,y=i<bn?b[i]:0;
		if(x!=y)return x<y;
	}
	return false;
}
void solve(int bs,int T)
{
	memset(a,0,sizeof(a));
	memset(pw,0,sizeof(pw));
	a[0]=1;pw[0]=3;
	int pwn=1,an=1,tmp=bs;
	while(tmp)
	{
		if(tmp&1)an=multi(a,an,pw,pwn,a);
		tmp>>=1;
		pwn=multi(pw,pwn,pw,pwn,pw);
	}
	int a2n=multinum(a,an,2,a2),a4n=multinum(a,an,4,a4);
	int ret=1e9;
	for(int i=0;i<T;i++)
	{
		/*
		cerr<<"i="<<bs+i<<endl;
		for(int j=0;j<an;j++)cerr<<a[j]<<" ";cerr<<endl;
		for(int j=0;j<a2n;j++)cerr<<a2[j]<<" ";cerr<<endl;
		for(int j=0;j<a4n;j++)cerr<<a4[j]<<" ";cerr<<endl;
		*/
		if(!smaller(a,an,A,n))ret=min(ret,(bs+i)*3);
		if(!smaller(a2,a2n,A,n))ret=min(ret,(bs+i)*3+2);
		if(!smaller(a4,a4n,A,n))ret=min(ret,(bs+i)*3+4);
		an=multinum(a,an,3,a);
		a2n=multinum(a2,a2n,3,a2);
		a4n=multinum(a4,a4n,3,a4);
	}
	cout<<ret<<endl;
}
int main()
{
	FFTprecalc();
	scanf("%s",s);
	n=strlen(s);
	if(n==1&&s[0]=='1')
	{
		cout<<1<<endl;
		return 0;
	}
	reverse(s,s+n);
	double t=0;
	for(int i=0;i<n;i++)t=t/10+s[i]-'0';
	t/=4;
	double L=log(t)/log(3)+(n-1)/(log(3)/log(10));
	for(int i=0;i<n;i+=4)
	{
		for(int j=3;j>=0;j--)
		{
			if(i+j<n)A[i/4]=A[i/4]*10+s[i+j]-'0';
		}
	}
	n=n/4+1;
	solve(max(0,int(L-1)),5);
	return 0;
}
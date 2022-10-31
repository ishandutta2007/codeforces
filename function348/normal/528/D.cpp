#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
struct complex
{
	double r,i;
	complex(double R=0.0,double I=0.0) { r=R,i=I;}
};
complex operator +(complex a,complex b) { return complex(a.r+b.r,a.i+b.i);}
complex operator -(complex a,complex b) { return complex(a.r-b.r,a.i-b.i);}
complex operator *(complex a,complex b) { return complex(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
const int N=600000;
const double pi=acos(-1);
complex a[N],b[N];
char s[N],t[N];
int p[N];
int n,m,k;
void fft(complex *a,int n,int x)
{
	for (int i=1,j=n/2;i<n-1;i++)
	{
		if (i<j) swap(a[i],a[j]);
		int p=n/2;
		while (j>=p) j-=p,p/=2;
		j+=p;
	}
	for (int j=2;j<=n;j*=2)
	{
		complex wn(cos(2*pi/j*x),sin(2*pi/j*x));
		for (int i=0;i<n;i+=j)
		{
			complex w(1,0);
			for (int k=i;k<i+j/2;k++)
			{
				complex u=a[k],t=a[k+j/2]*w;
				a[k]=u+t;a[k+j/2]=u-t;
				w=w*wn;
			}
		}
	}
	if (x==-1)
	for (int i=0;i<n;i++) a[i].r/=n;
}
void work(char ch)
{
	int cnt=0;
	int nn=1;
	while (nn<=n+m) nn*=2;
	for (int i=0;i<nn;i++) a[i].r=a[i].i=b[i].r=b[i].i=0;
	for (int i=1;i<=k&&i<=n;i++) cnt+=s[i]==ch;
	for (int i=1;i<=n;i++)
	{
		if (i+k<=n) cnt+=s[i+k]==ch;
		if (cnt) a[i].r=1;
		if (i>k) cnt-=s[i-k]==ch;
	}
	for (int i=1;i<=m;i++) b[i].r=t[m+1-i]==ch;
	fft(a,nn,1);fft(b,nn,1);
	for (int i=0;i<nn;i++) a[i]=a[i]*b[i];
	fft(a,nn,-1);
	for (int i=0;i<nn;i++) p[i]+=(int)(a[i].r+0.5);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);scanf("%s",t+1);
	work('A');work('C');
	work('G');work('T');
	int ans=0;
	for (int i=m+1;i<=n+1;i++)
	if (p[i]==m) ans++;
	cout<<ans<<endl;
	return 0;
}
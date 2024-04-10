#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define pi 3.141592653589793238462643383
using namespace std;
int i,j,m,n,p,k,N,rev[2500005],a[1000005],Ans[1000005];
map<int,int>mp;
struct complex
{
    double re,im;
    complex(double r=0.0,double i=0.0) {re=r,im=i;}
    void print() {printf("%lf %lf\n",re,im);}
}A[2500005],B[2500005],AX[2500005],W[2][2500005];
complex operator +(const complex&A,const complex&B) {return complex(A.re+B.re,A.im+B.im);}
complex operator -(const complex&A,const complex&B) {return complex(A.re-B.re,A.im-B.im);}
complex operator *(const complex&A,const complex&B) {return complex(A.re*B.re-A.im*B.im,A.re*B.im+A.im*B.re);}
void FFT(complex*a,int f)
{  int t,l,i,j,k;
	complex x,y;
	for (i=0; i<N; i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (i=1; i<N; i<<=1)
		for (j=0,t=N/(i<<1); j<N; j+=i<<1)
			for (k=0,l=0; k<i; k++,l+=t) x=W[f][l]*a[j+k+i],y=a[j+k],a[j+k]=y+x,a[j+k+i]=y-x;
	if (f) for (i=0; i<N; i++) a[i].re/=N;
}
int main()
{   
    scanf("%d%d",&a[0],&m);
    for (i=1;i<=a[0];i++) scanf("%d",&a[i]),n=max(n,a[i]),A[a[i]].re++,B[a[i]].re++,mp[a[i]]=1;
    n++;
    for (N=1;N<n;N*=2); N*=2; 
    for (i=0; i<N; i++)
	{
		int x=i,y=0;
		for (k=1; k<N; x>>=1,k<<=1) (y<<=1)|=x&1;
		rev[i]=y;
	}
	for (i=0; i<N; i++) W[0][i]=W[1][i]=complex(cos(2*pi*i/N),sin(2*pi*i/N)),W[1][i].im=-W[0][i].im;
    FFT(A,0); FFT(B,0); 
    for (i=0;i<N;i++) A[i]=A[i]*B[i];
    FFT(A,1);
    for (i=1;i<=m;i++)
     if (A[i].re-(1e-9)>0&&!mp[i]) { printf("NO\n"); return 0; }
    printf("YES\n");
    for (i=1;i<=a[0];i++)
     if (A[a[i]].re-(1e-9)<0) Ans[++Ans[0]]=a[i];
     printf("%d\n",Ans[0]);
     for (i=1;i<=Ans[0];i++) printf("%d ",Ans[i]);
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,N,len,Len,rev[1000005],ans,RR;
int sum[500001][26],vis[1000005];
char c[1000001],s[1000001];
#define pi 3.141592653589793238462643383
struct complex{
           double re,im;
           complex(double i=0.0,double r=0.0) 
           {  
                 re=i; im=r;
           }
}W[2][1000001],A[1000001],B[1000001];    
complex operator +(const complex&A,const complex&B) {return complex(A.re+B.re,A.im+B.im);}
complex operator -(const complex&A,const complex&B) {return complex(A.re-B.re,A.im-B.im);}
complex operator *(const complex&A,const complex&B) {return complex(A.re*B.re-A.im*B.im,A.re*B.im+A.im*B.re);}            
void FFT(complex*a,int f)
{   int i,j,k,l,t;
    complex x,y;
   for (i=0;i<N;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
   for (i=1;i<N;i<<=1)
     for (j=0,t=N/(i<<1);j<N;j+=i<<1)
       for (k=0,l=0;k<i;k++,l+=t)
        x=W[f][l]*a[j+k+i],y=a[j+k],a[j+k]=x+y,a[j+k+i]=y-x;
   if (f)
   for (i=0;i<N;i++) a[i].re/=N;
}
void Go(int x)
{     int rp=0;
      for (i=0;i<N;i++) A[i].im=A[i].re=0;
      for (i=0;i<N;i++) B[i].im=B[i].re=0;
      for (i=0;i<Len;i++)
        if (s[i]-'A'==x) B[i].re=1.0,rp++;
      for (i=0;i<len;i++)
      {   
            int Hou=sum[min(len-1,i+RR)][x];
            int Qian=max(0,i-RR);
            if (Qian==0) Qian=0; else Qian=sum[Qian-1][x];
            if (Hou-Qian>0) A[len-1-i].re=1;
      }
      FFT(A,0); FFT(B,0);
      for (i=0;i<N;i++) A[i]=A[i]*B[i];
      FFT(A,1);
      for (i=0;i<len;i++)
        if ((int)(A[i].re+0.5)==rp) vis[len-i-1]++;
}     
int main()
{ 
     scanf("%d%d%d",&len,&Len,&RR);
     scanf("%s",&c); scanf("%s",&s);
     for (N=1;N<len|N<Len;N<<=1); N<<=1;
      for (i=0;i<N;i++)
    { int x=i,y=0;
      for (k=1;k<N;x>>=1,k<<=1) 
       (y<<=1)|=x&1;
      rev[i]=y;
    }
     for (i=0;i<N;i++) W[0][i]=W[1][i]=complex(cos(2.0*pi*i/N),sin(2.0*pi*i/N)),W[1][i].im=-W[0][i].im;
     for (i=0;i<len;i++)
       for (j=0;j<26;j++)
     { 
             sum[i][j]=sum[i-1][j]+(c[i]-'A'-j==0);
     }
     Go('A'-'A');
     Go('C'-'A');
     Go('G'-'A');
     Go('T'-'A');  
     for (i=0;i<len;i++) if (vis[i]==4) ans++;
     printf("%d\n",ans);
  //   for (;;);
}
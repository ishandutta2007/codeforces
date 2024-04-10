#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define M 1100005
#define seed 23333
#define Mo 998244353

using namespace std;
char c[M];
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1,x=1ll*x*x%Mo)
	    if (y&1) sum=1ll*sum*x%Mo;
	  return sum;
}
int i,j,m,n,p,k,N,inv2=power(2,Mo-2),a[M],A[M],B[M];
void FWT(int *a)
{
	  int i,j,k,l,t,x,y;
	  for (i=1;i<N;i<<=1)
	    for (j=0,l=N/(i<<1);j<N;j+=i<<1)
	      for (k=0,l=0;k<i;++k,l+=t)
	      {
	      	  x=a[j+k]; y=a[j+k+i];
	      	  a[j+k]=(x+y)%Mo; a[j+k+i]=(x-y+Mo)%Mo;
	      }
}
void NFWT(int *a)
{
	   int i,j,k,l,t,x,y;
	  for (i=1;i<N;i<<=1)
	    for (j=0,l=N/(i<<1);j<N;j+=i<<1)
	      for (k=0,l=0;k<i;++k,l+=t)
	      {
	      	  x=a[j+k]; y=a[j+k+i];
	      	  a[j+k]=1ll*(x+y)*inv2%Mo; a[j+k+i]=1ll*(x-y+Mo)*inv2%Mo;
	      }
}
int bit(int x)
{
	 int S=0;
	 for (;x;x>>=1) S+=x&1;
	 return S;
}
int main()
{
      scanf("%d%d",&n,&m);
      N=(1<<n);
      for (i=0;i<n;++i)
      {
      	  scanf("%s",c); 
      	  for (j=0;j<m;++j) a[j]=(a[j]<<1)|(c[j]-'0');
      }
      for (j=0;j<m;++j) A[a[j]]++;
	  for (i=0;i<N;++i) B[i]=min(n-bit(i),bit(i));
	  FWT(A); FWT(B);
	  for (i=0;i<N;++i) A[i]=1ll*A[i]*B[i]%Mo;
	  NFWT(A);
	  int Ans=n*m;
	  for (i=0;i<N;++i) Ans=min(Ans,A[i]);
	  printf("%d\n",Ans);
}
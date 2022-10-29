#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define NN 1100005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

const int Mo=1000000007;

using namespace std;

int i,j,m,n,p,k,inv2=500000004,A[NN],B[NN],ans,N;

char c[NN];

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo; 
		}
		return sum;
}

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
int size(int x)
{
		int s=0;
		for (;x;x>>=1) s+=(x&1);
		return s;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for (i=0;i<(1<<n);++i) A[i]=c[i]-'0';
	for (i=0;i<(1<<n);++i) B[i]=1-A[i];
	N=1<<n;
	FWT(A); FWT(B);
	for (i=0;i<(1<<n);++i) A[i]=1ll*A[i]*B[i]%Mo;
	NFWT(A); 
	for (i=0;i<(1<<n);++i) 
		(ans+=3ll*A[i]*power(2,size(i))%Mo)%=Mo;
	printf("%d\n",ans); 
}
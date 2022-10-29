#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,p,k,A[N],a,b,ans;
int main()
{
	  scanf("%d",&n); 
      for (i=1;i<=n;++i) scanf("%d",&A[i]);
      scanf("%d%d",&a,&b);
      sort(A+1,A+n+1);
      n=unique(A+1,A+n+1)-(A+1);
      while (a>b)
      {
      	  int y=1;
      	  for (i=1;i<=n;++i)
      	  {
      	  	   if (a%A[i]>y&&a-a%A[i]>=b) y=a%A[i];
      	  	   if (a-a%A[i]<b)
      	  	     swap(A[i],A[n]),--n,--i;
      	  }
      	  a-=y; ++ans;
      }
      printf("%d\n",ans);
}
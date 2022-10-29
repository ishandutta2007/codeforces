#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005
#define M 2000005
 
using namespace std;
int i,j,m,n,p,k,a[N],cnt,Q[N],prime[M];
int main()
{ 
     for (i=2;i<M;++i) prime[i]=1;
     for (i=2;i<M;++i)
       if (prime[i])
         for(j=i+i;j<M;j+=i) prime[j]=0;
     scanf("%d",&n);
	 for (i=1;i<=n;++i) 
	 {
	     scanf("%d",&a[i]); 
	     if (a[i]==1) ++cnt;
	 }
	 int Ans=1; Q[1]=a[1];
	 if (cnt>Ans) 
	 {
	 	  Ans=cnt;
	 	  for (i=1;i<=Ans;++i) Q[i]=1;
	 }
	 for (i=1;i<=n;++i)
	    if (a[i]>1&&prime[a[i]+1])
		{ 
		    Ans=cnt+1;
			for (j=1;j<Ans;++j) Q[j]=1;
			Q[Ans]=a[i];
			break;
		}
	 for (i=1;i<=n;++i)
	   for (j=i+1;j<=n;++j)
	       if (a[i]>1&&a[j]>1&&prime[a[i]+1]&&prime[a[j]+1]&&prime[a[i]+a[j]])
	       {
	       	  Ans=cnt+2;
	       	  for (j=1;j<Ans-1;++j) Q[j]=1; 
	       	  Q[Ans]=a[i]; Q[Ans-1]=a[j];
	       	  break;
	       }
	 for (i=1;i<=n;++i)
	   for (j=i+1;j<=n;++j)
	     if (prime[a[i]+a[j]]&&Ans<2)
	     {
	     	   Ans=2;
	     	   Q[1]=a[i]; Q[2]=a[j];
	     }
	printf("%d\n",Ans);
	for (i=1;i<=Ans;++i) printf("%d ",Q[i]); 
}
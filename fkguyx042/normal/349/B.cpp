#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[10],Min,su[10];
int main()
{
	 scanf("%d",&n); Min=(int)1e9;
	 for (i=1;i<=9;++i) scanf("%d",&a[i]),Min=min(Min,a[i]);
	 if (n/Min==0) printf("-1\n");
	 else 
	 {
	 	   int Lim=n/Min;
	 	  int sum=0;
	 	  for (i=9;i;--i)
	 	    while (n>=a[i]&&(n-a[i])/Min+sum+1==Lim) n-=a[i],su[i]++,++sum;
	 	  for (i=9;i;--i) 
	 	    for (j=1;j<=su[i];++j) printf("%d",i);
	 }
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int inv[100005];
int power(int x,int y)
{ 
    int sum=1;
    for (;y;y>>=1)
    {
    	  if (y&1) sum=1ll*sum*x%n;
    	  x=1ll*x*x%n;
    }
	return sum;
}
int main()
{
	  scanf("%d",&n);
	  if (n==1) printf("YES\n1\n");
	  else if (n==4) printf("YES\n1\n3\n2\n4\n");
	  else 
	  {    
	        inv[1]=1;
	  	   for (i=2;i<n;i++)
	  	   {   
	  	       if (n%i==0) { printf("NO\n"); return 0;}
	  	       inv[i]=power(i,n-2);
	  	   }
	  	   printf("YES\n1\n");
	  	   for (i=2;i<=n;i++)
	  	     printf("%d\n",(1ll*inv[i-1]*i-1)%n+1);
	  }
}
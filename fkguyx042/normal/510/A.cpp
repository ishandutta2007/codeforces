#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{   
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
{  
    if (i&1)
      for (j=1;j<=m;j++) printf("#");
    else 
	{  
	    if (((i/2)&1)==0) printf("#");
		for (j=1;j<m;j++) printf(".");
		if ((i/2)&1) printf("#");
   }
   printf("\n");
}
}
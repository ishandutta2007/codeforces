#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,i,j;
int main()
{
	 scanf("%d",&n);
	 for (i=n/7;i>=0;--i)
	 	  if ((n-i*7)%4==0)
	 	{
	 		   for (j=1;j<=(n-i*7)/4;++j) printf("4");
	 		   for (j=1;j<=i;++j) printf("7");
	 		   return 0;
	 	}
	 	printf("-1\n");
	 	
}
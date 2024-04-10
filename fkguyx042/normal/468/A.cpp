#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,n;
int main()
{scanf("%d",&n);
  if (n<=3) printf("NO\n");
  else if (n==4) {printf("YES\n");
  	  printf("4 * 3 = 12\n");
  	  printf("12 * 2 = 24\n");
  	  printf("24 * 1 = 24\n");
  }
  else if (n==5)
  {printf("YES\n");  printf("4 * 3 = 12\n");
     printf("5 - 1 = 4\n");
     printf("4 - 2 = 2\n");
     printf("12 * 2 = 24\n");
  }
  else { printf("YES\n");
  	    if (n%2==0)
  	      { 
  	         for (i=n;i>6;i-=2)
  	         {  printf("%d - %d = 1\n",i,i-1);
			    printf("6 * 1 = 6\n");
		     }
		     printf("4 * 6 = 24\n");
		     printf("5 - 3 = 2\n");
		     printf("2 - 2 = 0\n");
			 printf("1 - 0 = 1\n");
			 printf("24 * 1 = 24\n");
	}
	else {
		  for (i=n;i>7;i-=2)
		  {  printf("%d - %d =1\n",i,i-1);
		     printf("6 * 1 = 6\n");
	     }
	     printf("4 * 6 = 24\n");
		 printf("7 - 5 = 2\n");
		 printf("2 + 2 = 4\n");
		 printf("4 - 3 = 1\n");
		 printf("1 - 1 = 0\n");
		 printf("24 + 0 = 24\n");
	}
  }
}
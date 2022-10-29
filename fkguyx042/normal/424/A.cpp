#include<cstdio>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
char c[201];
int main()
 {scanf("%d",&n);
  scanf("%s",&c);
  for (i=1;i<=strlen(c);i++)
   if (c[i-1]=='X') j++;
 if (j==n/2){ printf("0\n"); printf("%s\n",&c); }
 else if(j>n/2) { printf("%d\n",j-n/2); for (i=1;i<=strlen(c);i++)
   if (j!=n/2) 
     { if (c[i-1]=='X') j--;
       printf("x");
       }
      else printf("%c",c[i-1]);
 printf("\n");
} 
else { printf("%d\n",n/2-j); for (i=1;i<=strlen(c);i++)
     if (j!=n/2) 
     { if (c[i-1]=='x') j++;
       printf("X");
       }
      else printf("%c",c[i-1]);
 printf("\n");
}
return 0;
}
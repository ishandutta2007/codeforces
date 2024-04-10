#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[101];
char s[13];
int i,j,m,n,p,k,t,f;
int main()
 {scanf("%d",&t);
  for (;t--;)
   {scanf("%s",s+1);
     memset(a,0,sizeof(a));
     for (i=1;i<=12;i++)
      if (12%i==0)
       {  for (j=1;j<=12/i;j++)
          { f=1;
             for (k=1;k<=i;k++)
               if (s[(k-1)*(12/i)+j]=='O') 
                 {f=0; break;}
               if (f){ a[++a[0]]=i; break;}
               }
               }
       printf("%d",a[0]);
       for (i=1;i<=a[0];i++)
        printf(" %dx%d",a[i],12/a[i]);
        printf("\n");
}
return 0;
}
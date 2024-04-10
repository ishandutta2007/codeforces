#include <stdio.h>

#define w1 while(1)
#define sint(n) scanf("%d",&n)
#define pint(n) printf("%d\n",n)
#define For(n) for(i=1;i<=n;i++)
#define For0(n) for(i=0;i<n;i++)
#define fill(n,m) memset(n,m,sizeof(n))

int main()
{
    int i,n,k,l,j;
    int m=1;
    scanf("%d %d",&n,&k);
    printf("1");
    l=1;
        for(j=k;j>0;j--)
    {
                           l = l + (j*m);
                           
                           if(m==1) m=-1;
                           else m=1;
                           
                           printf(" %d",l);
    }
        for(i=k+2;i<=n;i++)
        {
                           printf(" %d",i);
        }
    return 0;
}
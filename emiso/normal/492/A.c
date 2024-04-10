#include <stdio.h>

int main()
{
    int x,i=0,s=0,l=0;
    scanf("%d",&x);
    while(1)
    {
              i++;    // 1 2
              l=l+i;  // 1 3
              s=s+l;  // 1 4 
              x = x-l;// 3 0
              if(x<0)
              {
                     printf("%d\n",i-1);
                     break;
              }
              if(x==0)
              {
                     printf("%d\n",i);
                     break;
              }
    }
    return 0;
}
//EM NOME DE ABELLA
#include <stdio.h>

int main()
{
    int n,rows,x,chairs,i,j;
    scanf("%d",&n);
    if(n<=4) rows=0;
    chairs=n;
    if(n>4)
    { 
      x = n-4;
      rows = (x/3)+1;
      chairs=x%3;
    }
    puts("+------------------------+");
    for(i=1;i<=4;i++)
    {
              if(i!=3) 
              {
                     printf("|");
                     for(j=1;j<=11;j++)
                     {
                         if(rows>=j ||(j==rows+1 && chairs>=i)) printf("O.");
                         else printf("#.");
                     }
                     if(i==1)puts("|D|)");
                     else if(i==2) puts("|.|");
                     else puts("|.|)");
              }
              else 
              {
                   if(rows>0 || chairs>=3) puts("|O.......................|");
                   else puts("|#.......................|");  
              }
                                          
    }
    puts("+------------------------+");
    return 0;
}
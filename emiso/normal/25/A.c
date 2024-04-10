#include <stdio.h>

int main()
{
    int n,i,par=0,impar=0,lixo,lixao;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
                     scanf("%d",&lixo);
                     if(lixo%2 == 0 && par==0) par=i;
                     else if(lixo%2 == 1 && impar==0) impar=i;
                     else if(lixo%2 == 1 && impar!=0)
                     {
                          lixao=0;
                     }
                     else if(lixo%2 == 0 && par!=0)
                     {
                          lixao=1;
                     }
    }
    if(lixao==0) printf("%d\n",par);
    else printf("%d\n",impar);
    return 0;
}
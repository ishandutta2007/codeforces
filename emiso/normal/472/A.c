// EM NOME DE ABELLA
#include <stdio.h>
#include <string.h>

int primo[1000002];

void prima()
{
     int ii,jj;
     for(ii=0;ii<1000002;ii++) primo[ii]=1;
     for(ii=2;ii<1000001;ii++)
     {
                              jj=ii;
                              if(primo[ii]==1)
                              {
                                              jj+=ii;
                                              while(jj<1000001)
                                              {
                                                               primo[jj]=0;
                                                               jj+=ii;
                                              }
                              }
     }
}

int main()
{
    int i,n;
    prima();
    scanf("%d",&n);
    for(i=2;i<n-1;i++)
    {
            if(!primo[i] && !primo[n-i])
            {
                        printf("%d %d\n",i,n-i);
                        return 0;
            }
    }
    return 0;
}
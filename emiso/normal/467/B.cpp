#include <stdio.h>

int main()
{
    int n,m,k,c=0,ci,i,j,v[1005];
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<=m;i++)
    {
          scanf("%d",&v[i]);  
    }
    for(i=0;i<m;i++)
    {
          ci=0; 
          for(j=n-1;j>=0;j--)
          {
                             int x = (v[i] & (1<<j)) != 0;
                             int y = (v[m] & (1<<j)) != 0;
                             if(x!=y) ci++;
          } 
          if(ci<=k) c++;
    }
    printf("%d\n",c);
    return 0;
}
#include <stdio.h>

int main()
{
    int n,h[150005],l,ms=0,i,mi,s=0;
    scanf("%d %d",&n,&l);
    for(i=1;i<=n;i++)
    {
                     scanf("%d",&h[i]);
                     if(i<=l) s+=h[i];
    }
    ms=s;
    mi=1;
    for(i=l+1;i<=n;i++)
    {
                      s = s + h[i] - h[i-l];
                      if(ms>s)
                      {
                              ms = s;
                              mi = i + 1 - l;
                      }
    }
    printf("%d\n",mi);
    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    int l[102],i,ok=1,a,b,n;
    memset(l,0,sizeof(l));
    scanf("%d",&n);
    scanf("%d",&a);
    for(;a>0;a--)
    {
                 scanf("%d",&b);
                 l[b]=1;
    }
    scanf("%d",&a);
    for(;a>0;a--)
    {
                 scanf("%d",&b);
                 l[b]=1;
    }
    for(a=1;a<=n;a++) if(l[a]==0) ok=0;
    if(ok==0) puts("Oh, my keyboard!");
    else puts("I become the guy.");
    return 0;
}
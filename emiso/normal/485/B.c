#include <stdio.h>


int main()
{
    long long i,n,x,y;
    long long xma=-1,xmi=-1,yma=-1,ymi=-1,s;
    long long z;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
           scanf("%lld %lld",&x,&y);
           if(i == 0 || xma < x) xma = x;
           if(i == 0 || xmi > x) xmi = x;
           if(i == 0 || yma < y) yma = y;
           if(i == 0 || ymi > y) ymi = y;
    }
    if((xma-xmi)>(yma-ymi)) z = xma-xmi;
    else z = yma-ymi;
    s = z * z;
    printf("%lld\n",s);
    return 0;
}
#include <stdio.h>

int gcd (int x, int y)
{
    int rem;
    while(1)
    {
            rem = x%y;
            if(rem == 0) break;
            x=y;
            y=rem;
    }
    return y;
}

int main()
{
    int a,b,x,y,mmc;
    scanf("%d %d %d %d",&x,&y,&a,&b);
    mmc = (x * y) / gcd(x,y);
    
    if(a%mmc != 0) a = ((a/mmc)+1)*mmc;
    if(b%mmc != 0) b = (b/mmc)*mmc;
    
    if(a>b) printf("0\n");
    else printf("%d\n",((b-a)/mmc)+1);
    return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int r,g,b;
    Int color=0;
    Int minute=0;
    Int ending;
    
    scanf("%I64d %I64d %I64d",&r,&g,&b);
    while (r+b+g>0)
    {
        if (color==0)
        {
            r-=2;
            ending=minute+30;
            if (r<0)
            r=0;
        }
        else if (color==1)
        {
            g-=2;
            ending=minute+30;
            if (g<0)
            g=0;
        }
        else
        {
            b-=2;
            ending=minute+30;
            if (b<0)
            b=0;
        }
        minute++;
        color=(color+1)%3;
    }
    printf("%I64d\n",ending);
    return 0;
}
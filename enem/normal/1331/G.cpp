#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a[11];
    for(int i=0;i<11;i++)
    {
        scanf("%f",&a[i]);
    }
    for(int i=10;i>=0;i--)
    {
        float ansa=sqrt(abs(a[i]));
        float ansb=pow(a[i],3)*5;
        float ans=ansa+ansb;
        if(ans<=400)
        {
            printf("f(%d) = %.2f\n",(int)(a[i]),ans);
        }
        else
        {
            printf("f(%d) = MAGNA NIMIS!\n",(int)(a[i]));
        }
    }

    return 0;
}
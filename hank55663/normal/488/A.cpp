#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,ok=0,i=0;
    scanf("%d",&n);
    while(!ok)
    {
        n++;
        for(int k=n;k!=0;k/=10)
        if(k%10==8||k%10==-8)
        {
            ok=1;
            break;
        }
        i++;
    }
    printf("%d",i);
    return 0;
}
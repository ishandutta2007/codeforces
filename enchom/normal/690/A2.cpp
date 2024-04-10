#include <iostream>
#include <stdio.h>
using namespace std;

int N;

int main()
{
    int i;
    int num;
    int ans;

    scanf("%d",&N);

    num=1;

    while(num<=N)
    {
        if ( (N-num)%2==0 )
        ans=(N-num)/2;

        num*=2;
    }

    printf("%d\n",ans);

    return 0;
}
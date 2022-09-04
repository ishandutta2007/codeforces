#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
main()
{
    int a[6];
    int num[10]={0};
    int four=0,two=0;
    for(int i=0;i<6;i++)
    {
        scanf("%d",&a[i]);
        num[a[i]]++;
    }
    for(int i=0;i<10;i++)
    {
        if(num[i]>=4)
            four=1;
        if(num[i]==6||num[i]==2)
            two=1;
    }
    if(four&&!two)
    {
        printf("Bear\n");
    }
    else if(four&&two)
    {
        printf("Elephant\n");
    }
    else
    {
        printf("Alien\n");
    }
    return 0;
}
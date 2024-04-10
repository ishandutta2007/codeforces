#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(n==k)
        {
            puts("0");
            continue;
        }
        if(n<k)
        {
            printf("%d\n",k-n);
            continue;
        }
        if((n-k)&1)
            puts("1");
        else
            puts("0");
    }
    return 0;
}
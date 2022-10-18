#include<iostream>
#include<cstdio>
using namespace std;
int t,l,r;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        if(r>=l<<1)
            printf("%d %d\n",l,l<<1);
        else
            puts("-1 -1");
    }
    return 0;
}
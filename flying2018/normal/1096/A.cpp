#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d %d\n",l,l*2);
    }
    return 0;
}
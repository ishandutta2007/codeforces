#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l*2<=r) printf("%d %d\n",l,l*2);
        else puts("-1 -1");
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d",&n);
        int m=n/10;
        if(n%10==9) m++;
        printf("%d\n",m);
    }
    return 0;
}
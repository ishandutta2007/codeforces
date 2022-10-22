#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",n/2+1);
    }
    return 0;
}
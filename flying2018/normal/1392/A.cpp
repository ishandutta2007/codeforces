#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool all=true;
        for(int i=2;i<=n;i++) all=all && a[i]==a[i-1];
        if(all) printf("%d\n",n);
        else puts("1");
    }
    return 0;
}
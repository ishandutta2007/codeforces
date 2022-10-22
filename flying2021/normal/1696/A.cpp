#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
using namespace std;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,z;scanf("%d%d",&n,&z);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,a[i]|z);
        printf("%d\n",mx);
    }
    return 0;
}
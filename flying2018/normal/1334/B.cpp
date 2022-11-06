#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        long long s=0;int p=0;
        for(p=1;p<=n;p++)
        if(s+a[p]<1ll*p*k) break;
        else s+=a[p];
        printf("%d\n",p-1);
    }
    return 0;
}
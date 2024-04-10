#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
using namespace std;
int a[N];
int main()
{
    int n,m;
    scanf("%d",&n);
    long long s=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
    sort(a+1,a+n+1,greater<int>());
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        printf("%lld\n",s-a[k]);
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
using namespace std;
int a[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=a[n]-a[1];
    for(int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
    sort(a+1,a+n,greater<int>());
    for(int i=1;i<=k-1;i++) ans-=a[i];
    printf("%d\n",ans);
    return 0;
}
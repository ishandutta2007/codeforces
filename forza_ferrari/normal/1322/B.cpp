#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[400001],b[400001],ans;
inline bool calc(int x,int y)
{
    if(x>y)
        return 0;
    int res=0,l=1,r=1;
    for(register int i=n;i;--i)
    {
        while(l<=n&&b[i]+b[l]<x)
            ++l;
        while(r<=n&&b[i]+b[r]<=y)
            ++r;
        res+=r-l-(l<=i&&r>i);
    }
    return (res>>1)&1;
}
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(register int i=0;i<=30;++i)
    {
        for(register int j=1;j<=n;++j)
            b[j]=a[j]&((1<<(i+1))-1);
        sort(b+1,b+n+1);
        ans|=(calc(1<<i,(1<<(i+1))-1)^calc(3<<i,(1<<(i+2))-2))<<i;
    }
    printf("%d\n",ans);
    return 0;
}
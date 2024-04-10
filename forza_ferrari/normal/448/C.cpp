#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,a[5005],ans;
int solve(int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return a[l]!=0;
    int minn=1<<30,p=l;
    for(register int i=l;i<=r;++i)
        minn=min(minn,a[i]);
    for(register int i=l;i<=r;++i)
        a[i]-=minn;
    int sum=minn;
    if(sum>r-l+1)
        return r-l+1;
    for(register int i=l;i<=r;++i)
        if(!a[i])
        {
            sum+=solve(p,i-1);
            p=i+1;
            if(sum>r-l+1)
                return r-l+1;
        }
    sum+=solve(p,r);
    return min(sum,r-l+1);
}
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    printf("%lld\n",solve(1,n));
    return 0;
}
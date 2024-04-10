#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n,a[200001],ans;
map<int,int> mp;
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        mp[a[i]-i]+=a[i];
        ans=max(ans,mp[a[i]-i]);
    }
    printf("%lld\n",ans);
    return 0;
}
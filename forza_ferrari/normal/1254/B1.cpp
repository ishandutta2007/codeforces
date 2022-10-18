#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> v;
int n,a[100001],ans,res;
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        if(a[i])
            v.push_back(i);
    }
    if(v.size()==1)
    {
        puts("-1");
        return 0;
    }
    n=v.size();
    ans=1ll<<60;
    for(register int i=2;i<=n;++i)
    {
        if(n%i)
            continue;
        res=0;
        for(register int j=0;j<n;j+=i)
        {
            int l=j,r=j+i-1;
            while(l<r)
            {
                res+=v[r]-v[l];
                ++l,--r;
            }
        }
        if(res>0)
            ans=min(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}
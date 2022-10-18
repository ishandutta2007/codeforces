#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int t,n,m,a[200001],ans,cnt[1001];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;++i)
            cnt[i]=0;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ++cnt[a[i]%m];
            ans+=a[i]/m;
        }
        int l=1,r=m-1,val=0;
        while(l<r)
        {
            val+=cnt[r];
            ans+=min(cnt[l],val);
            val-=min(val,cnt[l]);
            ++l,--r;
        }
        if(l==r)
        {
            ans+=cnt[l]>>1;
            ans+=min(cnt[l]&1,val);
            val-=min(cnt[l]&1,val);
        }
        ans+=val>>1;
        cout<<ans<<'\n';
    }
    return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a,b,ans,pos[200001],sum[200001];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>pos[i];
            sum[i]=sum[i-1]+pos[i];
        }
        int p=0;
        for(int i=1;i<=n;++i)
        {
            if(a*(pos[i-1]-pos[p])+b*(sum[n]-sum[i-1]-(n-i+1)*pos[i-1])<=b*(sum[n]-sum[i-1]-(n-i+1)*pos[p]))
            {
                ans+=a*(pos[i-1]-pos[p]);
                p=i-1;
            }
            ans+=b*(pos[i]-pos[p]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
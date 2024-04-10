#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,sum[4001],cnt,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        for(int i=0;i<=n<<1;++i)
            sum[i]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                char c;
                cin>>c;
                sum[i-j+n]+=c-'0';
                cnt+=c-'0';
            }
        ans=n*n-sum[n]+cnt-sum[n];
        for(int i=1;i<=n;++i)
            ans=min(ans,n-sum[i]-sum[i+n]+cnt-sum[i]-sum[i+n]);
        cout<<ans<<'\n';
    }
    return 0;
}
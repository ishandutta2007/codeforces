#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int n,a[200001][2],b[200001][2],ans;
signed main()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i][0];
        sum+=a[i][0];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a[i][1];
        sum+=a[i][1];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>b[i][0];
        b[i][0]+=b[i-1][0];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>b[i][1];
        b[i][1]+=b[i-1][1];
    }
    if(sum!=b[n][0]+b[n][1])
    {
        cout<<"-1\n";
        return 0;
    }
    int sum0=0,sum1=0;
    for(int i=1;i<=n;++i)
    {
        sum0+=a[i][0];
        sum1+=a[i][1];
        while(sum0<b[i][0]&&sum1>b[i][1])
        {
            ++sum0;
            --sum1;
            ++ans;
        }
        while(sum0>b[i][0]&&sum1<b[i][1])
        {
            --sum0;
            ++sum1;
            ++ans;
        }
        ans+=abs(sum0-b[i][0])+abs(sum1-b[i][1]);
    }
    cout<<ans<<'\n';
    return 0;
}
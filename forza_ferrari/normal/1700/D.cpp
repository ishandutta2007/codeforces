#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,sum[200001],maxn;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
        maxn=max(maxn,(sum[i]+i-1)/i);
    }
    cin>>m;
    while(m--)
    {
        int t;
        cin>>t;
        if(t<maxn)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<(sum[n]+t-1)/t<<'\n';
    }
    return 0;
}
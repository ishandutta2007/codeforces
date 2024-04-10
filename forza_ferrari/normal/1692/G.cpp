#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[200001],sum[200001],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ++m;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum[i]=0;
        }
        for(int i=2;i<=n;++i)
        {
            sum[i]=sum[i-1]+(2*a[i]>a[i-1]);
            if(i-m+1>=1)
                ans+=sum[i]-sum[i-m+1]==m-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
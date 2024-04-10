#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[101],sum[101],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+(a[i]==0);
        }
        ans=0;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;++j)
                ans+=j-i+1+sum[j]-sum[i-1];
        cout<<ans<<endl;
    }
    return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int t,n,m,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=1;
        for(int i=1;i<=m;++i)
            ans=1ll*ans*i%mod;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(i>n-m)
            {
                if(x>0)
                    ans=0;
            }
            else if(x>0)
            {
                if(x>=i)
                    ans=0;
            }
            else if(x==0)
                ans=1ll*ans*(m+1)%mod;
            else
                ans=1ll*ans*(m+i)%mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
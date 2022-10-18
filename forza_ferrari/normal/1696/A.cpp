#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            ans=max(ans,x|m);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
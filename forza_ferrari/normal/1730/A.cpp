#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,ans,cnt[101];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=100;++i)
            cnt[i]=0;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            ++cnt[x];
        }
        for(int i=0;i<=100;++i)
            ans+=min(cnt[i],m);
        cout<<ans<<'\n';
    }
    return 0;
}
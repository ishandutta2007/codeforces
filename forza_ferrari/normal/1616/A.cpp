#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,cnt[101],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=100;++i)
            cnt[i]=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            ++cnt[abs(x)];
        }
        ans=min(1,cnt[0]);
        for(int i=1;i<=100;++i)
            ans+=min(2,cnt[i]);
        cout<<ans<<'\n';
    }
    return 0;
}
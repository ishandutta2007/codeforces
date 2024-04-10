#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,m,mod,cnt[100001],ans,x,y;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>mod>>s>>x>>y;
        s=" "+s;
        ans=2e9;
        for(int i=0;i<mod;++i)
            cnt[i]=0;
        for(int i=m;i<=n;++i)
            cnt[i%mod]+=s[i]=='0';
        for(int i=m;i<=n;++i)
        {
            ans=min(ans,cnt[i%mod]*x+(i-m)*y);
            cnt[i%mod]-=s[i]=='0';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
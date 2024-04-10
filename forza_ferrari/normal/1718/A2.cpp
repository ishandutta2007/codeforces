#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int t,n,a[100001],dp[100001];
map<int,int> mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        mp.clear();
        mp[0]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            a[i]^=a[i-1];
            dp[i]=dp[i-1]+1;
            if(mp.count(a[i]))
                dp[i]=min(dp[i],i+mp[a[i]]-1);
            mp[a[i]]=dp[i]-i;
        }
        cout<<dp[n]<<'\n';
    }
    return 0;
}
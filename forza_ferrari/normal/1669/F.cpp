#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int t,n,a[200001],ans;
map<int,int> mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            a[i]+=a[i-1];
        }
        mp.clear();
        mp[0]=0;
        ans=0;
        for(int i=n;i>=1;--i)
        {
            if(mp.count(a[i]))
                ans=max(ans,i+mp[a[i]]);
            mp[a[n]-a[i-1]]=n-i+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
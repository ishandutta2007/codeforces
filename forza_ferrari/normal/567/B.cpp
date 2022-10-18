#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int n,sum[105];
map<int,int> mp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        char c;
        int x;
        cin>>c>>x;
        if(c=='+')
            mp[x]=i;
        else
        {
            if(mp.count(x))
            {
                ++sum[mp[x]];
                --sum[i+1];
                mp.erase(x);
            }
            else
            {
                ++sum[1];
                --sum[i+1];
            }
        }
    }
    for(auto i:mp)
        ++sum[i.second];
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        sum[i]+=sum[i-1];
        ans=max(ans,sum[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
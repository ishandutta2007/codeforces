#include<bits/stdc++.h>

int main()
{
    int n,k;
    std::cin>>n>>k;
    std::map<int,int> mp;
    while(n--)
    {
        int t;
        std::cin>>t;
        mp[t]++;
    }
    int l=1,r=(1<<20);
    while(l<r)
    {
        int x=((l+r)>>1)+1;
        int t=0;
        for(auto it:mp)
        {
            t+=it.second/x;
        }
        if(t>=k)
            l=x;
        else
            r=x-1;
    }
    std::vector<int> ans;
    for(auto it:mp)
    {
        for(int i=0;i<it.second/l;i++)
        {
            ans.push_back(it.first);
        }
    }
    for(int i=0;i<k;i++)
        std::cout<<ans[i]<<' ';
    return 0;
}
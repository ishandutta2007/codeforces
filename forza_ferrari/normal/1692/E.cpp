#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,m;
vector<int> v;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        v.clear();
        v.emplace_back(0);
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(x)
                v.emplace_back(i);
        }
        v.emplace_back(n+1);
        if(v.size()-2<m)
        {
            cout<<"-1\n";
            continue;
        }
        int ans=0;
        for(int i=m+1;i<(int)v.size();++i)
            ans=max(ans,v[i]-v[i-m-1]-1);
        cout<<n-ans<<'\n';
    }
    return 0;
}
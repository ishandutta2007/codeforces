#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define int long long
int t,n,ans;
vector<int> v[200001];
priority_queue<int,vector<int>,greater<int> > q;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
            v[i].clear();
        while(!q.empty())
            q.pop();
        ans=0;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            v[x].emplace_back(y);
        }
        for(int i=n-1;~i;--i)
        {
            for(auto j:v[i])
                q.emplace(j);
            while(q.size()>n-i)
            {
                ans+=q.top();
                q.pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
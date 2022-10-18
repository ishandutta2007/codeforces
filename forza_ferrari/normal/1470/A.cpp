#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[300001],c[300001],ans;
priority_queue<int> q;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        while(!q.empty())
            q.pop();
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=m;++i)
            cin>>c[i];
        ans=0;
        for(int i=1;i<=n;++i)
        {
            ans+=c[a[i]];
            q.emplace(c[a[i]]);
        }
        sort(c+1,c+m+1);
        for(int i=1;i<=m;++i)
        {
            if(q.empty())
                break;
            if(c[i]>=q.top())
                break;
            ans+=c[i]-q.top();
            q.pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}
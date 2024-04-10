#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m,x,a[100001],ans[100001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
        for(int i=1;i<=m;++i)
            q.emplace(0,i);
        for(int i=1;i<=n;++i)
        {
            pair<int,int> k=q.top();
            q.pop();
            ans[i]=k.second;
            q.emplace(k.first+a[i],k.second);
        }
        int minn=q.top().first,maxn=0;
        while(!q.empty())
        {
            maxn=q.top().first;
            q.pop();
        }
        if(maxn-minn>x)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}
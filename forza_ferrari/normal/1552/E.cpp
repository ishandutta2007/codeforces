#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,val[10001];
pair<int,int> ans[101];
bool vis[101];
vector<int> a[101];
vector<pair<int,int> > v;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
    {
        cin>>val[i];
        a[val[i]].emplace_back(i);
    }
    for(int i=1;i<m;++i)
    {
        v.clear();
        for(int j=1;j<=n;++j)
            if(!vis[j])
                v.emplace_back(a[j][i],a[j][i-1]);
        sort(v.begin(),v.end());
        for(int j=0;j<min((int)v.size(),(n+m-2)/(m-1));++j)
        {
            vis[val[v[j].first]]=1;
            ans[val[v[j].first]]={v[j].second,v[j].first};
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    return 0;
}
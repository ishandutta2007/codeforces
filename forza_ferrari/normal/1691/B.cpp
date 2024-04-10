#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,a[100001],cnt,node[100001],ans[100001];
vector<int> v[100001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            node[i]=a[i];
        }
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(int i=1;i<=cnt;++i)
            v[i].clear();
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            v[a[i]].emplace_back(i);
        }
        bool flag=1;
        for(int i=1;i<=cnt;++i)
        {
            if(v[i].size()==1)
            {
                flag=0;
                break;
            }
            if(v[i].empty())
                continue;
            ans[v[i][0]]=v[i].back();
            for(int j=1;j<(int)v[i].size();++j)
                ans[v[i][j]]=v[i][j-1];
        }
        if(flag)
        {
            for(int i=1;i<=n;++i)
                cout<<ans[i]<<" ";
            cout<<'\n';
        }
        else
            cout<<"-1\n";
    }
    return 0;
}
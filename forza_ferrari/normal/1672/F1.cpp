#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> pos[200001],num[200001],node,tmp;
int t,n,a[200001],ans[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            pos[i].clear();
            num[i].clear();
        }
        node.clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            pos[a[i]].emplace_back(i);
        }
        for(int i=1;i<=n;++i)
            if(pos[i].size())
                num[pos[i].size()].emplace_back(i);
        for(int i=1;i<=n;++i)
            if(num[i].size())
                node.emplace_back(i);
        for(int i=1;i<=n;++i)
        {
            tmp.clear();
            for(auto j:node)
                if(i<=j)
                    for(auto k:num[j])
                    {
                        tmp.emplace_back(pos[k].back());
                        pos[k].pop_back();
                    }
            for(int j=1;j<(int)tmp.size();++j)
                ans[tmp[j]]=a[tmp[j-1]];
            if(!tmp.empty())
                ans[tmp[0]]=a[tmp.back()];
        }
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}
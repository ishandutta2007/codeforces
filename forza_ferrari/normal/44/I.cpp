#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
bool vis[11];
vector<int> v;
vector<vector<int> > ans;
inline void dfs(int k)
{
    if(k>n)
    {
        ans.emplace_back(v);
        return;
    }
    if(vis[k])
    {
        v.emplace_back(1<<(k-1));
        dfs(k+1);
        v.pop_back();
        for(int i=(int)v.size()-1;i>=0;--i)
        {
            v[i]|=1<<(k-1);
            dfs(k+1);
            v[i]^=1<<(k-1);
        }
    }
    else
    {
        for(int i=0;i<(int)v.size();++i)
        {
            v[i]|=1<<(k-1);
            dfs(k+1);
            v[i]^=1<<(k-1);
        }
        v.emplace_back(1<<(k-1));
        dfs(k+1);
        v.pop_back();
    }
    vis[k]^=1;
}
int main()
{
    cin>>n;
    v.emplace_back(1);
    dfs(2);
    cout<<ans.size()<<'\n';
    for(auto i:ans)
    {
        bool tag=0;
        for(int j=0;j<(int)i.size();++j)
        {
            bool flag=0;
            if(tag)
                cout<<",{";
            else
            {
                cout<<'{';
                tag=1;
            }
            for(int k=1;k<=n;++k)
                if(i[j]&(1<<(k-1)))
                {
                    if(flag)
                        cout<<","<<k;
                    else
                    {
                        cout<<k;
                        flag=1;
                    }
                }
            cout<<'}';
        }
        cout<<'\n';
    }
    return 0;
}
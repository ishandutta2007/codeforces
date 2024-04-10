#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,m,sum,tot;
bool tag[300001],vis[300001];
vector<int> v[300001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void dfs(int k)
{
    ++tot;
    vis[k]=1;
    tag[k]=1;
    for(auto i:v[k])
        tag[k]&=tag[i]^1;
    for(auto i:v[k])
        if(!vis[i])
            dfs(i);
    sum+=tag[k];
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
        {
            v[i].clear();
            tag[i]=vis[i]=0;
        }
        tot=sum=0;
        for(int i=1;i<=m;++i)
        {
            int x=read(),y=read();
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        dfs(1);
        if(tot!=n)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<sum<<'\n';
        for(int i=1;i<=n;++i)
            if(tag[i])
                cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
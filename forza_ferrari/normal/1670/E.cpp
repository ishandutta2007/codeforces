#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,ans[1000001][2],cnt;
vector<pair<int,int> > v[1000001];
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
inline void dfs(int k,int f,int id,int deep)
{
    if(f)
    {
        if(deep&1)
        {
            ans[k][0]=++cnt+n;
            ans[id][1]=cnt;
        }
        else
        {
            ans[k][0]=++cnt;
            ans[id][1]=cnt+n;
        }
    }
    else
        ans[k][0]=n;
    for(auto i:v[k])
        if(i.first^f)
            dfs(i.first,k,i.second,deep+1);
}
int main()
{
    t=read();
    while(t--)
    {
        n=1<<read();
        cnt=0;
        for(int i=1;i<=n;++i)
            v[i].clear();
        for(int i=1;i<n;++i)
        {
            int x=read(),y=read();
            v[x].emplace_back(y,i);
            v[y].emplace_back(x,i);
        }
        dfs(1,0,0,1);
        cout<<"1\n";
        for(int i=1;i<=n;++i)
            cout<<ans[i][0]<<" ";
        cout<<'\n';
        for(int i=1;i<n;++i)
            cout<<ans[i][1]<<" ";
        cout<<'\n';
    }
    return 0;
}
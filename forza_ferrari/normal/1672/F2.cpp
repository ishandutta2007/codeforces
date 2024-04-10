#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[200001],b[200001],d[200001];
vector<int> v[200001];
bool vis[200001],tag[200001],flag;
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
    if(tag[k])
    {
        flag=0;
        return;
    }
    if(vis[k])
        return;
    vis[k]=tag[k]=1;
    for(int i:v[k])
        dfs(i);
    tag[k]=0;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
        {
            a[i]=read();
            v[i].clear();
            vis[i]=tag[i]=d[i]=0;
        }
        for(int i=1;i<=n;++i)
        {
            b[i]=read();
            ++d[a[i]];
        }
        int maxn=0,num=0;
        for(int i=1;i<=n;++i)
            if(d[i]>maxn)
            {
                maxn=d[i];
                num=i;
            }
        for(int i=1;i<=n;++i)
            if(a[i]!=num&&b[i]!=num)
                v[a[i]].emplace_back(b[i]);
        flag=1;
        for(int i=1;i<=n;++i)
            if(!vis[i])
                dfs(i);
        cout<<(flag? "AC":"WA")<<'\n';
    }
    return 0;
}
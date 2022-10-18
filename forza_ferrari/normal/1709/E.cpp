#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
vector<int> v[200001];
set<int> st[200001];
int n,a[200001],sum[200001],ans,son[200001],s[200001];
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
inline void dfs1(int k,int f)
{
    sum[k]=sum[f]^a[k];
    s[k]=1;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs1(i,k);
        s[k]+=s[i];
        if(s[i]>s[son[k]])
            son[k]=i;
    }
}
inline void dfs2(int k,int f)
{
    if(son[k])
    {
        dfs2(son[k],k);
        swap(st[son[k]],st[k]);
    }
    bool flag=0;
    if(st[k].find(sum[k]^a[k])!=st[k].end())
        flag=1;
    else
        st[k].emplace(sum[k]);
    for(int i:v[k])
    {
        if(i==f||i==son[k])
            continue;
        dfs2(i,k);
        for(int j:st[i])
            if(st[k].find(j^a[k])!=st[k].end())
                flag=1;
        for(int j:st[i])
            st[k].emplace(j);
    }
    if(flag)
    {
        ++ans;
        st[k].clear();
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    cout<<ans<<'\n';
    return 0;
}
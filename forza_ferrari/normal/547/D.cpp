#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int m=2e5;
struct edge
{
    int nxt,to;
    bool vis;
}e[400001<<2];
int n,s,d[400005],cur[400005],tot=1,h[400005];
bool ans[400005],tag[400005];
vector<int> node;
map<pair<int,int>,int> mp;
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k)
{
    tag[k]=1;
    for(int i=cur[k];i;i=cur[k])
    {
        cur[k]=e[i].nxt;
        if(!e[i].vis)
        {
            e[i].vis=e[i^1].vis=1;
            dfs(e[i].to);
        }
    }
    node.emplace_back(k);
}
int main()
{
    n=read();
    s=m+m+1;
    for(int i=1;i<=n;++i)
    {
        int x=read(),y=read();
        ++d[x];
        ++d[y+m];
        add(x,y+m);
        add(y+m,x);
        mp[{x,y+m}]=mp[{y+m,x}]=i;
    }
    for(int i=1;i<=m+m;++i)
        if(d[i]&1)
        {
            ++d[i];
            ++d[s];
            add(i,s);
            add(s,i);
        }
    for(int i=1;i<=s;++i)
        cur[i]=h[i];
    for(int i=1;i<=s;++i)
        if(!tag[i]&&d[i])
        {
            node.clear();
            dfs(i);
            for(int j=1;j<(int)node.size();++j)
                if(mp.count({node[j-1],node[j]}))
                    ans[mp[{node[j-1],node[j]}]]=node[j]<=m;
        }
    for(int i=1;i<=n;++i)
        cout<<(ans[i]? 'r':'b');
    cout<<'\n';
    return 0;
}
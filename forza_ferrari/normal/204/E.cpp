#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define int long long
int n,m,tot,ch[100001<<1][26],len[100001<<1],link[100001<<1],cnt,root[100001<<1],ls[100001*40],rs[100001*40],sum[100001*40],ans[100001<<1];
vector<int> v[100001<<1],g[100001<<1];
bool tag[100001<<1];
inline void push_up(int k)
{
    sum[k]=sum[ls[k]]+sum[rs[k]];
}
inline int merge(int x,int y,int l,int r)
{
    if(!x||!y)
        return x|y;
    if(l==r)
    {
        sum[x]|=sum[y];
        return x;
    }
    int mid=(l+r)>>1;
    ls[x]=merge(ls[x],ls[y],l,mid);
    rs[x]=merge(rs[x],rs[y],mid+1,r);
    push_up(x);
    return x;
}
inline void update(int node,int l,int r,int &k)
{
    if(!k)
        k=++cnt;
    if(l==r)
    {
        sum[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls[k]);
    else
        update(node,mid+1,r,rs[k]);
    push_up(k);
}
inline void insert(int x)
{
    string s;
    cin>>s;
    int node=0;
    for(int i=0;i<(int)s.length();++i)
    {
        if(!ch[node][s[i]-'a'])
            ch[node][s[i]-'a']=++tot;
        node=ch[node][s[i]-'a'];
        v[node].emplace_back(x);
    }
}
inline int build(int lst,int c)
{
    int cur=ch[lst][c],p=link[lst];
    len[cur]=len[lst]+1;
    for(;~p;p=link[p])
        if(!ch[p][c])
            ch[p][c]=cur;
        else
            break;
    if(p==-1)
        return cur;
    int q=ch[p][c];
    if(len[p]+1==len[q])
    {
        link[cur]=q;
        return cur;
    }
    int clone=++tot;
    link[clone]=link[q];
    len[clone]=len[p]+1;
    for(int i=0;i<26;++i)
        if(len[ch[q][i]])
            ch[clone][i]=ch[q][i];
    link[cur]=link[q]=clone;
    for(;~p;p=link[p])
        if(ch[p][c]==q)
            ch[p][c]=clone;
        else
            break;
    return cur;
}
inline void bfs()
{
    queue<pair<int,int> > q;
    link[0]=-1;
    for(int i=0;i<26;++i)
        if(ch[0][i])
            q.emplace(0,i);
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        int node=build(k.first,k.second);
        for(auto i:v[node])
            update(i,1,n,root[node]);
        for(int i=0;i<26;++i)
            if(ch[node][i])
                q.emplace(node,i);
    }
}
inline void dfs1(int k)
{
    for(auto i:g[k])
    {
        dfs1(i);
        root[k]=merge(root[k],root[i],1,n);
        tag[k]|=tag[i];
    }
    tag[k]|=sum[root[k]]>=m;
}
inline void dfs2(int k,int val)
{
    for(auto i:g[k])
        dfs2(i,tag[i]? len[i]:val);
    for(auto i:v[k])
        ans[i]+=val;
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        insert(i);
    bfs();
    for(int i=1;i<=tot;++i)
        g[link[i]].emplace_back(i);
    dfs1(0);
    dfs2(0,0);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}
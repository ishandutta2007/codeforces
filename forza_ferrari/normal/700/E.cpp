#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int ans,n,tot,lst,ch[200001<<1][26],len[200001<<1],link[200001<<1],pos[200001<<1],cnt,root[200001<<1],ls[200001*80],rs[200001*80],sum[200001*80],dp[200001<<1],g[200001<<1];
string s;
vector<int> v[200001<<1];
inline void push_up(int k)
{
    sum[k]=sum[ls[k]]+sum[rs[k]];
}
inline int merge(int x,int y,int l,int r)
{
    if(!x||!y)
        return x|y;
    int k=++cnt;
    if(l==r)
    {
        sum[k]=sum[x]+sum[y];
        return k;
    }
    int mid=(l+r)>>1;
    ls[k]=merge(ls[x],ls[y],l,mid);
    rs[k]=merge(rs[x],rs[y],mid+1,r);
    push_up(k);
    return k;
}
inline void update(int node,int l,int r,int &k)
{
    if(!k)
        k=++cnt;
    if(l==r)
    {
        ++sum[k];
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls[k]);
    else
        update(node,mid+1,r,rs[k]);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(!k)
        return 0;
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls[k]);
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs[k]);
    return res;
}
inline void build(int c,int id)
{
    int cur=++tot,p=lst;
    update(id,1,n,root[tot]);
    pos[cur]=id;
    len[cur]=len[lst]+1;
    lst=cur;
    for(;~p;p=link[p])
        if(!ch[p][c])
            ch[p][c]=lst;
        else
            break;
    if(p==-1)
        return;
    int q=ch[p][c];
    if(len[p]+1==len[q])
    {
        link[cur]=q;
        return;
    }
    int clone=++tot;
    pos[clone]=pos[q];
    link[clone]=link[q];
    len[clone]=len[p]+1;
    for(int i=0;i<26;++i)
        ch[clone][i]=ch[q][i];
    link[q]=link[cur]=clone;
    for(;~p;p=link[p])
        if(ch[p][c]==q)
            ch[p][c]=clone;
        else
            break;
}
inline void dfs1(int k,int f)
{
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs1(i,k);
        root[k]=merge(root[k],root[i],1,n);
    }
}
inline void dfs2(int k,int f)
{
    if(k)
    {
        if(f)
        {
            if(query(pos[k]+len[g[f]]-len[k],pos[k]-1,1,n,root[g[f]]))
            {
                g[k]=k;
                dp[k]=dp[f]+1;
            }
            else
            {
                g[k]=g[f];
                dp[k]=dp[f];
            }
        }
        else
        {
            g[k]=k;
            dp[k]=1;
        }
        ans=max(ans,dp[k]);
    }
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs2(i,k);
    }
}
int main()
{
    cin>>n>>s;
    link[0]=-1;
    s=" "+s;
    for(int i=1;i<=n;++i)
        build(s[i]-'a',i);
    for(int i=1;i<=tot;++i)
        v[link[i]].emplace_back(i);
    dfs1(0,0);
    dfs2(0,0);
    cout<<ans<<'\n';
    return 0;
}
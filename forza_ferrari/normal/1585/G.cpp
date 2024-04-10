#include<iostream>
#include<cstdio>
#include<map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> val[500001];
int t,ans,n,fa[500001],minn[500001],p[500001],tmp[2000001],*id=tmp,*sg[500001],len[500001],son[500001];
vector<int> v[500001];
map<int,int> cnt[500001];
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
inline void dfs1(int k)
{
    minn[k]=n;
    for(int i:v[k])
    {
        dfs1(i);
        if(len[i]>len[son[k]])
            son[k]=i;
        minn[k]=min(minn[k],minn[i]+1);
    }
    len[k]=len[son[k]]+1;
    if(v[k].empty())
    {
        len[k]=2;
        minn[k]=1;
    }
}
inline int mex(int l,int r,int k)
{
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    if(val[k].order_of_key(mid+1)==mid+1)
        return mex(mid+1,r,k);
    return mex(l,mid,k);
}
inline void dfs2(int k)
{
    if(son[k])
    {
        sg[son[k]]=sg[k]+1;
        dfs2(son[k]);
        p[k]=p[son[k]];
        for(int i=minn[son[k]]+1;i>minn[k];--i)
            if(!--cnt[p[k]][sg[k][i]])
            {
                val[p[k]].erase(sg[k][i]);
                cnt[p[k]].erase(sg[k][i]);
            }
    }
    else
    {
        p[k]=k;
        cnt[p[k]][0]=1;
        val[p[k]].insert(0);
    }
    for(int i:v[k])
    {
        if(i==son[k])
            continue;
        sg[i]=id;
        id+=len[i];
        dfs2(i);
        for(int j=1;j<=minn[k];++j)
        {
            if(!--cnt[p[k]][sg[k][j]])
            {
                val[p[k]].erase(sg[k][j]);
                cnt[p[k]].erase(sg[k][j]);
            }
            sg[k][j]^=sg[i][j-1];
            if(!cnt[p[k]][sg[k][j]]++)
                val[p[k]].insert(sg[k][j]);
        }
    }
    sg[k][0]=mex(0,n,p[k]);
    if(!cnt[p[k]][sg[k][0]]++)
        val[p[k]].insert(sg[k][0]);
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
        {
            fa[i]=read();
            if(fa[i])
                v[fa[i]].emplace_back(i);
        }
        for(int i=1;i<=n;++i)
            if(!fa[i])
            {
                dfs1(i);
                sg[i]=id;
                id+=len[i];
                dfs2(i);
                ans^=sg[i][0];
            }
        cout<<(ans? "YES":"NO")<<'\n';
        for(int i=0;i<=n;++i)
        {
            fa[i]=minn[i]=p[i]=len[i]=son[i]=0;
            sg[i]=NULL;
            v[i].clear();
            val[i].clear();
            cnt[i].clear();
        }
        for(int i=0;i<=n+n;++i)
            tmp[i]=0;
        id=tmp;
        ans=0;
    }
    return 0;
}
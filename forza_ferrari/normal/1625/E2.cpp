#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
using namespace std;
#define int long long
vector<int> v[300001];
int n,m,tot,s[300001],id[300001],dp[300001],fa[300001],rk[300001],dfn[300001],cnt;
string str;
stack<int> t;
struct bit
{
    int n;
    vector<int> sum;
    inline void init(int x)
    {
        n=x;
        sum.resize(x+1);
    }
    inline int lowbit(int x)
    {
        return x&-x;
    }
    inline void update(int x,int val)
    {
        for(;x<=n;x+=lowbit(x))
            sum[x]+=val;
    }
    inline int query(int x)
    {
        int res=0;
        for(;x;x-=lowbit(x))
            res+=sum[x];
        return res;
    }
}T[300001],V;
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
inline void dfs(int k,int f)
{
    fa[k]=f;
    dfn[k]=++cnt;
    s[k]=1;
    T[k].init(v[k].size());
    for(int i=1;i<=(int)v[k].size();++i)
        T[k].update(i,1);
    dp[k]=(int)v[k].size()*((int)v[k].size()+1)/2;
    int num=0;
    for(int i:v[k])
    {
        rk[i]=++num;
        dfs(i,k);
        s[k]+=s[i];
    }
    if(k)
        V.update(dfn[k],dp[k]);
}
signed main()
{
    n=read(),m=read();
    cin>>str;
    str=" "+str;
    for(int i=1;i<=n;++i)
        if(str[i]=='(')
            t.emplace(i);
        else if(!t.empty())
        {
            id[t.top()]=id[i]=++tot;
            t.pop();
        }
    while(!t.empty())
        t.pop();
    t.emplace(0);
    for(int i=1;i<=n;++i)
        if(id[i])
            if(str[i]=='(')
                t.emplace(i);
            else
            {
                t.pop();
                v[id[t.top()]].emplace_back(id[i]);
            }
    V.init(tot+1);
    dfs(0,0);
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==1)
        {
            int node=id[l],pos=rk[node],len=T[fa[node]].query(v[fa[node]].size());
            T[fa[node]].update(pos,-1);
            V.update(dfn[node],-dp[node]);
            V.update(dfn[fa[node]],-dp[fa[node]]);
            dp[fa[node]]-=len*(len+1)/2;
            dp[node]=0;
            --len;
            dp[fa[node]]+=len*(len+1)/2;
            V.update(dfn[fa[node]],dp[fa[node]]);
        }
        if(opt==2)
        {
            l=id[l],r=id[r];
            int node=fa[l],len=T[node].query(rk[r])-T[node].query(rk[l]-1);
            cout<<V.query(dfn[r]+s[r]-1)-V.query(dfn[l]-1)+len*(len+1)/2<<'\n';
        }
    }
    return 0;
}
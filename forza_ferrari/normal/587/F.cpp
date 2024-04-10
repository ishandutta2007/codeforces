#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int block=100;
int n,m,ch[100005][26],tot,fail[100005],dfn[100005],s[100005],cnt;
long long ans[100005],sum[100005],val[100005];
vector<int> v[100005];
struct element
{
    int pos,tag,id;
    element(int pos_,int tag_,int id_):
        pos(pos_),tag(tag_),id(id_){}
};
vector<element> q[100005],w[100005];
string str[100005];
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=tot;x+=lowbit(x))
        sum[x]+=val;
}
inline long long query(int x)
{
    long long res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
inline void insert(int x)
{
    int node=0;
    for(auto i:str[x])
    {
        if(!ch[node][i-'a'])
            ch[node][i-'a']=++tot;
        node=ch[node][i-'a'];
    }
}
inline void getfail()
{
    queue<int> q;
    for(int i=0;i<26;++i)
        if(ch[0][i])
            q.emplace(ch[0][i]);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<26;++i)
            if(ch[k][i])
            {
                fail[ch[k][i]]=ch[fail[k]][i];
                q.emplace(ch[k][i]);
            }
            else
                ch[k][i]=ch[fail[k]][i];
    }
}
inline void dfs(int k)
{
    dfn[k]=++cnt;
    s[k]=1;
    for(int i:v[k])
    {
        dfs(i);
        s[k]+=s[i];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>str[i];
        insert(i);
    }
    getfail();
    for(int i=1;i<=tot;++i)
        v[fail[i]].emplace_back(i);
    dfs(0);
    ++tot;
    for(int i=1;i<=m;++i)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if(str[k].length()>block)
        {
            w[k].emplace_back(l-1,-1,i);
            w[k].emplace_back(r,1,i);
        }
        else
        {
            q[l-1].emplace_back(k,-1,i);
            q[r].emplace_back(k,1,i);
        }
    }
    for(int i=1;i<=n;++i)
        if(str[i].length()>block)
        {
            for(int j=0;j<=n;++j)
                val[j]=0;
            for(int j=0;j<=tot;++j)
                sum[j]=0;
            int node=0;
            for(auto j:str[i])
            {
                node=ch[node][j-'a'];
                ++sum[dfn[node]];
            }
            for(int j=1;j<=tot;++j)
                sum[j]+=sum[j-1];
            for(int j=1;j<=n;++j)
            {
                node=0;
                for(auto k:str[j])
                    node=ch[node][k-'a'];
                val[j]=val[j-1]+sum[dfn[node]+s[node]-1]-sum[dfn[node]-1];
            }
            for(auto j:w[i])
                ans[j.id]+=j.tag*val[j.pos];
        }
    for(int i=1;i<=tot;++i)
        sum[i]=0;
    for(int i=1;i<=n;++i)
    {
        int node=0;
        for(auto j:str[i])
            node=ch[node][j-'a'];
        update(dfn[node],1);
        update(dfn[node]+s[node],-1);
        for(auto j:q[i])
        {
            node=0;
            for(auto k:str[j.pos])
            {
                node=ch[node][k-'a'];
                ans[j.id]+=j.tag*query(dfn[node]);
            }
        }
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}
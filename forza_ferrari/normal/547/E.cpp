#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[500001<<1];
struct element
{
    int pos,tag,id;
};
int n,m,tot,h[500001],cnt,ch[500001][26],fail[500001],sum[500001],ans[500001],dfn[500001],id,endpos[500001],s[500001];
vector<element> v[500001];
string str[500001];
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
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=cnt;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
inline void insert(int num)
{
    int node=0;
    for(int i=0;i<(int)str[num].length();++i)
    {
        if(!ch[node][str[num][i]-'a'])
            ch[node][str[num][i]-'a']=++cnt;
        node=ch[node][str[num][i]-'a'];
    }
    endpos[num]=node;
}
inline void getfail()
{
    queue<int> q;
    for(int i=0;i<26;++i)
        if(ch[0][i])
            q.push(ch[0][i]);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<26;++i)
            if(ch[k][i])
            {
                fail[ch[k][i]]=ch[fail[k]][i];
                q.push(ch[k][i]);
            }
            else
                ch[k][i]=ch[fail[k]][i];
    }
}
inline void dfs(int k)
{
    dfn[k]=++cnt;
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        dfs(e[i].to);
        s[k]+=s[e[i].to];
    }
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        cin>>str[i];
        insert(i);
    }
    getfail();
    for(int i=1;i<=cnt;++i)
        add(fail[i],i);
    dfs(0);
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read(),k=read();
        v[l-1].push_back({k,-1,i});
        v[r].push_back({k,1,i});
    }
    for(int i=1;i<=n;++i)
    {
        for(int node=0,j=0;j<(int)str[i].length();++j)
        {
            node=ch[node][str[i][j]-'a'];
            update(dfn[node],1);
        }
        for(auto j:v[i])
            ans[j.id]+=j.tag*(query(dfn[endpos[j.pos]]+s[endpos[j.pos]]-1)-query(dfn[endpos[j.pos]]-1));
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}
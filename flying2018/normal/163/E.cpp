#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define N 1000010
using namespace std;
int ch[N][26],fail[N],tot=1;
int rt=1;
int insert(char s[])
{
    int l=strlen(s+1);
    int u=rt;
    for(int i=1;i<=l;i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c]) ch[u][c]=++tot;
        u=ch[u][c];
    }
    return u;
}
vector<int>g[N];
queue<int>q;
void make_fail()
{
    int u=rt;
    for(int i=0;i<26;i++)
    if(ch[u][i]) fail[ch[u][i]]=u,q.push(ch[u][i]);
    else ch[u][i]=u;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(int i=0;i<26;i++)
        if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
        else ch[u][i]=ch[fail[u]][i];
    }
    for(int i=2;i<=tot;i++) g[fail[i]].push_back(i);
}
int id[N],siz[N],tid;
void dfs(int u)
{
    id[u]=++tid;siz[u]=1;
    for(int v:g[u]) dfs(v),siz[u]+=siz[v];
}
int sum[N];
void add(int u,int v){for(;u<=tot;u+=(u&(-u))) sum[u]+=v;}
int qry(int u){int v=0;for(;u;u-=(u&(-u))) v+=sum[u];return v;}
void upd(int l,int r,int v){add(l,v);add(r+1,-v);}
int find(char s[])
{
    int l=strlen(s+1),u=rt,ans=0;
    for(int i=1;i<=l;i++) u=ch[u][s[i]-'a'],ans+=qry(id[u]);
    return ans;
}
char s[N];
int pos[N];
bool in[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s+1);
        pos[i]=insert(s);
    }
    make_fail();
    dfs(1);
    for(int i=1;i<=m;i++) upd(id[pos[i]],id[pos[i]]+siz[pos[i]]-1,1),in[i]=true;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        if(s[0]=='?'){printf("%d\n",find(s));continue;}
        int a=0,l=strlen(s+1);
        for(int i=1;i<=l;i++) a=a*10+s[i]-'0';
        if(s[0]=='-' && in[a]) in[a]=false,upd(id[pos[a]],id[pos[a]]+siz[pos[a]]-1,-1);
        else if(s[0]=='+' && !in[a]) in[a]=true,upd(id[pos[a]],id[pos[a]]+siz[pos[a]]-1,1);
    }
    return 0;
}
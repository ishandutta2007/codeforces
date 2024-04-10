#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 200010
using namespace std;
int len[N],fa[N],ch[N][26],las=1,tot=1;
int insert(int c)
{
    int p=las,u=las=++tot;
    len[u]=len[p]+1;
    for(;p && !ch[p][c];p=fa[p]) ch[p][c]=u;
    if(!p) fa[u]=1;
    else
    {
        int np=ch[p][c];
        if(len[np]==len[p]+1) fa[u]=np;
        else
        {
            int nq=++tot;
            len[nq]=len[p]+1;
            memcpy(ch[nq],ch[np],sizeof(ch[np]));
            fa[nq]=fa[np];fa[np]=fa[u]=nq;
            for(;p && ch[p][c]==np;p=fa[p]) ch[p][c]=nq;
        }
    }
    return u;
}
char s[N],t[N];
int nxt[N<<1],to[N<<1],head[N],cnt;
int ed[N];
vector<int>pos;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
void dfs(int u)
{
    if(u==-1) return;
    if(ed[u]) pos.push_back(ed[u]);
    for(int i=head[u];i;i=nxt[i]) dfs(to[i]);
}
int find(char s[],int len)
{
    int u=1;
    for(int i=1;i<=len;i++)
    if(!ch[u][s[i]-'a']) return -1;
    else u=ch[u][s[i]-'a'];
    return u;
}
int main()
{
    int n,m;
    scanf("%s%d",s+1,&m);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        ed[insert(s[i]-'a')]=i;
    for(int i=2;i<=tot;i++) add(fa[i],i);
    for(int i=1;i<=m;i++)
    {
        int x,ans=100000000;
        scanf("%d%s",&x,t+1);
        int len=strlen(t+1);
        dfs(find(t,len));
        sort(pos.begin(),pos.end());
        for(int i=x-1;i<(int)pos.size();i++) ans=min(ans,pos[i]-pos[i-x+1]+len);
        pos.clear();
        printf("%d\n",ans>n?-1:ans);
    }
    return 0;
}
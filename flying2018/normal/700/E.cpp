#include<iostream>
#include<cstdio>
#include<cstring>
#define N 400010
using namespace std;
int len[N],pos[N],ch[N][26],fa[N],las=1,cnt=1;
int nxt[N<<1],to[N<<1],head[N],rcnt;
void add(int u,int v)
{
    nxt[++rcnt]=head[u];
    to[rcnt]=v;
    head[u]=rcnt;
}
int root[N],ls[N*40],rs[N*40],n,tcnt;
void insert(int &u,int l,int r,int p)
{
    if(!u) u=++tcnt;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p<=mid) insert(ls[u],l,mid,p);
    else insert(rs[u],mid+1,r,p);
}
void insert(int c,int id)
{
    int p=las,q=las=++cnt;
    pos[q]=id;
    insert(root[cnt],1,n,id);
    len[q]=len[p]+1;
    for(;p && !ch[p][c];p=fa[p]) ch[p][c]=q;
    if(!p) fa[q]=1;
    else
    {
        int np=ch[p][c];
        if(len[np]==len[p]+1) fa[q]=np;
        else
        {
            int nq=++cnt;
            memcpy(ch[nq],ch[np],sizeof(ch[nq]));
            len[nq]=len[p]+1;
            pos[nq]=pos[np];
            fa[nq]=fa[np];
            fa[np]=fa[q]=nq;
            for(;p && ch[p][c]==np;p=fa[p]) ch[p][c]=nq;
        }
    }
}
int merge(int x,int y)
{
    if(!x || !y) return x+y;
    int u=++tcnt;
    ls[u]=merge(ls[x],ls[y]);
    rs[u]=merge(rs[x],rs[y]);
    return u;
}
bool answer(int u,int l,int r,int L,int R)
{
    if(!u || L>R || l>R || L>r) return 0;
    if(L<=l && r<=R) return 1;
    int mid=(l+r)>>1;
    return answer(ls[u],l,mid,L,R)|answer(rs[u],mid+1,r,L,R);
}
int up[N],f[N],ans;
void meke(int u){for(int i=head[u];i;i=nxt[i]) meke(to[i]),root[u]=merge(root[u],root[to[i]]);}
void dfs(int u)
{
    if(u==1) f[u]=0;
    else if(fa[u]==1) f[u]=1,up[u]=u;
    else
    {
        int t=answer(root[up[fa[u]]],1,n,pos[u]-len[u]+len[up[fa[u]]],pos[u]-1);
        if(t) f[u]=f[fa[u]]+1,up[u]=u;
        else f[u]=f[fa[u]],up[u]=up[fa[u]];
    }
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        dfs(v);
    }
}
char str[N];
int main()
{
    scanf("%d%s",&n,str+1);
    for(int i=1;i<=n;i++) insert(str[i]-'a',i);
    for(int i=2;i<=cnt;i++) add(fa[i],i);
    meke(1);
    dfs(1);
    for(int i=2;i<=cnt;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
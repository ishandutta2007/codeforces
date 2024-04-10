#include<iostream>
#include<cstring>
#include<cstdio>
#define N 200010
int fa[N],ch[N][26],len[N],cnt=1,las=1;
int ls[N*40],rs[N*40],ntot,n;
int nxt[N<<1],to[N<<1],head[N],rcnt;
int root[N];
void insert(int &u,int l,int r,int p)
{
    if(!u) u=++ntot;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p<=mid) insert(ls[u],l,mid,p);
    else insert(rs[u],mid+1,r,p);
}
void insert(int c)
{
    int p=las,q=las=++cnt;
    len[q]=len[p]+1;
    insert(root[q],1,n,len[q]);
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
            fa[nq]=fa[np];
            fa[np]=fa[q]=nq;
            len[nq]=len[p]+1;
            for(;p && ch[p][c]==np;p=fa[p]) ch[p][c]=nq;
        }
    }
}
int answer(int u,int l,int r,int L,int R)
{
    if(!u || L>R || l>R || L>r) return false;
    if(L<=l && r<=R) return true;
    int mid=(l+r)>>1;
    return answer(ls[u],l,mid,L,R) || answer(rs[u],mid+1,r,L,R);
}
int merge(int x,int y)
{
    if(!x || !y) return x+y;
    int u=++ntot;
    ls[u]=merge(ls[x],ls[y]);
    rs[u]=merge(rs[x],rs[y]);
    return u;
}
void add(int u,int v)
{
    nxt[++rcnt]=head[u];
    to[rcnt]=v;
    head[u]=rcnt;
}
void dfs(int u)
{
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        dfs(v);
        root[u]=merge(root[u],root[v]);
    }
}
char s[N];
int zy[N];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++) insert(s[i]-'a');
    for(int i=2;i<=cnt;i++) add(fa[i],i);
    dfs(1);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        scanf("%s",s+1);
        int len=strlen(s+1),u=1,p;
        for(p=1;;p++)
        {
            zy[p]=-1;
            for(int c=p>len?0:s[p]-'a'+1;c<26;c++)
            {
                int v=ch[u][c];
                if(v && answer(root[v],1,n,l+p-1,r)){zy[p]=c;break;}
            }
            int v=p>len?0:ch[u][s[p]-'a'];
			if(!v || p==n+1 || !answer(root[v],1,n,l+p-1,r)) break;
			u=v;
        }
        for(;p && zy[p]==-1;p--);
		if(!p) {puts("-1");continue;}
		else
        {
			for(int j=1;j<p;j++) putchar(s[j]);
			putchar('a'+zy[p]);puts("");
		}
    }
    return 0;
}
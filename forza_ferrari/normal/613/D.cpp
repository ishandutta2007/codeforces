#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[1000001<<1],ee[1000001];
int n,m,tot,tott,h[1000001],hh[1000001],dep[1000001],f[1000001][21],stack[1000001],top,id[1000001],cnt,ans,node[1000001],s[1000001];
bool intree[100001];
inline bool cmp(int a,int b)
{
    return id[a]<id[b];
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void add2(int x,int y)
{
    ee[++tott].nxt=hh[x];
    hh[x]=tott;
    ee[tott].to=y;
}
void dfs(int k)
{
    id[k]=++cnt;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f[k][0])
            continue;
        dep[e[i].to]=dep[k]+1;
        f[e[i].to][0]=k;
        dfs(e[i].to);
    }
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(register int j=18;j>=0;--j)
        if(dep[f[x][j]]>=dep[y]&&f[x][j])
            x=f[x][j];
    if(x==y)
        return x;
    for(register int j=18;j>=0;--j)
        if(f[x][j]!=f[y][j]&&f[x][j])
        {
            x=f[x][j];
            y=f[y][j];
        }
    return f[x][0];
}
void dp(int k)
{
    for(register int i=hh[k];i;i=ee[i].nxt)
    {
        dp(ee[i].to);
        if(intree[k])
        {
            if(intree[ee[i].to]||s[ee[i].to])
            {
                s[ee[i].to]=0;
                ++ans;
            }
        }
        else
        {
            s[k]+=s[ee[i].to]+intree[ee[i].to];
            s[ee[i].to]=0;
        }
        intree[ee[i].to]=0;
    }
    if(!intree[k]&&s[k]>1)
    {
        ++ans;
        s[k]=0;
    }
    hh[k]=0;
}
signed main()
{
    scanf("%d",&n);
    for(register int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dep[1]=1;
    dfs(1);
    for(register int j=1;j<=18;++j)
        for(register int i=1;i<=n;++i)
            f[i][j]=f[f[i][j-1]][j-1];
    scanf("%d",&m);
    while(m--)
    {
        int p;
        scanf("%d",&p);
        for(register int i=1;i<=p;++i)
        {
            scanf("%d",&node[i]);
            intree[node[i]]=1;
        }
        sort(node+1,node+p+1,cmp);
        bool flag=1;
        for(register int i=1;i<=p;++i)  
            if(intree[f[node[i]][0]])
            {
                puts("-1");
                flag=0;
                break;
            }
        if(!flag)
        {
            for(register int i=1;i<=p;++i)
                intree[node[i]]=0;
            continue;
        }
        stack[top=1]=node[1];
        for(register int i=2;i<=p;++i)
        {
            int lca=LCA(node[i],stack[top]);
            while(top>1&&dep[lca]<=dep[stack[top-1]])
            {
                add2(stack[top-1],stack[top]);
                --top;
            }
            if(lca!=stack[top])
            {
                add2(lca,stack[top]);
                stack[top]=lca;
            }
            stack[++top]=node[i];
        }
        while(top>1)
        {
            add2(stack[top-1],stack[top]);
            --top;
        }
        dp(stack[1]);
        intree[stack[1]]=s[stack[1]]=0;
        printf("%d\n",ans);
        ans=tott=0;
    }
    return 0;
}
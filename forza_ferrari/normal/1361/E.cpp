#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstring>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to,flag;
}e[200001];
int root,t,n,m,tot,h[100001],cnt,id[100001],s[100001],p[100001];
bool tag[100001];
vector<int> g[100001];
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
void dfs1(int k)
{
    id[k]=++cnt;
    s[k]=1;
    for(register int i=h[k];i;i=e[i].nxt)
        if(!id[e[i].to])
        {
            e[i].flag=1;
            dfs1(e[i].to);
            s[k]+=s[e[i].to];
        }
}
bool dfs2(int k)
{
    for(register int i=h[k];i;i=e[i].nxt)
        if(e[i].flag)
        {
            if(!dfs2(e[i].to))
                return 0;
        }
        else
            if(!(id[k]>=id[e[i].to]&&id[k]<=id[e[i].to]+s[e[i].to]-1))
                return 0;
    return 1;
}
void dfs3(int k)
{
    for(register int i=h[k];i;i=e[i].nxt)
        if(e[i].flag)
        {
            dfs3(e[i].to);
            for(register int j=0;j<(int)(g[e[i].to].size());++j)
                if(g[e[i].to][j]^k)
                    g[k].push_back(g[e[i].to][j]);
        }
        else
            g[k].push_back(e[i].to);
    tag[k]=g[k].size()<2u;
}
void dfs4(int k)
{
    for(register int i=0;i<(int)g[k].size();++i)
        tag[k]&=tag[g[k][i]];
    for(register int i=h[k];i;i=e[i].nxt)
        if(e[i].flag)
            dfs4(e[i].to);
}
int main()
{
    srand(time(NULL));
    t=read();
    while(t--)
    {
        memset(e,0,sizeof e);
        memset(h,0,sizeof h);
        tot=0;
        memset(tag,0,sizeof tag);
        n=read(),m=read();
        for(register int i=1;i<=m;++i)
        {
            int x=read(),y=read();
            add(x,y);
        }
        bool flag=0;
        for(register int i=1;i<=n;++i)
            p[i]=i;
        random_shuffle(p+1,p+n+1);
        for(register int i=1;i<=min(n,100);++i)
        {
            cnt=0;
            memset(id,0,sizeof id);
            memset(s,0,sizeof s);
            for(register int j=1;j<=tot;++j)
                e[j].flag=0;
            root=p[i];
            dfs1(root);
            if(dfs2(root))
            {
                dfs3(root);
                dfs4(root);
                cnt=0;
                for(register int j=1;j<=n;++j)
                    cnt+=tag[j];
                if(cnt*5>=n)
                {
                    for(register int j=1;j<=n;++j)
                        if(tag[j])
                            printf("%d ",j);
                    puts("");
                }
                else
                    puts("-1");
                flag=1;
                for(register int j=1;j<=n;++j)
                    g[j].clear();
                break;
            }
        }
        if(!flag)
            puts("-1");
    }
    return 0;
}
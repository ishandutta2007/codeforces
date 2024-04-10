#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
int t,n,m,h[100001],tot,res,cnt,opt[100001][4],fst,lst,l,r;
vector<int> v[100001];
bool tag[100001],vis[100001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs1(int k,int f)
{
    int a=0,b=0;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        if(!tag[e[i].to])
        {
            if(!a)
                a=e[i].to;
            else
                if(!b)
                    b=e[i].to;
                else
                {
                    opt[++cnt][0]=k;
                    opt[cnt][1]=e[i].to;
                }
        }
        else
        {
            opt[++cnt][0]=k;
            opt[cnt][1]=e[i].to;
        }
    }
    if(a&&b)
    {
        tag[k]=1;
        v[k].push_back(a);
        v[a].push_back(k);
        v[k].push_back(b);
        v[b].push_back(k);
    }
    else
        if(a)
        {
            v[k].push_back(a);
            v[a].push_back(k);
        }
}
void dfs2(int k,int f)
{
    vis[k]=1;
    lst=k;
    for(register int i=0;i<(int)(v[k].size());++i)
    {
        if(v[k][i]==f)
            continue;
        dfs2(v[k][i],k);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tot=res=cnt=0;
        memset(e,0,sizeof e);
        memset(h,0,sizeof h);
        memset(tag,0,sizeof tag);
        memset(vis,0,sizeof vis);
        for(register int i=1;i<=n;++i)
            v[i].clear();
        for(register int i=1;i<n;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        dfs1(1,0);
        printf("%d\n",cnt);
        cnt=0;
        fst=lst=l=r=0;
        for(register int i=1;i<=n;++i)
            if(!vis[i]&&v[i].size()<=1)
            {
                fst=i;
                dfs2(i,0);
                if(!l)
                {
                    l=fst;
                    r=lst;
                }
                else
                {
                    opt[++cnt][2]=r;
                    opt[cnt][3]=fst;
                    r=lst;
                }
            }
        for(register int i=1;i<=cnt;++i)
            printf("%d %d %d %d\n",opt[i][0],opt[i][1],opt[i][2],opt[i][3]);
    }
    return 0;
}
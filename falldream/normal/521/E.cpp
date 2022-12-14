#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> q[MN+5];bool found,vis[MN+5],in[MN+5];
int dfn[MN+5],low[MN+5],head[MN+5],cnt=0,bel[MN+5],num=0,dn=0,n,m,top,Q[MN+5],C[MN+5],size,to,qq[MN+5],tp,vis2[MN+5];
struct edge{int to,next;}e[MN*2+5];
vector<int> V[MN+5];vector<pair<int,int> >E[MN+5];
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void Tarjan(int x,int fa)
{
    dfn[x]=low[x]=++dn;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            if(!dfn[e[i].to])
            {
                q[++top]=make_pair(x,e[i].to);
                Tarjan(e[i].to,x);low[x]=min(low[x],low[e[i].to]);
                if(low[e[i].to]>=dfn[x])
                {
                    ++num;
                    for(;q[top+1]!=make_pair(x,e[i].to);--top)
                    {
                        int x=q[top].first,y=q[top].second;
                        if(bel[x]!=num) V[num].push_back(x),bel[x]=num;
                        if(bel[y]!=num) V[num].push_back(y),bel[y]=num;
                        E[num].push_back(q[top]);
                    }
                    
                }
            }
            else
            {
                low[x]=min(low[x],dfn[e[i].to]);
                if(dfn[x]>dfn[e[i].to]) q[++top]=make_pair(x,e[i].to);
            }
        }
}

void dfs(int x,int fa)
{
    vis[x]=1;if(found) return;Q[++top]=x;
    for(int i=head[x];i&&!found;i=e[i].next)
        if(!vis[e[i].to]) dfs(e[i].to,x);
        else if(e[i].to!=fa)
        {
            found=1;
            for(Q[top+1]=0;Q[top+1]!=e[i].to;--top) C[++size]=Q[top];
        }
    if(!found) --top;
}

void dfs2(int x)
{
    if(to) return;qq[++tp]=x;vis2[x]=1;
    for(int i=head[x];i&&!to;i=e[i].next)
        if(!vis2[e[i].to])
        {
            if(in[e[i].to]) to=e[i].to;
            else dfs2(e[i].to);
        }
    if(!to) --tp;
}

bool Solve(const vector<int>&V,const vector<pair<int,int> >&E)
{
    cnt=top=found=size=to=tp=0;
    for(int i=0;i<E.size();++i) ins(E[i].first,E[i].second);
    for(int i=0;i<V.size();++i) if(!vis[V[i]]) dfs(V[i],0);
    C[0]=C[size];C[size+1]=C[1];
    for(int i=1;i<=size;++i) in[C[i]]=1;//printf("%d ",C[i]);puts("");
    for(int i=1;i<=size;++i)
        for(int j=head[C[i]];j;j=e[j].next)
            if(e[j].to!=C[i-1]&&e[j].to!=C[i+1])
            {
                if(in[e[j].to]) to=e[j].to;
                else vis2[C[i]]=1,dfs2(e[j].to);
                int id=0;
                for(int k=1;k<=size;++k) if(C[k]==to) id=k;
                puts("YES");
                printf("%d",id<i?(i-id+1):(size-id+i+1));
                for(int k=id;k!=i;k=k%size+1) printf(" %d",C[k]);
                printf(" %d\n",C[i]);
                printf("%d",id>i?(id-i+1):(id+size-i+1));
                for(int k=id;k!=i;k=(k+size-2)%size+1) printf(" %d",C[k]);
                printf(" %d\n",C[i]);
                printf("%d %d",tp+2,to);
                for(int k=tp;k;--k) printf(" %d",qq[k]);
                printf(" %d\n",C[i]);
                return true;
            }
    return false;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i) ins(read(),read());
    for(int i=1;i<=n;++i) if(!dfn[i]) Tarjan(i,0);
    memset(head,0,sizeof(head));
    for(int i=1;i<=num;++i) if(E[i].size()>1)
    {
        if(Solve(V[i],E[i])) return 0;
        for(int j=0;j<V[i].size();++j) head[V[i][j]]=vis[V[i][j]]=in[V[i][j]]=vis2[V[i][j]]=0;
    }
    puts("NO");
    return 0;
}
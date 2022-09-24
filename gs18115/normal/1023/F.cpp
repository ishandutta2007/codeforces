#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXV=5e5+10;
inline void swap(LL&A,LL&B)
{
    A=A^B;
    B=A^B;
    A=A^B;
    return;
}
struct EDGE
{
    LL s,e,w;
    bool operator<(EDGE X)
    {
        return w<X.w;
    }
}EG[MAXV],EG2[MAXV];
vector<EDGE>VV;
vector<LL>adj[MAXV];
LL V,E,E2,cnt;
LL i,j;
LL PA[MAXV],dep[MAXV];
LL par(const LL A)
{
    if(PA[A]==-1)
        return A;
    return PA[A]=par(PA[A]);
}
inline void uni(const LL&a,const LL&b)
{
    LL A=par(a);
    LL B=par(b);
    if(par(A)==par(B))
        return;
    if(dep[A]>dep[B])
        PA[B]=A;
    else if(dep[B]>dep[A])
        PA[A]=B;
    else
    {
        PA[B]=A;
        dep[A]++;
    }
    return;
}
LL spa[20][MAXV],dpt[MAXV],pa[MAXV];
bool vis[MAXV];
void dfs(const LL N)
{
    vis[N]=true;
    for(LL i=0;i<adj[N].size();i++)
    {
        if(!vis[adj[N][i]])
        {
            spa[0][adj[N][i]]=N;
            dpt[adj[N][i]]=dpt[N]+1;
            dfs(adj[N][i]);
        }
    }
    return;
}
inline void makesparse(LL&i,LL&j,const LL&V)
{
    for(i=1;i<19;i++)
        for(j=0;j<V;j++)
            spa[i][j]=spa[i-1][j]==-1?-1:spa[i-1][spa[i-1][j]];
    return;
}
inline LL LCA(LL A,LL B)
{
    if(dpt[A]<dpt[B])
        swap(A,B);
    LL i;
    const LL C=dpt[A]-dpt[B];
    for(i=19;i-->0;)
        if((C>>i)&1)
            A=spa[i][A];
    for(i=19;i-->0;)
    {
        if(spa[i][A]!=spa[i][B])
        {
            A=spa[i][A];
            B=spa[i][B];
        }
    }
    if(A!=B)
        return spa[0][A];
    return A;
}
LL WW[MAXV];
LL skp[MAXV];
inline void paint(const EDGE&X)
{
    LL S=X.s,E=X.e,W=X.w;
    LL SS,EE,t;
    LL L=LCA(S,E);
    while(dpt[S]>dpt[L])
    {
        if(WW[S]==INF)
            WW[S]=W;
        S=skp[S];
    }
    SS=S;
    S=X.s;
    while(dpt[S]>dpt[L])
    {
        t=skp[S];
        skp[S]=SS;
        S=t;
    }
    while(dpt[E]>dpt[L])
    {
        if(WW[E]==INF)
            WW[E]=W;
        E=skp[E];
    }
    EE=E;
    E=X.e;
    while(dpt[E]>dpt[L])
    {
        t=skp[E];
        skp[E]=EE;
        E=t;
    }
    return;
}
bool BOOL[MAXV];
LL SSS;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>V>>E>>E2;
    for(i=0;i<E;i++)
    {
        cin>>EG[i].s>>EG[i].e;
        EG[i].s--;
        EG[i].e--;
        EG[i].w=-1;
        adj[EG[i].s].push_back(EG[i].e);
        adj[EG[i].e].push_back(EG[i].s);
    }
    for(i=0;i<E2;i++)
    {
        cin>>EG2[i].s>>EG2[i].e>>EG2[i].w;
        EG2[i].s--;
        EG2[i].e--;
    }
    sort(EG2,EG2+E2);
    for(i=0;i<V;i++)
        PA[i]=-1;
    for(i=0;i<E;i++)
        uni(EG[i].s,EG[i].e);
    for(i=0;i<E2;i++)
    {
        if(par(EG2[i].s)!=par(EG2[i].e))
        {
            BOOL[i]=true;
            uni(EG2[i].s,EG2[i].e);
            adj[EG2[i].s].push_back(EG2[i].e);
            adj[EG2[i].e].push_back(EG2[i].s);
        }
    }
    spa[0][0]=-1;
    dpt[0]=0;
    dfs(0);
    makesparse(i,j,V);
    for(i=0;i<V;i++)
    {
        skp[i]=spa[0][i];
        WW[i]=INF;
    }
    for(i=0;i<E2;i++)
        if(!BOOL[i])
            paint(EG2[i]);
    for(i=0;i<E;i++)
    {
        if(spa[0][EG[i].s]==EG[i].e)
        {
            if(WW[EG[i].s]==INF)
                return cout<<-1<<endl,0;
            SSS+=WW[EG[i].s];
        }
        else
        {
            if(WW[EG[i].e]==INF)
                return cout<<-1<<endl,0;
            SSS+=WW[EG[i].e];
        }
    }
    cout<<SSS<<endl;
    return 0;
}
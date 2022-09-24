#include<iostream>
#include<vector>
#include<queue>
#include<time.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MAXV=1e5+10;
LL dis[45][MAXV];
bool qin[MAXV];
LL V,E;
vector<PL>adj[MAXV];
queue<LL>Q;
void SPFA(LL rt,LL num)
{
    fill(dis[num],dis[num]+V,INF);
    fill(qin,qin+V,false);
    Q.push(rt);
    dis[num][rt]=0;
    while(!Q.empty())
    {
        LL T=Q.front();
        Q.pop();
        qin[T]=false;
        for(LL i=0;i<adj[T].size();i++)
        {
            LL H=adj[T][i].first;
            LL W=adj[T][i].second;
            if(dis[num][H]>dis[num][T]+W)
            {
                dis[num][H]=dis[num][T]+W;
                if(!qin[H])
                {
                    Q.push(H);
                    qin[H]=true;
                }
            }
        }
    }
    return;
}
LL pa[MAXV],pd[MAXV];
LL dep[MAXV];
vector<LL>OV;
bool vis[MAXV];
void maketree(LL rt)
{
    vis[rt]=true;
    for(LL i=0;i<adj[rt].size();i++)
    {
        const PL&T=adj[rt][i];
        if(!vis[T.first])
        {
            pa[T.first]=rt;
            pd[T.first]=T.second;
            dep[T.first]=dep[rt]+1;
            maketree(T.first);
        }
        else if(T.first!=pa[rt])
            OV.push_back(rt);
    }
    return;
}
LL sp[MAXV][25],sd[MAXV][25];
inline void makesparse()
{
    LL i,j;
    for(i=0;i<V;i++)
        sp[i][0]=pa[i],sd[i][0]=pd[i];
    for(i=0;i<20;i++)
    {
        for(j=0;j<V;j++)
        {
            if(sp[j][i]==-1)
                sp[j][i+1]=-1;
            else
            {
                sp[j][i+1]=sp[sp[j][i]][i];
                sd[j][i+1]=sd[j][i]+sd[sp[j][i]][i];
            }
        }
    }
    return;
}
inline LL LCA(LL X,LL Y)
{
    LL i,sum=0;
    if(dep[X]>dep[Y])
    {
        LL p=dep[X]-dep[Y];
        for(i=0;i<20;i++)
        {
            if(p&1<<i)
            {
                sum+=sd[X][i];
                X=sp[X][i];
            }
        }
    }
    else if(dep[X]<dep[Y])
    {
        LL p=dep[Y]-dep[X];
        for(i=0;i<20;i++)
        {
            if(p&1<<i)
            {
                sum+=sd[Y][i];
                Y=sp[Y][i];
            }
        }
    }
    if(X==Y)
        return sum;
    for(i=20;i-->0;)
    {
        if(sp[X][i]!=sp[Y][i])
        {
            sum+=sd[X][i]+sd[Y][i];
            X=sp[X][i];
            Y=sp[Y][i];
        }
    }
    return sum+sd[X][0]+sd[Y][0];
}
LL i,s,e,w,u,v;
LL q,cnt;
LL mini;
bool CHK[MAXV];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>V>>E;
    for(i=0;i<E;i++)
    {
        cin>>s>>e>>w;
        adj[s-1].push_back({e-1,w});
        adj[e-1].push_back({s-1,w});
    }
    pa[0]=-1;
    maketree(0);
    for(i=0;i<OV.size();i++)
    {
        if(!CHK[OV[i]])
        {
            CHK[OV[i]]=true;
            SPFA(OV[i],cnt++);
        }
    }
    makesparse();
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        mini=LCA(--u,--v);
        for(i=0;i<cnt;i++)
            mini=min(mini,dis[i][u]+dis[i][v]);
        cout<<mini<<'\n';
    }
    cout<<endl;
    return 0;
}
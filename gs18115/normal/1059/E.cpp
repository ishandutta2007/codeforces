#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXN=1e5+10;
LL spap[20][MAXN],spaw[20][MAXN];
LL hei[MAXN];
LL LC(const LL X,const LL n,const LL w)
{
    LL N=0;
    LL sum=0;
    LL Y=X;
    for(LL i=18;i-->0;)
    {
        if(spap[i][Y]!=-1)
        {
            if(N+(1<<i)<=n&&sum+spaw[i][Y]<=w)
            {
                sum+=spaw[i][Y];
                N+=1<<i;
                Y=spap[i][Y];
            }
        }
    }
    return hei[X]-N;
}
bool vis[MAXN];
vector<LL>adj[MAXN];
LL L,S;
LL sum;
LL dfs(LL X)
{
    vis[X]=true;
    sum+=adj[X].size();
    LL maxi=INF;
    for(LL i=0;i<adj[X].size();i++)
    {
        LL&T=adj[X][i];
        if(vis[T])
            continue;
        LL t=dfs(T);
        maxi=min(maxi,t);
    }
    if(maxi>=hei[X])
        return LC(X,L,S);
    else
    {
        sum--;
        return maxi;
    }
}
void dfsh(LL X,LL H)
{
    vis[X]=true;
    hei[X]=H;
    for(LL i=0;i<adj[X].size();i++)
        if(!vis[adj[X][i]])
            dfsh(adj[X][i],H+1);
    return;
}
LL N;
LL i,j;
LL W[MAXN];
LL P[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>L>>S;
    for(i=0;i<N;i++)
    {
        cin>>W[i];
        if(W[i]>S)
            return cout<<-1<<endl,0;
    }
    P[0]=-1;
    for(i=1;i<N;i++)
    {
        cin>>P[i];
        adj[P[i]-1].push_back(i);
    }
    fill(vis,vis+N,false);
    dfsh(0,0);
    fill(vis,vis+N,false);
    for(i=0;i<N;i++)
    {
        spap[0][i]=P[i]-1;
        spaw[0][i]=W[i];
    }
    for(i=1;i<18;i++)
    {
        for(j=0;j<N;j++)
        {
            if(spap[i-1][j]!=-1)
            {
                spap[i][j]=spap[i-1][spap[i-1][j]];
                spaw[i][j]=spaw[i-1][j]+spaw[i-1][spap[i-1][j]];
            }
            else
                spap[i][j]=-1;
        }
    }
    dfs(0);
    cout<<sum+1<<endl;
    return 0;
}
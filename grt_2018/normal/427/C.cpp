#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define PB push_back

int n,nr,m;
const int MAXN = 100001;
const int INF = 1000*1000*1000;
const int MOD = 1000000007;
vector<int>V[MAXN];
vector<int>Vrev[MAXN];
int SCC[MAXN];
int order[MAXN];
int cost[MAXN];
int mini[MAXN];
int numberof[MAXN];
bool visited[MAXN];

void dfsOrder(int x)
{
    visited[x]=1;
    for(auto i:V[x])
        if(!visited[i])
            dfsOrder(i);
    order[nr--]=x;
}

void dfsSCC(int x,int id)
{
    visited[x]=1;
    SCC[x]=id;
    for(auto i:Vrev[x])
        if(!visited[i])
            dfsSCC(i,id);
}

int main()
{
    cin>>n; nr=n-1;
    FOR(i,1,n+1) cin>>cost[i];
    cin>>m;
    FOR(i,0,m)
    {
        int a,b; cin>>a>>b;
        V[a].PB(b); Vrev[b].PB(a);
    }
    FOR(i,1,n+1)
        if(!visited[i])
            dfsOrder(i);
    FOR(i,1,n+1)
        visited[i]=0;
    nr=1;
    FOR(i,0,n)
        if(!visited[order[i]])
            dfsSCC(order[i],nr++);
    FOR(i,1,n+1)
        mini[i]=INF;
    FOR(i,1,n+1)
        mini[SCC[i]] = min(mini[SCC[i]],cost[i]);
    FOR(i,1,n+1)
        if(mini[SCC[i]] == cost[i])
            numberof[SCC[i]]++;
    LL totalcost=0;
    LL result=1;
    FOR(i,1,nr)
    {
        totalcost+=mini[i];
        result=(result*numberof[i])%MOD;
    }
    cout<<totalcost<<" "<<result;
    return 0;
}
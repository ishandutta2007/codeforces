#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;
#define PB push_back
#define ST first
#define ND second
#define REP(x,n) for(int x=0; x<(n);x++)
#define FOR(x,b,e) for(int x=b; x<=(e);x++)
#define FORD(x,b,e) for(int x=b; x>=(e);x--)
#define SIZE(x) ((int)(x).size())

const int MAXN = 2*100000+10;
LL DP[MAXN],result,act;
int a[MAXN];
int d[MAXN];
bool visited[MAXN];
vector<int>V[MAXN];
int n;

void DfsDP(int x)
{
    visited[x]=1;
    REP(i,SIZE(V[x]))
        if(!visited[V[x][i]]) {
            d[V[x][i]]=d[x]+1;
            DfsDP(V[x][i]);
        }
    DP[x]=(LL)a[x-1];
    REP(i,SIZE(V[x]))
        if(d[V[x][i]]>d[x])
            DP[x]+=DP[V[x][i]];
}

void DfsLast(int x)
{
    visited[x]=1;
    result=max(result,act);
    //cout<<x<<" "<<act<<"\n";
    REP(i,SIZE(V[x]))
    {
        if(!visited[V[x][i]]) {
            act-=DP[V[x][i]];
            act+=DP[1]-DP[V[x][i]];
            DfsLast(V[x][i]);
        }
    }
    act+=DP[x];
    act-=(DP[1]-DP[x]);
}

int main()
{
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n-1)
    {
        int b,e;
        cin>>b>>e;
        V[b].PB(e); V[e].PB(b);
    }
    d[1]=0;
    DfsDP(1);
    FOR(i,1,n) act+=(LL)d[i]*a[i-1];
    REP(i,n+1) visited[i]=0;
    result=act;
    DfsLast(1);
    cout<<result;
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL

int n,m;
vector< pair<int,int> > Graph[100111];
int components=0;
bool TFO[100111];
int color[100111];
bool gonebad=false;

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1LL;

    Int P=FastPow(k,p/2);
    P=(P*P)%MOD;

    if (p%2==1)
    P=(P*k)%MOD;

    return P;
}

void DFS(int ver,int c)
{
    if (TFO[ver])
    {
        if (color[ver]!=c)
        gonebad=true;

        return;
    }

    TFO[ver]=true;
    color[ver]=c;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i].second==0)
        DFS(Graph[ver][i].first,c^1);
        else
        DFS(Graph[ver][i].first,c);
    }

    return;
}

int main()
{
    int i;
    int a,b,c;

    memset(color,-1,sizeof(color));

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);

        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));
    }

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            components++;

            DFS(i,0);
        }
    }

    if (gonebad)
    {
        printf("0\n");
    }
    else
    {
        printf("%lld\n",FastPow(2LL,components-1LL));
    }

    return 0;
}
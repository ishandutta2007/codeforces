#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
typedef long double Double;
typedef long long Int;

int n,q;
vector< pair<int,int> > Graph[110001];

pair<int,int> Edges[110001];
int Size[110001];
bool TFO[110001];
int W[110001];

map< pair<int,int> , int> mymap;
map< pair<int,int> , int>::iterator myit;

Double CurValue[110001];

int DFS(int ver,int dad)
{
    int i;
    int sz;
    int mysz=1;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i].first==dad)
        continue;

        sz=DFS(Graph[ver][i].first,ver);

        if (ver<Graph[ver][i].first)
        mymap.insert( make_pair( make_pair(ver,Graph[ver][i].first),sz ) );
        else
        mymap.insert( make_pair( make_pair(Graph[ver][i].first,ver),sz ) );

        mysz+=sz;
    }

    return mysz;
}

int main()
{
    int a,b,c;
    int i;
    Double PickChance;
    Int S1,S2;
    Double Sum;
    Double Total=0.0;
    int r,w;

    scanf("%d",&n);

    PickChance=( (Double)1.0 / (Double)( (Double)n*(Double)(n-1)*(Double)(n-2) ) )*(Double)6.0;

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d %d",&a,&b,&c);

        Edges[i]=make_pair(a,b);
        W[i]=c;

        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));
    }

    DFS(1,0);

    for (i=1;i<=n-1;i++)
    {
        if (Edges[i].first<Edges[i].second)
        {
            a=Edges[i].first;
            b=Edges[i].second;
        }
        else
        {
            a=Edges[i].second;
            b=Edges[i].first;
        }

        myit=mymap.find(make_pair(a,b));

        Size[i]=(*myit).second;
    }

    for (i=1;i<=n-1;i++)
    {
        S1=( (Int)Size[i]*(Int)(Size[i]-1)*(Int)(n-Size[i]) )/(Double)2.0;
        S2=( (Int)(n-Size[i])*(Int)(n-Size[i]-1)*(Int)Size[i] )/(Double)2.0;

        Sum=( (Double)S1*PickChance ) + ( (Double)S2*PickChance );

        Sum=Sum*(Double)2.0*(Double)W[i];

        CurValue[i]=Sum;
        Total+=Sum;
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&r,&w);

        Total-=CurValue[r];
        W[r]=w;

        S1=( (Int)Size[r]*(Int)(Size[r]-1)*(Int)(n-Size[r]) )/(Double)2.0;
        S2=( (Int)(n-Size[r])*(Int)(n-Size[r]-1)*(Int)Size[r] )/(Double)2.0;

        Sum=( (Double)S1*PickChance ) + ( (Double)S2*PickChance );

        Sum=Sum*(Double)2.0*(Double)W[r];

        CurValue[r]=Sum;
        Total+=Sum;

        printf("%.7f\n",(double)Total);
    }

    return 0;
}
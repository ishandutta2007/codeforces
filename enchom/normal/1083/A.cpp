#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

llong w[500111];
int n;
llong F[500111];
vector< pair<int,int> > Graph[500111];

llong bestAns = -1;

void tryAns(llong ans)
{
    if (ans > bestAns)
        bestAns = ans;
}

void DFS(int ver,int dad)
{
    int i;

    F[ver] = w[ver];

    llong maxFuel = -1, secondMaxFuel = -1;
    for (i=0;i<Graph[ver].size();i++)
    {
        int nver = Graph[ver][i].first;

        if (nver == dad)
            continue;

        DFS(nver, ver);

        llong fuelUp = F[nver] + w[ver] - Graph[ver][i].second;

        if (fuelUp > F[ver])
            F[ver] = fuelUp;

        llong fuelGain = F[nver] - Graph[ver][i].second;

        if (fuelGain > maxFuel)
        {
            secondMaxFuel = maxFuel;
            maxFuel = fuelGain;
        }
        else if (fuelGain > secondMaxFuel)
        {
            secondMaxFuel = fuelGain;
        }
    }

    if (secondMaxFuel != -1)
    {
        tryAns(w[ver] + secondMaxFuel + maxFuel);
    }
    else if (maxFuel != -1)
    {
        tryAns(w[ver] + maxFuel);
    }
    else
    {
        tryAns(w[ver]);
    }

    return;
}

int main()
{
    int i,j;
    int a,b,c;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }

    for (i=1;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);

        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));
    }

    DFS(1,0);

    printf("%lld\n",bestAns);

    return 0;
}
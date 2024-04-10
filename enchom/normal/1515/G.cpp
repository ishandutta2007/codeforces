#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long llong;

int n, m;
vector< pair<int, llong> > Graph[500111];
vector< pair<int, llong> > invGraph[500111];
int q;

bool TFO[500111];
vector<int> order;

llong gcd(llong a, llong b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    llong r;

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void DFS(int ver)
{
    if (TFO[ver])
        return;
    TFO[ver] = true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i].first);
    }

    order.push_back(ver);
}

int cId[500111];
int idCtr = 0;
vector<int> members[500111];

void mark(int ver)
{
    if (TFO[ver])
        return;
    TFO[ver] = true;

    cId[ver] = idCtr;
    members[idCtr].push_back(ver);

    //printf("Mark %d in component %d\n", ver, idCtr);

    int i;

    for (i=0;i<invGraph[ver].size();i++)
    {
        mark(invGraph[ver][i].first);
    }
}

void buildComponents()
{
    int i;

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
            DFS(i);
    }

    reverse(order.begin(), order.end());

    memset(TFO, false, sizeof(TFO));
    for (i=0;i<order.size();i++)
    {
        if (!TFO[ order[i] ])
        {
            idCtr++;
            mark(order[i]);
        }
    }

    return;
}

llong to[500111];
llong fro[500111];
llong mixed[500111];

llong compGcd[500111];

void traceDist(int ver, llong curDist, vector< pair<int, llong> > *G, llong *res)
{
    if (TFO[ver])
        return;
    TFO[ver] = true;

    res[ver] = curDist;

    int i;

    for (i=0;i<G[ver].size();i++)
    {
        int nv = G[ver][i].first;

        if (cId[ver] != cId[nv])
            continue;

        traceDist(nv, curDist + G[ver][i].second, G, res);
    }
}

void fillDistances(int leader, vector< pair<int, llong> > *G, llong *res, vector<int> &allMembers)
{
    int i;

    for (i=0;i<allMembers.size();i++)
    {
        TFO[ allMembers[i] ] = false;
    }

    traceDist(leader, 0, G, res);
}

int main()
{
    int i, j, in;

    scanf("%d %d", &n, &m);

    for (i=1;i<=m;i++)
    {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        Graph[a].push_back(make_pair(b, c));
        invGraph[b].push_back(make_pair(a, c));
    }

    buildComponents();

    for (i=1;i<=idCtr;i++)
    {
        fillDistances(members[i][0], Graph, to, members[i]);
        fillDistances(members[i][0], invGraph, fro, members[i]);

        for (j=0;j<members[i].size();j++)
        {
            int v = members[i][j];

            mixed[v] = to[v] + fro[v];
        }

        for (j=0;j<members[i].size();j++)
        {
            int v = members[i][j];

            compGcd[i] = gcd(compGcd[i], mixed[v]);

            for (in=0;in<Graph[v].size();in++)
            {
                int nv = Graph[v][in].first;

                if (cId[nv] != cId[v])
                    continue;

                llong newMix = to[v] + Graph[v][in].second + fro[nv];

                compGcd[i] = gcd(compGcd[i], newMix);
            }
        }

        //printf("Group %d has gcd %lld\n", i, compGcd[i]);
    }

    scanf("%d", &q);

    for (i=1;i<=q;i++)
    {
        int v, s, t;

        scanf("%d %d %d", &v, &s, &t);

        llong conflicting = gcd(t, compGcd[ cId[v] ]);

        if (s % conflicting != 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
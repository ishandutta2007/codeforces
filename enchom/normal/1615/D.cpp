#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int t;
int n, m;

vector< pair<int, int> > Graph[200111];
vector< pair<int, int> > affinity[200111];

int myValue[200111];
int father[200111];

int parity(int x)
{
    int cnt = 0;
    while(x > 0)
    {
        cnt += x % 2;
        x /= 2;
    }
    return cnt % 2;
}

void DFS(int ver, int dad)
{
    int i;

    father[ver] = dad;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i].first == dad)
            continue;

        myValue[ Graph[ver][i].first ] = Graph[ver][i].second;
        DFS(Graph[ver][i].first, ver);
    }
}

int F[200111];
vector<int> setBatch;

void clearBatch()
{
    int i;

    for (i=0;i<setBatch.size();i++)
    {
        F[ setBatch[i] ] = -1;
    }

    return;
}

bool trySet(int ver, int val)
{
    int i;

    setBatch.push_back(ver);
    F[ver] = val;

    for (i=0;i<affinity[ver].size();i++)
    {
        int nver = affinity[ver][i].first;
        int p = affinity[ver][i].second;

        if (F[nver] == -1)
        {
            if (!trySet(nver, val ^ p))
                return false;
        }
        else
        {
            if ( (val ^ p) != F[nver] )
                return false;
        }
    }

    return true;
}

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &m);

        for (i=1;i<=n;i++)
        {
            Graph[i].clear();
            affinity[i].clear();
            myValue[i] = -1;
            father[i] = 0;
            F[i] = -1;
        }

        for (i=1;i<n;i++)
        {
            int x, y, v;

            scanf("%d %d %d", &x, &y, &v);

            Graph[x].push_back(make_pair(y, v));
            Graph[y].push_back(make_pair(x, v));

            if (v != -1)
            {
                int p = parity(v);
                affinity[x].push_back(make_pair(y, p));
                affinity[y].push_back(make_pair(x, p));
            }
        }

        for (i=1;i<=m;i++)
        {
            int x, y, p;

            scanf("%d %d %d", &x, &y, &p);

            affinity[x].push_back(make_pair(y, p));
            affinity[y].push_back(make_pair(x, p));
        }

        DFS(1, 0);

        bool impossible = false;
        for (i=1;i<=n;i++)
        {
            if (F[i] == -1)
            {
                if (!trySet(i, 0))
                {
                    clearBatch();
                    if (!trySet(i, 1))
                    {
                        clearBatch();
                        impossible = true;
                        break;
                    }
                }
            }
        }

        if (impossible || F[1] == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");

            for (i=2;i<=n;i++)
            {
                if (myValue[i] == -1)
                {
                    if (F[i] == F[ father[i] ])
                        myValue[i] = 0;
                    else
                        myValue[i] = 1;
                }
            }

            for (i=2;i<=n;i++)
            {
                printf("%d %d %d\n", father[i], i, myValue[i]);
            }
        }
    }

    return 0;
}
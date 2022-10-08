#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
typedef long long llong;

int n, m;
llong x;

vector< pair<int, int> > Graph[500111];
int father[500111];
llong w[500111];
bool consumed[500111];

int Find(int ver)
{
    if (father[ver] == 0)
        return ver;
    else
    {
        father[ver] = Find(father[ver]);
        return father[ver];
    }
}

priority_queue< pair<llong, int> > pq;
vector<int> ans;

int main()
{
    int i, j;

    scanf("%d %d %lld", &n, &m, &x);

    for (i=1;i<=n;i++)
    {
        scanf("%lld", &w[i]);

        pq.push(make_pair(w[i], i));
    }

    for (i=1;i<=m;i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        int r1 = Find(a);
        int r2 = Find(b);

        if (r1 != r2)
        {
            father[r1] = r2;

            Graph[a].push_back(make_pair(b, i));
            Graph[b].push_back(make_pair(a, i));
        }
    }

    memset(father, 0, sizeof(father));

    for (i=1;i<n;i++)
    {
        pair<llong, int> top = pq.top();
        pq.pop();

        int v = top.second;

        if (consumed[v])
        {
            i--;
            continue;
        }

        if (w[v] != top.first)
        {
            i--;
            continue;
        }

        while(!Graph[v].empty())
        {
            int r = Find(Graph[v].back().first);

            if (r == v)
                Graph[v].pop_back();
            else
                break;
        }

        int nV = Find(Graph[v].back().first);
        ans.push_back(Graph[v].back().second);

        if (w[v] + w[nV] < x)
        {
            printf("NO\n");
            return 0;
        }

        if (Graph[v].size() < Graph[nV].size())
        {
            swap(v, nV);
        }

        father[nV] = v;
        consumed[nV] = true;

        for (j=0;j<Graph[nV].size();j++)
        {
            Graph[v].push_back(Graph[nV][j]);
        }

        w[v] = w[v] + w[nV] - x;

        pq.push(make_pair(w[v], v));
    }

    printf("YES\n");

    for (i=0;i<ans.size();i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
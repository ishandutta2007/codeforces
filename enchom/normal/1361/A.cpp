#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> Graph[500111];

set<int> blocked[500111];
int topic[500111];

pair<int,int> goal[500111];

int getTopic(int node)
{
    while(blocked[node].find(topic[node]) != blocked[node].end())
        topic[node]++;

    return topic[node];
}

void assignTopic(int node, int tpc)
{
    int i;

    for (i=0;i<Graph[node].size();i++)
    {
        int nb = Graph[node][i];

        blocked[nb].insert(tpc);
    }

    return;
}

int main()
{
    int i,j;

    scanf("%d %d", &n, &m);

    for (i=1;i<=m;i++)
    {
        int a,b;

        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=1;i<=n;i++)
    {
        topic[i] = 1;

        scanf("%d",&goal[i].first);
        goal[i].second = i;
    }

    sort(goal+1,goal+1+n);

    for (i=1;i<=n;i++)
    {
        int actualTopic = getTopic(goal[i].second);

        if (actualTopic != goal[i].first)
        {
            printf("-1\n");
            return 0;
        }

        assignTopic(goal[i].second, goal[i].first);
    }

    for (i=1;i<=n;i++)
    {
        printf("%d", goal[i].second);

        if (i != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}
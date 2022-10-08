#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> Graph[1011];
int n;

bool dead[1011];

pair<int,int> markLeaves()
{
    int i,j;

    vector<int> lvs;
    for (i=1;i<=n;i++)
    {
        if (dead[i])
            continue;

        if (Graph[i].size() == 1)
        {
            lvs.push_back(i);
        }

        if (lvs.size() >= 2)
            break;
    }

    if (lvs.size() < 2)
        return make_pair(-1, -1);
    else
        return make_pair(lvs[0], lvs[1]);
}

void murder(int ver,int dad)
{
    int i;

    dead[ver] = true;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;
        murder(Graph[ver][i], ver);
    }
}

bool findTarget(int ver,int dad,int target)
{
    if (ver == target)
        return true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        if (findTarget(Graph[ver][i], ver, target))
            return true;
    }

    return false;
}

void kill(int ver, int dad, int target)
{
    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        if (findTarget(Graph[ver][i], ver, target))
            murder(Graph[ver][i], ver);
    }
}

void cleanEdges()
{
    int i,j;

    for (i=1;i<=n;i++)
    {
        if (dead[i])
        {
            Graph[i].clear();
            continue;
        }

        j = 0;
        while(j < Graph[i].size())
        {
            if (dead[ Graph[i][j] ])
            {
                Graph[i][j] = Graph[i].back();
                Graph[i].pop_back();
            }
            else
                j++;
        }
    }
}

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n-1;i++)
    {
        int a,b;

        scanf("%d %d",&a,&b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    while(true)
    {
        pair<int,int> lvs = markLeaves();
        if (lvs.first == -1)
            break;

        printf("? %d %d\n",lvs.first,lvs.second);
        fflush(stdout);
        int lca;

        scanf("%d",&lca);

        kill(lca, 0, lvs.first);
        kill(lca, 0, lvs.second);

        cleanEdges();
    }

    for (i=1;i<=n;i++)
    {
        if (!dead[i])
        {
            printf("! %d\n",i);
            fflush(stdout);
            break;
        }
    }

    return 0;
}
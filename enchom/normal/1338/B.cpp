#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> Graph[200111];

bool freeVal[200111];
int depth[200111];

int ans = 0;

void DFS(int ver, int dad)
{
    int i;
    bool zeroTake = false;

    depth[ver] = depth[dad] + 1;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        freeVal[ver] = true;
        DFS(Graph[ver][i], ver);
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        if (freeVal[ Graph[ver][i] ])
            ans++;
        else if (!zeroTake)
        {
            ans++;
            zeroTake = true;
        }
    }
}

int getMin()
{
    int i;
    int cur = -1;
    bool ans1 = true;

    for (i=1;i<=n;i++)
    {
        if (!freeVal[i])
        {
            if (cur == -1)
                cur = depth[i] % 2;
            else if (cur != depth[i] % 2)
            {
                ans1 = false;
                break;
            }
        }
    }

    if (ans1)
        return 1;
    else
        return 3;
}

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<n;i++)
    {
        int a,b;

        scanf("%d %d",&a,&b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    int root;
    for (i=1;i<=n;i++)
    {
        if (Graph[i].size() > 1)
        {
            root = i;
            break;
        }
    }

    depth[0] = 0;
    DFS(root, 0);

    printf("%d %d\n",getMin(),ans);

    return 0;
}
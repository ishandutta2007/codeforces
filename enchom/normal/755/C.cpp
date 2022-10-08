#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> Graph[100111];
int n;
bool TFO[100111];

void DFS(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i]);
    }

    return;
}

int main()
{
    int i;
    int a;
    int ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);

        Graph[i].push_back(a);
        Graph[a].push_back(i);
    }

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            DFS(i);
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}
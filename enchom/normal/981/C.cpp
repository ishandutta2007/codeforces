#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> Graph[100111];

vector<int> leaves;

vector< pair<int,int> > paths;

int main()
{
    int i,j;
    int a,b;
    int ctr = 0;
    int root;

    scanf("%d",&n);

    for (i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=1;i<=n;i++)
    {
        if (Graph[i].size() > 2)
        {
            ctr++;
            root = i;
        }

        if (Graph[i].size() == 1)
        {
            leaves.push_back(i);
        }
    }

    if (ctr == 0)
    {
        root = 1;
    }
    else if (ctr > 1)
    {
        printf("No\n");
        return 0;
    }

    for (i=0;i<leaves.size();i++)
    {
        if (leaves[i] != root)
        {
            paths.push_back(make_pair(root,leaves[i]));
        }
    }

    printf("Yes\n%d\n",paths.size());

    for (i=0;i<paths.size();i++)
    {
        printf("%d %d\n",paths[i].first,paths[i].second);
    }

    return 0;
}
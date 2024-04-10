#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,s;
vector<int> Graph[100111];

int main()
{
    int i,j;

    scanf("%d %d",&n,&s);

    for (i=1;i<n;i++)
    {
        int a,b;

        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    int leaves = 0;

    for (i=1;i<=n;i++)
    {
        if (Graph[i].size() == 1)
            leaves++;
    }

    printf("%.8f\n",(double)(2*s) / (double)(leaves));

    return 0;
}
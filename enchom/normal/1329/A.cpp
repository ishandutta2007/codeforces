#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int ls[200111];
int ans[200111];

int main()
{
    int i,j;
    int ending;
    int sum = 0;

    scanf("%d %d",&n,&m);

    ending = n + 1;

    for (i=1;i<=m;i++)
    {
        scanf("%d",&ls[i]);
    }

    for (i=m;i>=1;i--)
    {
        int colBeg = min(ending-1, n - ls[i] + 1);

        ans[i] = colBeg;

        ending = colBeg;
    }

    if (ending <= 0)
    {
        printf("-1\n");
        return 0;
    }

    int goal = 1;
    for (i=1;i<=m;i++)
    {
        while(ans[i] > goal)
            ans[i]--;

        goal = max(goal, ans[i] + ls[i]);
    }

    if (goal <= n)
    {
        printf("-1\n");
        return 0;
    }

    for (i=1;i<=m;i++)
    {
        printf("%d",ans[i]);
        if (i != m)
            printf(" ");
    }
    printf("\n");

    return 0;
}
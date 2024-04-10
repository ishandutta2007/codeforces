#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, x;
int t;
int h[100111];
priority_queue< pair<int, int> > pq;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d %d", &n, &m, &x);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &h[i]);
        }

        while(!pq.empty())
            pq.pop();

        for (i=1;i<=m;i++)
        {
            pq.push(make_pair(0, i));
        }

        printf("YES\n");

        for (i=1;i<=n;i++)
        {
            pair<int, int> top = pq.top();
            pq.pop();

            printf("%d", top.second);

            if (i != n)
                printf(" ");

            top.first -= h[i];
            pq.push(top);
        }
        printf("\n");
    }

    return 0;
}
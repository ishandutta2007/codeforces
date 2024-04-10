#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int t;
int n;
int vals[200111];

set<int> seen;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &vals[i]);
        }

        int cost = n;
        seen.clear();
        seen.insert(0);
        int xorTally = 0;
        for (i=1;i<=n;i++)
        {
            xorTally ^= vals[i];
            auto it = seen.find(xorTally);

            if (it != seen.end())
            {
                seen.clear();
                seen.insert(0);
                cost--;
                xorTally = 0;
            }
            else
            {
                seen.insert(xorTally);
            }
        }

        printf("%d\n", cost);
    }

    return 0;
}
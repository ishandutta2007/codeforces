#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long llong;

struct pos
{
    int r, c;
};

int t;
int n;
pos crick[4];
pos goal;

int dst(pos A, pos B)
{
    return abs(A.r - B.r) + abs(A.c - B.c);
}

pos rott90(pos X)
{
    pos Y;

    Y.r = X.c;
    Y.c = n - X.r + 1;

    return Y;
}

void rot90()
{
    for (int i = 1; i <= 3; i++)
    {
        crick[i] = rott90(crick[i]);
    }
    goal = rott90(goal);
}

bool has(int x, int y)
{
    for (int i = 1; i <= 3; i++)
    {
        if (crick[i].r == x && crick[i].c == y)
            return true;
    }

    return false;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);
        scanf("%d %d %d %d %d %d", &crick[1].r, &crick[1].c, &crick[2].r, &crick[2].c, &crick[3].r, &crick[3].c);
        scanf("%d %d", &goal.r, &goal.c);

        bool fitParity = false;
        for (i=1;i<=3;i++)
        {
            if (crick[i].r % 2 == goal.r % 2 && crick[i].c % 2 == goal.c % 2)
                fitParity = true;
        }

        if (!fitParity)
        {
            printf("NO\n");
            continue;
        }

        bool bad = false;
        for (i=1;i<=4;i++)
        {
            rot90();

            if (has(1,1) && has(1,2) && has(2,1))
            {
                if (goal.r != 1 && goal.c != 1)
                {
                    bad = true;
                    break;
                }
            }
        }

        if (bad)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }

    return 0;
}
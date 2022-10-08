#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;

int n, m, t;
char grid[1111][1111];
char ng[1111][1111];

bool OK(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;

    return true;
}

int sameNbs(int x, int y)
{
    int i,j;
    int ans = 0;

    for (i=x-1;i<=x+1;i++)
    {
        for (j=y-1;j<=y+1;j++)
        {
            if (OK(i, j) && abs(x-i) + abs(y-j) == 1)
            {
                if (grid[x][y] == grid[i][j])
                    ans++;
            }
        }
    }

    return ans;
}

bool TFO[1011][1011];
int flipper[1011][1011];
pair<int,int> q[1100111];
int qL;

void propagateFlippers()
{
    int uk = 1;
    int i,j;

    qL = 0;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (sameNbs(i, j) > 0)
            {
                qL++;
                q[qL] = make_pair(i, j);
                flipper[i][j] = 0;
                TFO[i][j] = true;
            }
        }
    }

    while(uk <= qL)
    {
        int x = q[uk].first, y = q[uk].second;

        for (i=x-1;i<=x+1;i++)
        {
            for (j=y-1;j<=y+1;j++)
            {
                if (OK(i, j) && abs(x-i) + abs(y-j) == 1 && !TFO[i][j])
                {
                    flipper[i][j] = flipper[x][y] + 1;
                    TFO[i][j] = true;
                    qL++;
                    q[qL] = make_pair(i, j);
                }
            }
        }

        uk++;
    }
}

inline char flip(char ch)
{
    if (ch == '0')
        return '1';
    else
        return '0';
}

int main()
{
    memset(flipper, -1, sizeof(flipper));
    int i,j;

    scanf("%d %d %d",&n,&m,&t);

    for (i=1;i<=n;i++)
    {
        scanf("%s", grid[i]+1);
    }

    propagateFlippers();

    /*for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            printf("%d ",flipper[i][j]);
        }
        printf("\n");
    }*/

    for (i=1;i<=t;i++)
    {
        int x, y;
        llong p;

        scanf("%d %d %lld", &x, &y, &p);

        if (flipper[x][y] == -1 || p <= flipper[x][y])
        {
            printf("%c\n", grid[x][y]);
        }
        else
        {
            llong flips = p - flipper[x][y];

            if (flips % 2 == 0)
                printf("%c\n", grid[x][y]);
            else
                printf("%c\n", flip(grid[x][y]));
        }
    }


    return 0;
}
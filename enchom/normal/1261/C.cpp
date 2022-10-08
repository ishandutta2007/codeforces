#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;
vector<char> grid[1000111];
char inp[1000111];

vector<int> gridSums[1000111];

vector<int> savedFire[1000111];
vector<int> fire[1000111];

vector<int> fireSums[1000111];

void saveFire()
{
    int i,j;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            savedFire[i][j] = fire[i][j];
        }
    }
}

int getGridSum(int x1, int y1, int x2, int y2)
{
    x1 = max(1, x1);
    y1 = max(1, y1);
    x2 = min(n, x2);
    y2 = min(m, y2);

    if (x2 < x1 || y2 < y1)
        return 0;

    return gridSums[x2][y2] - gridSums[x2][y1-1] - gridSums[x1-1][y2] + gridSums[x1-1][y1-1];
}

int getFireSum(int x1,int y1,int x2,int y2)
{
    x1 = max(1, x1);
    y1 = max(1, y1);
    x2 = min(n, x2);
    y2 = min(m, y2);

    if (x2 < x1 || y2 < y1)
        return 0;

    return fireSums[x2][y2] - fireSums[x2][y1-1] - fireSums[x1-1][y2] + fireSums[x1-1][y1-1];
}

int getArea(int x1,int y1,int x2,int y2)
{
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

bool possibleFire(int r)
{
    int i,j;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            int gsum = getGridSum(i-r, j-r, i+r, j+r);

            if (gsum == getArea(i-r, j-r, i+r, j+r))
                fire[i][j] = 1;
            else
                fire[i][j] = 0;

            fireSums[i][j] = fireSums[i-1][j] + fireSums[i][j-1] - fireSums[i-1][j-1] + fire[i][j];
        }
    }

    for (i=0;i<=n+1;i++)
    {
        for (j=0;j<=m+1;j++)
        {
            int fsum = getFireSum(i-r, j-r, i+r, j+r);

            if (i < 1 || i > n || j < 1 || j > m)
            {
                if (fsum > 0)
                    return false;

                continue;
            }

            if (grid[i][j] == '.' && fsum > 0)
                return false;

            if (grid[i][j] == 'X' && fsum == 0)
                return false;
        }
    }

    return true;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    gridSums[0].resize(m+1, 0);
    fire[0].resize(m+1, 0);
    fireSums[0].resize(m+1, 0);
    savedFire[0].resize(m+1, 0);

    for (i=1;i<=n;i++)
    {
        scanf("%s",inp+1);

        grid[i].resize(m+1);
        gridSums[i].resize(m+1, 0);
        fire[i].resize(m+1, 0);
        fireSums[i].resize(m+1, 0);
        savedFire[i].resize(m+1, 0);

        for (j=1;j<=m;j++)
        {
            grid[i][j] = inp[j];

            gridSums[i][j] = gridSums[i-1][j] + gridSums[i][j-1] - gridSums[i-1][j-1];
            if (inp[j] == 'X')
                gridSums[i][j]++;
        }
    }

    int l = 0, r = n, mid, best = 0;

    while(l <= r)
    {
        mid = (l + r) / 2;

        if (possibleFire(mid))
        {
            saveFire();
            best = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    printf("%d\n",best);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (savedFire[i][j] == 1)
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}
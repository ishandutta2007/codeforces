#include <cstdio>
#define DOWN 0
#define RIGHT 1

int n;
long long a[1001][1001], b[1001][1001], c[1001][1001], d2[1001][1001], p2[1001][1001], d5[1001][1001], p5[1001][1001];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void repair2(int i, int j)
{
    if (i + j == 0) return;
    if (p2[i][j] == RIGHT)
    {
        repair2(i, j - 1);
        printf("R");
    }
    else
    {
        repair2(i - 1, j);
        printf("D");
    }
}

void repair5(int i, int j)
{
    if (i + j == 0) return;
    if (p5[i][j] == RIGHT)
    {
        repair5(i, j - 1);
        printf("R");
    }
    else
    {
        repair5(i - 1, j);
        printf("D");
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int nx = -1, ny = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                b[i][j] = 123456789;
                c[i][j] = 123456789;
                nx = i;
                ny = j;
                continue;
            }
            int q;
            q = a[i][j];
            b[i][j] = 0;
            while (q % 2 == 0) q /= 2, b[i][j]++;
            q = a[i][j];
            c[i][j] = 0;
            while (q % 5 == 0) q /= 5, c[i][j]++;
        }

    d2[0][0] = b[0][0];
    for (int i = 1; i < n; i++)
    {
        d2[0][i] = b[0][i] + d2[0][i - 1];
        p2[0][i] = RIGHT;
        d2[i][0] = b[i][0] + d2[i - 1][0];
        p2[i][0] = DOWN;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (d2[i][j - 1] < d2[i - 1][j])
            {
                d2[i][j] = b[i][j] + d2[i][j - 1];
                p2[i][j] = RIGHT;
            }
            else
            {
                d2[i][j] = b[i][j] + d2[i - 1][j];
                p2[i][j] = DOWN;
            }

    d5[0][0] = c[0][0];
    for (int i = 1; i < n; i++)
    {
        d5[0][i] = c[0][i] + d5[0][i - 1];
        p5[0][i] = RIGHT;
        d5[i][0] = c[i][0] + d5[i - 1][0];
        p5[i][0] = DOWN;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (d5[i][j - 1] < d5[i - 1][j])
            {
                d5[i][j] = c[i][j] + d5[i][j - 1];
                p5[i][j] = RIGHT;
            }
            else
            {
                d5[i][j] = c[i][j] + d5[i - 1][j];
                p5[i][j] = DOWN;
            }

    if (nx + ny > 0 && d5[n - 1][n - 1] != 0)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                d5[i][j] = 1;
                if (i == 0) p5[i][j] = RIGHT;
                else if (j == 0) p5[i][j] = DOWN;
                else if (i == nx) p5[i][j] = RIGHT;
                else p5[i][j] = DOWN;
            }
    }

    printf("%d\n", min(d2[n - 1][n - 1], d5[n - 1][n - 1]));

    if (d2[n - 1][n - 1] < d5[n - 1][n - 1])
        repair2(n - 1, n - 1);
    else
        repair5(n - 1, n - 1);

}
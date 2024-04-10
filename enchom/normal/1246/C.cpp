#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

const int MOD = 1000000007;

int n,m;
char grid[2011][2011];
int rowRocks[2011][2011];
int colRocks[2011][2011];

int paint[2][2011][2011];

llong ANSWER = 0;

int normalized(int num)
{
    if (num >= MOD)
        num -= MOD;
    if (num < 0)
        num += MOD;

    return num;
}

int getVal(int dim, int t, int ind, bool push=true)
{
    if (push)
    {
        paint[dim][t][ind+1] += paint[dim][t][ind];
        paint[dim][t][ind+1] = normalized(paint[dim][t][ind+1]);
    }
    return paint[dim][t][ind];
}

void addVal(int dim, int t, int L, int R, int v)
{
    paint[dim][t][L] += v;
    paint[dim][t][R+1] -= v;

    paint[dim][t][L] = normalized(paint[dim][t][L]);
    paint[dim][t][R+1] = normalized(paint[dim][t][R+1]);

    return;
}

inline bool possible(int dir, int x, int y)
{
    if (dir == 0)
    {
        return rowRocks[x][m] - rowRocks[x][y-1] < m - y + 1;
    }
    else
    {
        return colRocks[y][n] - colRocks[y][x-1] < n - x + 1;
    }
}

void run(int x,int y)
{
    ///Left entry
    int v = getVal(0, y, x);
    //cout<<"->"<<x<<";"<<y<<" is "<<v<<endl;
    int rocks = colRocks[y][n] - colRocks[y][x];

    if (possible(0, x, y))
    {
         //Move down
        if (n - rocks > x && y != m)
        {
            addVal(0, y+1, x+1, n-rocks, v);
        }
        //Move right
        rocks = rowRocks[x][m] - rowRocks[x][y-1];
        if (m - rocks > y && x != n)
        {
            addVal(1, x+1, y+1, m-rocks, v);
        }
    }


    ///Top entry
    v = getVal(1, x, y);

    //cout<<"V "<<x<<";"<<y<<" is "<<v<<endl;
    rocks = colRocks[y][n] - colRocks[y][x-1];

    if (possible(1, x, y))
    {
        //Move down
        if (n - rocks > x && y != m)
        {
            addVal(0, y+1, x+1, n-rocks, v);
        }
        //Move right
        rocks = rowRocks[x][m] - rowRocks[x][y];
        if (m - rocks > y && x != n)
        {
            addVal(1, x+1, y+1, m-rocks, v);
        }
    }
}

int compute(int x, int y)
{
    int ans = 0;
    if (possible(0, x, y))
        ans += getVal(0, y, x, false);
    if (possible(1, x, y))
        ans += getVal(1, x, y, false);

    if (ans >= MOD)
        ans -= MOD;

    return ans;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);

        for (j=1;j<=m;j++)
        {
            rowRocks[i][j] = rowRocks[i][j-1];
            if (grid[i][j] == 'R')
                rowRocks[i][j]++;
        }
    }

    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            colRocks[i][j] = colRocks[i][j-1];
            if (grid[j][i] == 'R')
                colRocks[i][j]++;
        }
    }

    addVal(0, 1, 1, 1, 1);
    for (i=1;i<=m;i++)
    {
        int x,y;

        x = 1;
        y = i;
        while(x <= n && y >= 1)
        {
            run(x, y);
            x++;
            y--;
        }
    }

    for (i=2;i<=n;i++)
    {
        int x,y;

        x = i;
        y = m;
        while(x <= n && y >= 1)
        {
            run(x, y);
            x++;
            y--;
        }
    }

    int ans = 0;

    for (i=m;i>=1;i--)
    {
        if (grid[n][i] == 'R')
            break;

        ans += compute(n, i);

        if (ans >= MOD)
            ans -= MOD;
    }

    for (i=n;i>=1;i--)
    {
        if (grid[i][m] == 'R')
            break;

        if (i != n)
            ans += compute(i, m);

        if (ans >= MOD)
            ans -= MOD;
    }

    printf("%d\n",ans);

    return 0;
}
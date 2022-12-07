#include <cstdio>

using namespace std;

const int yy[] = {1, 0, -1, 0};
const int xx[] = {0, -1, 0, 1};
const int inf = (int)1e9;
int n, m, a[501][501] = {{0}}, ax[501][501] = {{0}}, ay[501][501] = {{0}};

void precalc(void)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        ax[i][0] = a[i][0];
        for (j = 1; j < m; ++j)
            ax[i][j] = ax[i][j - 1] + a[i][j];
    }
    for (i = 0; i < m; ++i)
    {
        ay[0][i] = a[0][i];
        for (j = 1; j < n; ++j)
            ay[j][i] = ay[j - 1][i] + a[j][i];
    }
}

int mod(int z)
{
    if (z < 0)
        return 500;
    return z;
}

int go(int x, int y, bool inv)
{
    bool b = true;
    int mx = -inf;
    int k, res = a[x][y], nx, ny, t, tres;
    if (inv)
        k = 2;
    else
        k = 0;
    //((x >= 0) && (x < n) && (y >= 0) && (y < m))
    t = 2;
    while (b)
    {
        nx = x + t * (xx[k] + xx[(k + 1) % 4]);
        ny = y + t * (yy[k] + yy[(k + 1) % 4]);
        if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
        {
            if (xx[k] == 0)
            {
                if (yy[k] == 1)
                    res += ax[x][ny] - ax[x][y];
                else
                    res += ax[x][mod(y - 1)] - ax[x][mod(ny - 1)];
                if (xx[(k + 1) % 4] == 1)
                    res += ay[nx][ny] - ay[x][ny];
                else
                    res += ay[mod(x - 1)][ny] - ay[mod(nx - 1)][ny];
            }
            else
            {
                if (xx[k] == 1)
                    res += ay[nx][n] - ay[x][y];
                else
                    res += ay[mod(x - 1)][y] - ay[mod(nx - 1)][n];
                if (yy[(k + 1) % 4] == 1)
                    res += ax[nx][ny] - ax[nx][y];
                else
                    res += ax[nx][mod(y - 1)] - ax[nx][mod(ny - 1)];
            }
            x = nx;
            y = ny;
            k = (k + 2) % 4;
        }
        else
        {
            b = false;
            t -= 2;
        }
        if ((t > 0) && ((!inv && (t % 4 == 2)) || (inv && (t % 4 == 0))))
        {
            tres = res;
            if (xx[k] == 0)
            {
                ny = y + t * yy[k];
                if (yy[k] == 1)
                    tres += ax[x][ny] - ax[x][y];
                else
                    tres += ax[x][mod(y - 1)] - ax[x][mod(ny - 1)];
            }
            else
            {
                nx = x + t * xx[k];
                if (xx[k] == 1)
                    tres += ay[nx][n] - ay[x][y];
                else
                    tres += ay[mod( x  - 1)][y] - ay[mod(nx - 1)][n];
            }
            if (tres > mx)
                mx = tres;
        }
        t += 2;
    }
    return mx;
}

int main(void)
{
    int i, j, mx = -inf, cur;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            scanf("%d", a[i] + j);
    precalc();
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
        {
            if ((cur = go(i, j, false)) > mx)
                mx = cur;
            if ((cur = go(i, j, true)) > mx)
                mx = cur;
        }
    printf("%d", mx);
    return 0;
}
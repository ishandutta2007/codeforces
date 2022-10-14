// Codeforces Beta Round #11
// Problem C -- How Many Squares?
#include <cstdio>
#include <cstring>

#define maxN 250

using namespace std;

int t, n, m, cnt, xmin, xmax, ymin, ymax, head, tail, 
g[maxN + 2][maxN + 2], f[maxN + 2][maxN + 2], qx[maxN * maxN], qy[maxN * maxN];

bool checkType1()
{
    if(tail != 4 * (xmax - xmin))
        return false;
    for(int i = xmin; i <= xmax; ++ i)
    {
        if(f[i][ymin] != cnt)return false;
        if(f[i][ymax] != cnt)return false;
    }
    for(int j = ymin; j <= ymax; ++ j)
    {
        if(f[xmin][j] != cnt)return false;
        if(f[xmax][j] != cnt)return false;
    }
    return true;
}

bool checkType2()
{
    if((xmin + xmax) % 2 || (ymin + ymax) % 2)
        return false;
    int xmid = (xmax + xmin) / 2,
        ymid = (ymax + ymin) / 2,
        rang = (xmax - xmin) / 2;
    if(tail != 4 * rang)
        return false;
    for(int x = 0; x <= rang; ++ x)
    {
        int y = rang - x;
        if(f[xmid - x][ymid - y] != cnt)return false;
        if(f[xmid - x][ymid + y] != cnt)return false;
        if(f[xmid + x][ymid - y] != cnt)return false;
        if(f[xmid + x][ymid + y] != cnt)return false;
    }
    return true;
}

int main()
{
    for(scanf("%d", &t); t; -- t)
    {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; ++ i)
        {
            char b[maxN];
            scanf("%s", b);
            for(int j = 1; j <= m; ++ j)
                g[i][j] = b[j - 1] - '0';
        }
        int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1},
            dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1},
            ans = cnt = 0;
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j)
                if(g[i][j] && !f[i][j])
                {
                    f[i][j] = ++ cnt;
                    head = tail = 0;
                    xmin = xmax = i;
                    ymin = ymax = j;
                    qx[tail] = i;
                    qy[tail] = j;
                    tail ++;
                    while(head != tail)
                    {
                        for(int k = 0; k != 8; ++ k)
                        {
                            int xx = qx[head] + dx[k],
                                yy = qy[head] + dy[k];
                            if(g[xx][yy] && !f[xx][yy])
                            {
                                f[xx][yy] = cnt;
                                if(xx < xmin)xmin = xx;
                                if(xx > xmax)xmax = xx;
                                if(yy < ymin)ymin = yy;
                                if(yy > ymax)ymax = yy;
                                qx[tail] = xx;
                                qy[tail] = yy;
                                tail ++;
                            }
                        }
                        head ++;
                    }
                    if(tail <= 1 || xmax - xmin != ymax - ymin)
                        continue;
                    if(checkType1() || checkType2())
                        ans ++;
                        
                }
        printf("%d\n", ans);
    }
    return 0;
}
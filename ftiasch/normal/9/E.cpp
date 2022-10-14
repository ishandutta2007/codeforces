// Codeforces Beta Round #9
// Problem E -- Interesting Graph and Apples
#include <cstdio>
#include <cstring>

#define maxN 51

using namespace std;

int n, m, d[maxN], g[maxN][maxN];
bool v[maxN], cir;

void dfs(int i)
{
    if(v[i])
    {
        cir = true;
        return;
    }
    v[i] = true;
    for(int j = 1; j <= n; ++ j)
        if(g[i][j])
        {
            g[i][j] --, g[j][i] --;
            dfs(j);
            g[i][j] ++, g[j][i] ++;
            
        }
}

bool check()
{
    bool deg = true;
    for(int i = 1; i <= n; ++ i)
        deg &= (d[i] == 2);
    if(deg)
    {
        memset(v, 0, sizeof(v));
        dfs(1);
        bool con = true;
        for(int i = 1; i <= n; ++ i)
            con &= v[i];
        if(con)
            return true;
    }
    for(int i = 1; i <= n; ++ i)
        if(d[i] > 2)
            return false;
    cir = false;
    for(int i = 1; i <= n; ++ i)
    {
        memset(v, 0, sizeof(v));
        dfs(i);
    }
    if(cir)
        return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(d, 0, sizeof(d));
    memset(g, 0, sizeof(g));
    for(int i = 0; i != m; ++ i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        d[x] ++, d[y] ++, g[x][y] ++, g[y][x] ++;
    }
    if(!check())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n%d\n", n - m);
    for(; m < n; ++ m)
    {   
        bool flag = true;
        for(int i = 1; i <= n && flag; ++ i)
            for(int j = i; j <= n && flag; ++ j)
            {
                d[i] ++, d[j] ++, g[i][j] ++, g[j][i] ++;
                if(check())
                {
                    printf("%d %d\n", i, j);
                    flag = false;
                    break;
                }
                d[i] --, d[j] --, g[i][j] --, g[j][i] --;
            }
    }
    return 0;
}
// Codeforces Beta Round #6
// Problem B -- President's Office
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char c, g[102][102];
bool v[256];

int main()
{
    char t[101];
    scanf("%d%d%s", &n, &m, t);
    c = t[0];
    for(int i = 0; i <= n + 1; ++ i)
        for(int j = 0; j <= m + 1; ++ j)
            g[i][j] = '.';
    for(int i = 1; i <= n; ++ i)
    {
        scanf("%s", t);
        for(int j = 1; j <= m; ++ j)
            g[i][j] = t[j - 1];
    }
    memset(v, 0, sizeof(v));
    int dx[4] = {00, 00, +1, -1}, 
        dy[4] = {+1, -1, 00, 00};
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(g[i][j] == c)
                for(int k = 0; k < 4; ++ k)
                    v[g[i + dx[k]][j + dy[k]]] = true;
    v['.'] = v[c] = false;
    int s = 0;
    for(int i = 0; i < 256; ++ i)
        s += v[i];
    printf("%d\n", s);
    return 0;
}
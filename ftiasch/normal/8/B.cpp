// Codeforces Beta Round #8
// Problem B -- Obsession with Robots
#include <cstdio>
#include <cstring>
#include <climits>

#define maxN 203

using namespace std;

const int dx[4] = {00, 00, +1, -1},
          dy[4] = {+1, -1, 00, 00};

int s_x, s_y, t_x, t_y, dis[maxN][maxN];
char str[maxN];
bool map[maxN][maxN];

void dfs(int x, int y, int d)
{
    if(map[x][y] && d < dis[x][y])
    {
        dis[x][y] = d;
        for(int i = 0; i < 4; ++ i)
            dfs(x + dx[i], y + dy[i], d + 1);
    }
}

int main()
{
    scanf("%s", str);
    memset(map, false, sizeof(map));
    int way[256];
    way['U'] = 0, way['D'] = 1, way['R'] = 2, way['L'] = 3;
    s_x = s_y = t_x = t_y = 101, map[t_x][t_y] = true, dis[t_x][t_y] = INT_MAX;
    for(int i = 0; i < strlen(str); ++ i)
        t_x += dx[way[str[i]]], t_y += dy[way[str[i]]], map[t_x][t_y] = true, dis[t_x][t_y] = INT_MAX;
    dfs(s_x, s_y, 0);
    printf(dis[t_x][t_y] == strlen(str)? "OK\n": "BUG\n");
    return 0;
}
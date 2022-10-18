#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,u[4009005];
char s[2005][2005];
vector<int> g[4009005];
queue< pair<int,int> > q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int degr(int x, int y) {
    return (s[y][x-1] == '.') + (s[y][x+1] == '.') + (s[y-1][x] == '.') + (s[y+1][x] == '.');
}

pii first_free(int x, int y) {
    if (s[y][x-1] == '.') return make_pair(x-1, y);
    if (s[y][x+1] == '.') return make_pair(x+1, y);
    if (s[y-1][x] == '.') return make_pair(x, y-1);
    if (s[y+1][x] == '.') return make_pair(x, y+1);
    return make_pair(-1,-1);
}

int neighbour(int x, int y) {
    if (s[y][x] == '<') return (y)*2003 + (x+1);
    if (s[y][x] == '>') return (y)*2003 + (x-1);
    if (s[y][x] == '^') return (y+1)*2003 + (x);
    if (s[y][x] == 'v') return (y-1)*2003 + (x);
    return -1;
}

void fail() {
    printf("Not unique");
    exit(0);
}

bool is_obstacle(int x, int y) {
    return s[y][x] != '.' && s[y][x] != '<' && s[y][x] != '>' && s[y][x] != 'v' && s[y][x] != '^';
}

bool dfs(int curver) {
    u[curver] = 1;
    for (int i = 0; i < g[curver].size(); ++i) {
        int to = g[curver][i];
        if (u[to] == 0) {
            if (dfs(to)) { fail(); return true; }
        } else if (u[to] == 1) { fail(); return true; }
    }
    u[curver] = 2;
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i)
        scanf("%s",s[i]+1);
    int black = 0, white = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != '.') continue;
            int curdegr = degr(j, i);
            if (curdegr == 0) fail();
            if (curdegr == 1) q.push(make_pair(j, i));
            if ((i + j) % 2 == 0) ++black;
            else ++white;
        }
    }
    if (black != white) fail();
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        if (s[cury][curx] != '.') continue;
        if (degr(curx, cury) == 0) fail();
        if (degr(curx, cury) >= 2) continue;
        pii frs = first_free(curx, cury);
        int newx = frs.first, newy = frs.second;
        if (cury == newy && curx + 1 == newx) {
            s[cury][curx] = '<';
            s[cury][curx+1] = '>';
        } else if (cury == newy && curx - 1 == newx) {
            s[cury][curx-1] = '<';
            s[cury][curx] = '>';
        } else if (cury + 1 == newy && curx == newx) {
            s[cury][curx] = '^';
            s[cury+1][curx] = 'v';
        } else {
            s[cury-1][curx] = '^';
            s[cury][curx] = 'v';
        }
        for (int k = 0; k < 4; ++k) {
            if (s[newy + dy[k]][newx + dx[k]] == '.' && degr(newx + dx[k], newy + dy[k]) == 1) {
                q.push(make_pair(newx + dx[k], newy + dy[k]));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == '.') fail();
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x)  {
            if (is_obstacle(x, y)) continue;
            int curver = y * 2003 + x;
            int neigh = neighbour(x, y);
            for (int k = 0; k < 4; ++k) {
                if (neigh == ((y + dy[k]) * 2003 + (x + dx[k]))) continue;
                if (!is_obstacle(x + dx[k], y + dx[k])) {
                    g[curver].push_back(neighbour(x + dx[k], y + dy[k]));
                }
            }
        }
    }

    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            if (dfs(y * 2003 + x)) fail();
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%s\n",s[i]+1);


    return 0;
}
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,X,Y,a[505][505],u[505][505];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
char cc[4] = {'R','D','L','U'}, anticc[4] = {'L','U','R','D'};
char ans[3001005];
int ansi;

void fail() { puts("NO"); exit(0); }

void dfs(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > n) return;
    if (u[y][x]) return;
    u[y][x] = 1;
    if (!a[y][x]) {
        ans[ansi++] = '1';
        a[y][x] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        bool good = false;
        int nx = x, ny = y;
        while (1) {
            nx += dx[i];
            ny += dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) break;
            if (a[ny][nx] == 1) { good = true; break; }
        }
        if (good) {
            ans[ansi++] = cc[i];
            dfs(x + dx[i], y + dy[i]);
            ans[ansi++] = anticc[i];
        }
    }
    a[y][x] = 0;
    ans[ansi++] = '2';
}

int main()
{
    scanf("%d%d%d",&n,&Y,&X);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    dfs(X, Y);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j]) fail();
    puts("YES");
    puts(ans);

    return 0;
}
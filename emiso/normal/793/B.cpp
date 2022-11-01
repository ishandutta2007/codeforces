#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, possible = 0, visit[1010][1010][4][3];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

pii ini, fim;
char g[MN], grid[1010][1010];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(pair<int,int> no, int dir, int t) {
    if(t > 2) return;

    if(no == fim) possible = 1;
    int x = no.first;
    int y = no.second;

    if(!valid(x, y)) return;
    if(grid[x][y] == '*') return;
    if(visit[x][y][dir][t]) return;
    visit[x][y][dir][t]++;

    dfs({x + dx[dir], y + dy[dir]}, dir, t);
    int dirR = (dir + 1) % 4;
    int dirL = (dir + 3) % 4;

    dfs({x + dx[dirL], y + dy[dirL]}, dirL, t + 1);
    dfs({x + dx[dirR], y + dy[dirR]}, dirR, t + 1);
}

int main() {
    scanf("%d %d",&n, &m);

    for(int i=0; i<n; i++) {
        scanf("%s", &g);
        for(int j=0;j<m;j++) {
            grid[i][j] = g[j];
            if(g[j] == 'S') ini = {i, j};
            if(g[j] == 'T') fim = {i, j};
        }
    }

    dfs(ini, 0, 0);
    dfs(ini, 1, 0);
    dfs(ini, 2, 0);
    dfs(ini, 3, 0);

    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}
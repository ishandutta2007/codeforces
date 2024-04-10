#include <bits/stdc++.h>

using namespace std;

int n, m;
char grid[2020][2020], s[2020];

bool check(int i, int j) {
    if(grid[i][j] == '.') return false;
    if(grid[i-1][j] == '.' && grid[i-1][j-1] == '.' && grid[i][j-1] == '.')
        grid[i][j] = '.';
    else if(grid[i-1][j] == '.' && grid[i-1][j+1] == '.' && grid[i][j+1] == '.')
        grid[i][j] = '.';
    else if(grid[i+1][j] == '.' && grid[i+1][j+1] == '.' && grid[i][j+1] == '.')
        grid[i][j] = '.';
    else if(grid[i+1][j] == '.' && grid[i+1][j-1] == '.' && grid[i][j-1] == '.')
        grid[i][j] = '.';
    else return false;
    return true;
}

int main() {
    scanf("%d %d", &n, &m);

    memset(grid, '*', sizeof grid);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for(int j = 1; j <= m; j++)
            grid[i][j] = s[j];
    }

    queue<pair<int, int> > fila;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(check(i, j))
                fila.push({i, j});

    while(!fila.empty()) {
        auto p = fila.front(); fila.pop();
        for(int i = p.first - 1; i <= p.first + 1; i++)
            for(int j = p.second - 1; j <= p.second + 1; j++)
                if(check(i, j))
                    fila.push({i, j});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            printf("%c", grid[i][j]);
        puts("");
    }
    return 0;
}
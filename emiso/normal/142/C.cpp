#include <bits/stdc++.h>

using namespace std;

int n, m, best;
vector<vector<char>> g, ans;

void fim() {
    printf("%d\n", best);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%c", ans[i][j]);
        puts("");
    }
    exit(0);
}

void cmon(int i, int j, int cur) {
    if(cur > best) {
        best = cur;
        ans = g;
    }
    if(clock() > 1.5 * CLOCKS_PER_SEC) fim();
    if(j + 2 >= m) return;
    if(cur + ((m-j-1)*n+(n-i))/5 < best) return;

    if(i + 2 >= n) {
        cmon(0, j + 1, cur);
        return;
    }

    if(g[i][j] == '.' && g[i+1][j] == '.' && g[i+2][j] == '.' && g[i+1][j+1] == '.' && g[i+1][j+2] == '.') {
       g[i][j] = g[i+1][j] = g[i+2][j] = g[i+1][j+1] = g[i+1][j+2] = char('A' + cur);
       cmon(i + 2, j, cur + 1);
       g[i][j] = g[i+1][j] = g[i+2][j] = g[i+1][j+1] = g[i+1][j+2] = '.';
    }
    if(g[i][j] == '.' && g[i][j+1] == '.' && g[i][j+2] == '.' && g[i+1][j+1] == '.' && g[i+2][j+1] == '.') {
       g[i][j] = g[i][j+1] = g[i][j+2] = g[i+1][j+1] = g[i+2][j+1] = char('A' + cur);
       cmon(i + 2, j, cur + 1);
       g[i][j] = g[i][j+1] = g[i][j+2] = g[i+1][j+1] = g[i+2][j+1] = '.';
    }
    if(g[i][j+2] == '.' && g[i+1][j+2] == '.' && g[i+2][j+2] == '.' && g[i+1][j+1] == '.' && g[i+1][j] == '.') {
       g[i][j+2] = g[i+1][j+2] = g[i+2][j+2] = g[i+1][j+1] = g[i+1][j] = char('A' + cur);
       cmon(i + 2, j, cur + 1);
       g[i][j+2] = g[i+1][j+2] = g[i+2][j+2] = g[i+1][j+1] = g[i+1][j] = '.';
    }
    if(g[i+2][j] == '.' && g[i+2][j+1] == '.' && g[i+2][j+2] == '.' && g[i+1][j+1] == '.' && g[i][j+1] == '.') {
       g[i+2][j] = g[i+2][j+1] = g[i+2][j+2] = g[i+1][j+1] = g[i][j+1] = char('A' + cur);
       cmon(i + 3, j, cur + 1);
       g[i+2][j] = g[i+2][j+1] = g[i+2][j+2] = g[i+1][j+1] = g[i][j+1] = '.';
    }
    cmon(i + 1, j, cur);
}

int main() {
    scanf("%d %d", &n, &m);
    ans = g = vector<vector<char>>(n, vector<char>(m, '.'));

    cmon(0, 0, 0);
    fim();
    return 0;
}
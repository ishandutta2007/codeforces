#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

void re(int& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int rows,cols;

int seen[1100][1100];
char board[1100][1100];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y) {
    if (seen[x][y]) return;
    seen[x][y] = 1;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
        if (board[nx][ny] == '.') continue;
        dfs(nx,ny);
    }
}

void solve()
{
    re(rows,cols);
    for (int i = 0; i < rows; i++) scanf("%s", board[i]);

    int unr = 0, unc = 0;

    for (int i = 0; i < rows; i++) {
        int c = 0;
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == '#' && (j == 0 || board[i][j-1] == '.')) c++;
        }
        if (c > 1) {
            ps(-1);
            return;
        }
        if (c == 0) unr = 1;
    }

    for (int j = 0; j < cols; j++) {
        int c = 0;
        for (int i = 0; i < rows; i++) {
            if (board[i][j] == '#' && (i == 0 || board[i-1][j] == '.')) c++;
        }
        if (c > 1) {
            ps(-1);
            return;
        }
        if (c == 0) unc = 1;
    }

    if (unr + unc == 1) {
        ps(-1);
        return;
    }
    
    int ans = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) if (!seen[i][j] && board[i][j]=='#') {
            dfs(i,j);
            ans++;
        }
    }

    ps(ans);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
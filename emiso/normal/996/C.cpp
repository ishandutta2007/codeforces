#include <bits/stdc++.h>

using namespace std;

int n, k, g[5][200], f;

struct mov {
    int i, x, y;
    mov(int i, int x, int y) : i(i), x(x), y(y) {}
};
vector<mov> moves;

void check(int r, int c) {
    if(g[r][c] == 0) return;
    if(r == 1 && (g[r-1][c] == g[r][c])) {
        moves.emplace_back(g[r][c], 1, c + 1);
        g[r][c] = 0;
        f++;
    }
    else if(r == 2 && (g[r+1][c] == g[r][c])) {
        moves.emplace_back(g[r][c], 4, c + 1);
        g[r][c] = 0;
        f++;
    }
}

void movecar(int Or, int oc, int nr, int nc) {
    if(g[Or][oc] == 0) return;
    if(g[nr][nc] == 0) {
        moves.emplace_back(g[Or][oc], nr+1, nc+1);
        g[nr][nc] = g[Or][oc];
        g[Or][oc] = 0;
    }
    check(nr, nc);
}

void movecars() {
    movecar(1, 0, 2, 0);
    for(int i = 1; i < n; i++)
        movecar(1, i, 1, i-1);

    movecar(2, n-1, 1, n-1);
    for(int i = n - 2; i >= 0; i--)
        movecar(2, i, 2, i+1);
}

int main(){
    scanf("%d %d",&n, &k);

    for(int r = 0; r < 4; r++)
        for(int i = 0; i < n; i++)
            scanf("%d", &g[r][i]);

    for(int i = 0; i < n; i++) {
        check(1, i);
        check(2, i);
    }

    if(k - f == 2 * n) puts("-1");
    else {
        while(f < k) {
            movecars();
        }

        printf("%d\n", moves.size());
        for(auto m : moves) {
            printf("%d %d %d\n", m.i, m.x, m.y);
        }
    }

    return 0;
}
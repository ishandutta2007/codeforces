#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int n;
int ax, ay, bx, by, cx, cy;
void read() {
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
}

bool ch(int x, int y) {
    return (x == ax || y == ay || abs(x - ax) == abs(y - ay));
}

bool used[MAXN][MAXN];

bool check(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n && !ch(x, y) && !used[x][y];
}

void dfs(int x, int y) {
    if (x == cx && y == cy) {
        cout << "YES\n";
        exit(0);
    }
    used[x][y] = 1;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            if (check(x + i, y + j)) dfs(x + i, y + j);
        }
    }
}

void solve() {
    dfs(bx, by);
}

void print() {
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}
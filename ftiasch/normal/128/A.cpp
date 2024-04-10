#include <cstdio>
#include <cstring>

using namespace std;

const int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

char map[11][11];
bool vis[11][11][11];

int main() {
    for (int i = 0; i < 8; ++ i) {
        scanf("%s", map[i]);
    }
    memset(vis, 0, sizeof(vis));
    vis[0][7][0] = true;
    for (int k = 0; k < 10; ++ k) {
        for (int i = 0; i < 8; ++ i) {
            for (int j = 0; j < 8; ++ j) {
                if (map[i][j] == 'S' && i + k < 8) {
                    vis[k][i + k][j] = false;
                }
            }
        }
        for (int i = 0; i < 8; ++ i) {
            for (int j = 0; j < 8; ++ j) {
                if (!vis[k][i][j]) {
                    continue;
                }
                for (int _ = 0; _ < 9; ++ _) {
                    int x = i + dx[_];
                    int y = j + dy[_];
                    if (0 <= x && x < 8
                            && 0 <= y && y < 8) {
                        vis[k + 1][x][y] = true;
                    }
                }
            }
        }
        for (int i = 0; i < 8; ++ i) {
            for (int j = 0; j < 8; ++ j) {
                if (map[i][j] == 'S' && i + k < 8) {
                    vis[k + 1][i + k][j] = false;
                }
            }
        }
    }
    bool ok = false;
    for (int i = 0; i < 8; ++ i) {
        for (int j = 0; j < 8; ++ j) {
            ok |= vis[10][i][j];
        }
    }
    if (ok) {
        printf("WIN\n");
    } else {
        printf("LOSE\n");
    }
    return 0;
}
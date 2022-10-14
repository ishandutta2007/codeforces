#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <utility>

const int N = 2000;
const int DELTA[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int n, m, k, need[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            need[i][j] = INT_MAX;
        }
    }
    std::queue <std::pair <int, int> > queue;
    while (k --) {
        int x, y;
        scanf("%d%d", &x, &y);
        x --, y --;
        need[x][y] = 0;
        queue.push(std::make_pair(x, y));
    }
    int answer_x = 0, answer_y = 0;
    while (!queue.empty()) {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        for (int k = 0; k < 4; ++ k) {
            int xx = x + DELTA[k][0];
            int yy = y + DELTA[k][1];
            if (0 <= xx && xx < n && 0 <= yy && yy < m && need[xx][yy] == INT_MAX) {
                answer_x = xx;
                answer_y = yy;
                need[xx][yy] = need[x][y] + 1;
                queue.push(std::make_pair(xx, yy));
            }
        }
    }
    printf("%d %d\n", answer_x + 1, answer_y + 1);
    return 0;
}
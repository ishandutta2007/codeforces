#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 100;

int n, m, config[N][2];
int memory[N][N][4][4];
std::vector <int> buffer[N][N][4][4];

int get_sg(int l, int r, int x, int y) {
    if (l > r) {
        return 0;
    }
    int &ret = memory[l][r][x][y];
    if (ret == -1) {
        std::vector <int> &b = buffer[l][r][x][y];
        for (int i = l; i <= r; ++ i) {
            for (int j = 0; j < 2; ++ j) {
                if (config[i][j]) {
                    continue;
                }
                if (i == l && (x >> j & 1)) {
                    continue;
                }
                if (i == r && (y >> j & 1)) {
                    continue;
                }
                b.push_back(get_sg(l, i - 1, x, 1 << (j ^ 1)) ^ get_sg(i + 1, r, 1 << (j ^ 1), y));
            }
        }
        std::sort(b.begin(), b.end());
        b.erase(std::unique(b.begin(), b.end()), b.end());
        ret = 0;
        while (ret < (int)b.size() && b[ret] == ret) {
            ret ++;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(config, 0, sizeof(config));
    for (int i = 0; i < m; ++ i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x --, y --;
        config[x][y] = config[x][y ^ 1] = true;
        if (x) {
            config[x - 1][y ^ 1] = true;
        }
        if (x + 1 < n) {
            config[x + 1][y ^ 1] = true;
        }
    }
    memset(memory, -1, sizeof(memory));
    puts(get_sg(0, n - 1, 0, 0) ? "WIN" : "LOSE");
    return 0;
}
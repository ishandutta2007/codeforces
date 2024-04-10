#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

const int N = 35;

int n;
std::vector<std::pair<int, bool>> rel[N << 1];
long long ways[(N << 1) + 1][(N << 1) + 1];

bool check(int x, int y, int l, int r)
{
    std::vector <int> vv;
    vv.push_back(x);
    vv.push_back(y);
    for (int z : vv) {
        for (const auto &iterator : rel[z]) {
            bool valid = false;
            if (iterator.second && (iterator.first == x || iterator.first == y)) {
                valid = true;
            }
            if (l <= iterator.first && iterator.first < (n << 1) - r) {
                valid = true;
            }
            if (!valid) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int k;
    scanf("%d%d", &n, &k);
    while (k --) {
        int x, y;
        char op[3];
        scanf("%d%s%d", &x, op, &y);
        x --;
        y --;
        if (*op == '>') {
            std::swap(x, y);
        }
        if (*op == '=') {
            rel[x].push_back({y, true});
            rel[y].push_back({x, true});
        } else {
            rel[x].push_back({y, op[1] == '='});
        }
    }
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;
    for (int i = 0; i <= n << 1; ++ i) {
        for (int j = 0; i + j < (n << 1); ++ j) {
            if (ways[i][j]) {
                bool last = i + j + 2 == (n << 1);
                if (check(i, i + 1, i + 2, j)) {
                    ways[i + 2][j] += ways[i][j];
                }
                if (!last) {
                    if (check(i, (n << 1) - 1 - j, i + 1, j + 1)) {
                        ways[i + 1][j + 1] += ways[i][j];
                    }
                    if (check((n << 1) - 2 - j, (n << 1) - 1 - j, i, j + 2)) {
                        ways[i][j + 2] += ways[i][j];
                    }
                }
            }
        }
    }
    long long result = 0;
    for (int i = 0; i <= n << 1; ++ i) {
        result += ways[i][(n << 1) - i];
    }
    std::cout << result << std::endl;
    return 0;
}
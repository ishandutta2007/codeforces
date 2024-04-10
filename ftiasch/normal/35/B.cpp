#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

const int N = 30;

int n, m, k;
std::string shelves[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    while (k --) {
        int type, x, y;
        std::string name;
        std::cin >> type;
        if (type > 0) {
            std::cin >> x >> y >> name;
            x --;
            y --;
            bool found = false;
            for (int i = x; i < n && !found; ++ i) {
                for (int j = i == x ? y : 0; j < m && !found; ++ j) {
                    if (shelves[i][j] == "") {
                        found = true;
                        shelves[i][j] = name;
                    }
                }
            }
        } else {
            std::cin >> name;
            bool found = false;
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    if (shelves[i][j] == name) {
                        found = true;
                        shelves[i][j] = "";
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
            }
            if (!found) {
                puts("-1 -1");
            }
        }
    }
    return 0;
}
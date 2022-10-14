#include <cstdio>
#include <cstring>

int x, t, a, b, da, db;

bool solve() {
    for (int i = -1; i < t; ++ i) {
        for (int j = -1; j < t; ++ j) {
            int sum = 0;
            if (i >= 0) {
                sum += a - da * i;
            }
            if (j >= 0) {
                sum += b - db * j;
            }
            if (sum == x) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d%d%d%d", &x, &t, &a, &b, &da, &db);
    puts(solve() ? "YES" : "NO");
    return 0;
}
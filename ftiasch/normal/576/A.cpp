#include <cstdio>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> result;
    for (int i = 2; i <= n; ++ i) {
        int x = i;
        int p = 2;
        while (x % p != 0) {
            p ++;
        }
        while (x % p == 0) {
            x /= p;
        }
        if (x == 1) {
            result.push_back(i);
        }
    }
    printf("%d\n", (int)result.size());
    for (int y : result) {
        printf("%d ", y);
    }
    puts("");
    return 0;
}
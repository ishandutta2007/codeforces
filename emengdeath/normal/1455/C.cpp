#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (!y) {
            printf("%d 0\n", x);
            continue;
        }
        if (!x) {
            printf("0 %d\n", y);
            continue;
        }
        printf("%d %d\n", x - 1, y);
    }
    return 0;
}
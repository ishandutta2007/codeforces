#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            puts("1");
            continue;
        }
        if (n & 1)
            printf("%d\n", (n + 1) / 2);
        else
            printf("%d\n", (n + 3) / 2);
    }
    return 0;
}
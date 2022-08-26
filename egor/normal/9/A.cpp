#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int c = 7 - max(a, b);
    int d = 6;
    if (c % 2 == 0) {
        c /= 2;
        d /= 2;
    }
    if (c % 3 == 0) {
        c /= 3;
        d /= 3;
    }
    printf("%d/%d\n", c, d);
    return 0;
}
#include  <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == b) {
            puts("0");
            continue;
        }
        if (a < b) {
            if ((b - a) & 1)
                puts("1");
            else
                puts("2");
        } else
            if (!((a - b) & 1)) {
                puts("1");
            } else
                puts("2");
    }
    return 0;
}
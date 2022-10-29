#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        if (n == 1) {
            puts("0");
            continue;
        }
        if (n == 2) {
            puts("1");
            continue;
        }
        if (n == 3) {
            puts("2");
            continue;
        }
        if (n & 1) {
            puts("3");
            continue;
        }
        puts("2");
    }
    return 0;
}
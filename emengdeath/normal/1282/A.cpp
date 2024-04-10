#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int a, b, c, t;
int T;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d %d", &a, &b, &c, &t);
        if (a > b) swap(a, b);
        int l = max(c - t, a), r = min(c + t, b);
        printf("%d\n", b - a - max(r - l, 0));
    }
    return 0;
}
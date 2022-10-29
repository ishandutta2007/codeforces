#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        bool sig1 = 0;
        bool sig2 = 0;
        for (int i = 1; i <= n; i ++) {
            char c;
            scanf(" %c", &c);
            c -= '0';
            if (i & 1)
                sig1 |= (c & 1);
            else
                sig2 |= ((c + 1) & 1);
        }
        if (n & 1) {
            sig1 ? puts("1") :puts("2");
        } else {
            sig2 ? puts("2"):puts("1");
        }
    }
    return 0;
}
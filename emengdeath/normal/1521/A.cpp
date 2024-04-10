#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b == 1) {
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%lld %lld %lld\n", 1ll * a  * b, 1ll *a, 1ll * a * (b + 1));
    }
    return 0;
}
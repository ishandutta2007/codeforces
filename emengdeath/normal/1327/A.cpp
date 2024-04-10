#include <algorithm>
#include <cstdio>
using namespace std;
int T;
int main() {
    scanf("%d", &T);
    while (T --) {
        int n, k;
        scanf("%d %d", &k, &n);
        if (!((n + k) & 1) && 1ll * n * (n - 1) + n <= k)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
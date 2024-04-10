#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
int T;
int n;
int a[N], b[N], c[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int x = 1;
        for (int i = 1;i <= n; i ++) {
            scanf("%d", &a[i]);
            if (a[i] > a[x]) x = i;
        }
        printf("%d", a[x]);
        int y = a[x];
        a[x] = -1;
        for (int i = 2; i <= n; i ++) {
            x = -1;
            for (int j = 1; j <= n; j ++)
                if (a[j] != -1 && (x == -1||__gcd(a[x], y) < __gcd(a[j], y)))
                    x = j;
            printf(" %d", a[x]);
            y = __gcd(a[x], y);
            a[x] = -1;
        }
        puts("");
    }
    return 0;
}
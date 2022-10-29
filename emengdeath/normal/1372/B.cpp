#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n = 0;
        scanf("%d", &n);
        int mx = 1;
        for (int i = 1; 1ll * i * i <= n; i ++)
            if (n % i == 0) {
                mx = max(mx, i);
                if (i != 1)
                    mx = max(mx, n / i);
            }
        printf("%d %d\n", mx, n - mx);
    }
    return 0;
}
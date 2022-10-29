#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k;
int bz[1000];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &k);
        memset(bz, 0, sizeof(bz));
        bool sig = 1;
        while (n --) {
            long long x;
            scanf("%lld", &x);
            for (int i = 0; x; i ++, x /= k) {
                int y = x % k;
                bz[i] += y;
                if (bz[i] > 1) sig = 0;
            }
        }
        sig?puts("YES"):puts("NO");
    }
    return 0;
}
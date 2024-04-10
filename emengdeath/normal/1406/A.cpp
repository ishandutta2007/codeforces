#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 101;
int sum[N];
int T, n;
int main() {
    scanf("%d", &T);
    while (T --) {
        memset(sum, 0, sizeof(sum));
        scanf("%d", &n);
        while (n --) {
            int x = 0;
            scanf("%d", &x);
            sum[x] ++;
        }
        int ans = 0;
        for (int i = 0; i <= 100; i ++)
        {
            for (int j = 0; j <= 100; j ++) {
                int v = sum[j] - (j < i);
                if (!v) {
                    ans = max(ans, j + i);
                    break;
                }
            }
            if (!sum[i]) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n;
int T;
bool bz[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d ", &n);
        for (int i= 1; i <= n; i ++)
            bz[i] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            int k;
            scanf("%d", &k);
            bool sig = 0;
            while (k --) {
                int x;
                scanf("%d", &x);
                if (!bz[x] && !sig)  {
                    bz[x] = 1;
                    sig = 1;
                }
            }
            if (!sig && !ans)
                ans = i;
        }
        if (!ans) {
            puts("OPTIMAL");
        } else {
            puts("IMPROVE");
            printf("%d ", ans);
            for (int i = 1; i <= n; i ++)
                if (!bz[i]) {
                    printf("%d\n", i);
                    break;
                }
        }
    }
    return 0;
}
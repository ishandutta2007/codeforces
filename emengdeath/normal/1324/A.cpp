#include <algorithm>
#include <cstdio>
using namespace std;
int a[10000];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        int x = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            x = max(x, a[i]);
        }
        bool sig = 1;
        for (int i = 1; i <= n; i ++)
            sig &= !((x - a[i]) &1);
        sig?puts("YES"):puts("NO");
    }
    return 0;
}
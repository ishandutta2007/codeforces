#include <cstdio>

using namespace std;

int t, n, ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int i = 1;
        ans = 0;
        for (i = 1; i * 9ll <= n; i = i * 10 + 1) {
            ans += 9;
        }
        for (int j = 1; i * j <= n; ++j) {
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
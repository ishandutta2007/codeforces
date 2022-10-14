#include <algorithm>
#include <cstdio>
#include <cstring>

int main()
{
#ifdef LOCAL_JUDGE
    freopen("A.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) == 1) {
        int minimum[3];
        memset(minimum, 0, sizeof(minimum));
        for (int i = 0; i < n; ++ i) {
            int a;
            scanf("%d", &a);
            int new_minimum[] = {n, n, n};
            for (int x = 0; x < 3; ++ x) {
                for (int y = 0; y < 3; ++ y) {
                    if (x < 2 && y < 2 && x == y || y < 2 && (~a >> y & 1)) {
                        continue;
                    }
                    new_minimum[y] = std::min(new_minimum[y], minimum[x] + (y >= 2));
                }
            }
            memcpy(minimum, new_minimum, sizeof(new_minimum));
        }
        printf("%d\n", *std::min_element(minimum, minimum + 3));
    }
}
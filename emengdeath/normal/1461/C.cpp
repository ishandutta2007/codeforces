#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int T, n, m;
int a[N], b[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n;i ++)
            scanf("%d", &a[i]), b[i] = a[i];
        int l =0;
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i ++)
            if (b[i] != a[i]) {
                l = i;
            }
        double p = 0;
        if (l == 0)  p = 1;
        while (m -- ){
            int x;
            double y;
            scanf("%d %lf", &x, &y);
            if (x >= l) {
                p += (1 - p) * y;
            }
        }
        printf("%.10f\n", p);
    }
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 301;
int n, m;
int a[N], b[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n;i ++) {
            int x;
            scanf("%d", &x);
            a[x] ++;
        }
        for (int i = 1; i <= m;i ++) {
            int x;
            scanf("%d", &x);
            b[x] ++;
        }
        int sum =  0;
        for (int i = 1; i <= 300; i ++)
            sum += max(a[i], b[i]);
        printf("%d\n", n + m - sum);
    }
    return 0;
}
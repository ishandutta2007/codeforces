#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5;
int a[N + 1], d[N], b[N], c[N];
int n;
int output(char x, int y) {
   printf("%c %d\n", x, y);
   fflush(stdout);
   scanf("%d", &y);
   return y;
}
int main() {
    scanf("%d", &n);
    for (int i= 2; i <= n; i ++){
        if (!a[i])
            d[a[i] = ++d[0]] = i;
        for (int j = 1; j <= a[i] && 1ll * i * d[j] <= n; j ++)
            a[d[j] * i] = j;
    }
    for (int i = 1;i <= d[0]; i ++)
        if (1ll * d[i] * d[i] <= n)
            b[++b[0]] = d[i];
        else
            c[++c[0]] = d[i];
    for (int i = 1; i <= b[0]; i ++)
        output('B', b[i]);
    int sum = (c[0] + 99) / 100;
    int l = 1;
    int ans = 1;
    int now = output('A', 1);
    while (l <= c[0]) {
        int all = 0;
        int tmp = now;
        for (int i = 0; i < sum && i + l <= c[0]; i ++) {
            all += output('B', c[i + l]);
        }
        now = output('A', 1);
        if (now + all != tmp) {
            for (int i = 0; i < sum; i ++)
                if (output('B', c[i + l])) {
                    ans = c[i + l];
                    break;
                }
            break;
        }
        l += sum;
    }
    for (int i = 1; i <= b[0]; i ++) {
        int x = b[i];
        while (output('A', x)) {
            ans *= b[i];
            if (1ll * x * b[i] > n) break;
            x *= b[i];
        }
    }
    printf("C %d\n", ans);
    return 0;
}
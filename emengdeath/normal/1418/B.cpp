#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int b[N];
bool bz[N];
int n;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n;i ++)
            scanf("%d", &a[i]);
        b[0] = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            bz[i] = x;
            if (!bz[i]) {
                b[++b[0]] = a[i];
            }
        }
        sort(b + 1, b + b[0] + 1);
        reverse(b + 1,b + b[0] + 1);
        int l = 0;
        for (int i = 1; i <= n; i ++)
            if (!bz[i])
                a[i] = b[++l];
        for (int i = 1; i <= n; i ++)
            printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6;
int a[N], b[N];
int n;
int did(int x) {
    if (x == 1) return -1;
    return 1;
}
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i <= n + n + n + n; i ++)
            b[i] = 0;
        int all = 0;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), all += did(a[i]);
        int pre = 0;
        int ans = n + n;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            pre += did(x);
            if (!b[pre + n + n])
                b[pre + n + n] = i;
            all += did(x);
        }
        if (b[all + n + n]) ans = min(ans, b[all + n + n]);
        if (!all) ans = 0;
        pre = 0;
        for (int i = n; i >= 1; i --) {
            pre += did(a[i]);
            if (b[all - pre + n + n])  ans = min(ans, b[all - pre + n + n] + n - i + 1);
            if (all == pre) ans =min(ans, n - i + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, ans = INT_MAX, mn = ans, mx[maxn];
bool chk[maxn];
int calc(int x) { return x - mx[x] + 1; }

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (!chk[i]) {
            if (!(n % i)) {
                mn = min(mn, n - i + 1);
            }
            for (int j = i + i; j <= n; j += i) {
                mx[j] = i, chk[j] = 1;
            }
        }
    }
    for (int i = mn; i <= n; i++) {
        ans = min(ans, calc(i));
    }
    printf("%d\n", ans);
    return 0;
}
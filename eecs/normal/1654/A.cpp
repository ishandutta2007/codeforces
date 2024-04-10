#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mx = 0, sec = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > mx) sec = mx, mx = a[i];
            else if (a[i] > sec) sec = a[i];
        }
        printf("%d\n", mx + sec);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (a[i] != a[j] && a[j] != a[k] && a[i] != a[k] &&
                    abs(a[i] - a[j]) <= 2 && abs(a[i] - a[k]) <= 2 &&
                    abs(a[j] - a[k]) <= 2) puts("YES"), exit(0);
            }
        }
    }
    puts("NO");
    return 0;
}
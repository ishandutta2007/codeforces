#include <bits/stdc++.h>
using namespace std;

int n, a[15];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 1 << n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) s += a[j];
            else s -= a[j];
        }
        if (!(abs(s) % 360)) puts("YES"), exit(0);
    }
    puts("NO");
    return 0;
}
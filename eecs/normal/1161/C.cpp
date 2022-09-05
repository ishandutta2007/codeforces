#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    while (1) {
        int num = count(a + 1, a + n + 1, 1);
        if (num > n / 2) puts("Bob"), exit(0);
        if (num && num <= n / 2) puts("Alice"), exit(0);
        for (int i = 1; i <= n; i++) a[i]--;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    int ans = 0, tmp = n - 1;
    while (tmp) tmp /= k, ans++;
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int cur = 0, tmp1 = i, tmp2 = j;
            while (tmp1 != tmp2) cur++, tmp1 /= k, tmp2 /= k;
            printf("%d%c", cur, " \n"[i == n - 2 && j == n - 1]);
        }
}
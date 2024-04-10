#include <bits/stdc++.h>
using namespace std;
int a[310][310], b[310];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) {
        int maxans = n + 1, maxid;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            int now = -1;
            for (int k = 1; k <= n; k++) {
                if (b[k] <= j && b[k] != i) {
                    now = b[k];
                    break;
                }
            }
            for (int k = 1; k <= n; k++) {
                if (a[i][k] == now) {
                    now = k;
                    break;
                }
            }
            if (maxans > now) maxans = now, maxid = j;
        }
        printf("%d%c", maxid, " \n"[i == n]);
    }
}
#include <bits/stdc++.h>
using namespace std;
int cnt[40][2];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < 30; j++, x >>= 1) cnt[j][x & 1]++;
        }
        for (int i = 30; i --> 0;) {
            if (i == 0) cerr << cnt[i][1] << endl;
            if (cnt[i][1] % 2 == 0) continue;
            if (cnt[i][1] % 4 == 1 || cnt[i][0] % 2 == 1) puts("WIN");
            else puts("LOSE");
            goto gototag;
        }
        puts("DRAW");
        gototag:;
    }
}
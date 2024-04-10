#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll q, n, ans, a[30][30];
//char s[MN]; string str;

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i % 2 == 0) a[i][j] = (1LL << (i + j));
            printf("%lld%c", a[i][j], (j < n) ? ' ' : '\n');
        }
        fflush(stdout);
    }

    scanf("%lld", &q);
    while(q--) {
        ll k;
        scanf("%lld", &k);
        int x = 1, y = 1, diag = 3;

        printf("%d %d\n", x, y);
        fflush(stdout);
        while(x != n || y != n) {
            ll active = ((1LL << diag++) & k);
            if(active != 0) {
                if(x % 2 == 0) y++;
                else x++;
            } else {
                if(x % 2 == 0) x++;
                else y++;
            }
            printf("%d %d\n", x, y);
            fflush(stdout);
        }
    }
    return 0;
}
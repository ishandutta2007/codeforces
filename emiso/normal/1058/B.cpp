#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, n, m, x, y, ans, flag = 0;
    scanf("%d %d %d", &n, &d, &m);

    if(2*d > n) {
        flag = 1;
        d = n - d;
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ans = 0;
        if(flag) x = n - x;

        if(x < d) {
            if(y >= d - x && y <= d + x) ans++;
        } else if(x > n - d) {
            if(y >= x - d && y <= 2*n - x - d) ans++;
        } else {
            if(y >= x - d && y <= x + d) ans++;
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
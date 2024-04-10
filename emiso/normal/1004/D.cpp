#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int t, a[MN], f[MN], mx, tot, n, m, x, y;

inline int calc(ll d) {
    ll quant = 2LL * d * (d+1LL) + 1LL;

    ll d0, d1, d2, d3;

    d0 = 0 - min(0LL, x - d);
    quant -= d0*d0;

    d1 = max(n-1LL, x + d) - (n-1);
    quant -= d1*d1;

    d2 = 0 - min(0LL, y - d);
    quant -= d2*d2;

    d3 = max(m-1LL, y + d) - (m-1);
    quant -= d3*d3;

    ll e02, e03, e12, e13;

    e02 = 0 - min(0LL, y - d0 + 1) - 1;
    quant += e02 * (e02+1) / 2;

    e03 = max(m-1LL, y + d0 - 1) - (m-1);
    quant += e03 * (e03+1) / 2;

    e12 = 0 - min(0LL, y - d1 + 1);
    quant += e12 * (e12+1) / 2;

    e13 = max(m-1LL, y + d1 - 1) - (m-1);
    quant += e13 * (e13+1) / 2;

    return quant;
}

int main() {
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%d", &a[i]);
        f[a[i]]++;
        mx = max(mx, a[i]);
    }

    for(int d = 1; d * d <= t; d++) {
        if(t % d) continue;
        n = d, m = t / d;

        if(mx < n) x = mx;
        else x = n - 1;
        y = mx - x;

        while(x >= 0 && y < m) {
            int flag = 1, tot = 0;

            for(int d = 0; d <= mx; d++) {
                int fd = calc(d) - tot;

                if(fd != f[d]) {
                    flag = 0;
                    break;
                }

                tot += fd;
            }


            if(flag) {
                printf("%d %d\n%d %d\n", n, m, x+1, y+1);
                return 0;
            }
            x--; y++;
        }

    }

    printf("-1\n");
    return 0;
}
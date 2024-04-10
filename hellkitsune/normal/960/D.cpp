#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int q;
LL sum[70];

int lev;
LL from, to, sz;
void getLevel(LL x) {
    lev = 0;
    from = 1;
    to = 1;
    sz = 1;
    while (to < x) {
        from *= 2;
        to = 2 * to + 1;
        sz *= 2;
        ++lev;
    }
}

void fixk(LL &k, LL sz) {
    k *= -1;
    k %= sz;
    if (k < 0) {
        k += sz;
    }
}

int main() {
    scanf("%d", &q);
    forn(_, q) {
        int qt;
        LL x, k;
        scanf("%d", &qt);
        if (qt == 1) {
            scanf("%I64d%I64d", &x, &k);
            getLevel(x);
            fixk(k, sz);
            sum[lev] = (sum[lev] + k) % sz;
        } else if (qt == 2) {
            scanf("%I64d%I64d", &x, &k);
            getLevel(x);
            fixk(k, sz);
            while (lev <= 60) {
                sum[lev] = (sum[lev] + k) % sz;
                k *= 2;

                from *= 2;
                to = 2 * to + 1;
                sz *= 2;
                ++lev;
            }
        } else {
            scanf("%I64d", &x);
            getLevel(x);
            x -= from;
            x -= sum[lev];
            if (x < 0) {
                x += sz;
            }
            while (lev >= 0) {
                printf("%I64d ", (x + sum[lev]) % sz + from);
                x /= 2;

                from /= 2;
                to /= 2;
                sz /= 2;
                --lev;
            }
            printf("\n");
        }
    }
    return 0;
}
#include <cstdio>

#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

ll sft1[63], sft2[63];

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int t, lev = 0;
        ll x, k;
        scanf("%d%lld", &t, &x);
        while ((1LL << lev) <= x)
            ++lev;
        --lev;
//        printf("%lld: %d\n", x, lev);
        if (t == 1) {
            scanf("%lld", &k);
            k %= 1LL << lev;
            if (k < 0)
                k += 1LL << lev;
            sft2[lev] = (sft2[lev] + k) % (1LL << lev);
            ++lev;
            k <<= 1;
            sft2[lev] = (sft2[lev] - k + (1LL << lev)) % (1LL << lev);
        }
        if (t == 2) {
            scanf("%lld", &k);
            k %= 1LL << lev;
            if (k < 0)
                k += 1LL << lev;
            sft2[lev] = (sft2[lev] + k) % (1LL << lev);
        }
        if (t == 3) {
            while (x != 1) {
                printf("%lld ", x);
                x = (x + sft2[lev]) % (1LL << lev);
                x |= 1LL << lev;
                x >>= 1;
                --lev;
            }
            puts("1");
        }
    }
    return 0;
}
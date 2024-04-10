#include <bits/stdc++.h>

using namespace std;

typedef long long LL;   

const LL P = 998244353;
const LL INF = 0x3f3f3f3f;
const LL INFLL = 0x3f3f3f3f3f3f3f3fll;
const LL N = 2e5 + 5;

LL n, m, k;
LL a, b, c, d;
LL gap, dif;

LL calc(LL x) {
    if(x == 0) return 0;
    if(x <= dif - gap) return gap + x;
    return dif + 2 * (x - (dif - gap));
}

void init() {
    LL ans = 0;
    cin >> n >> m >> a >> b >> c >> d;
    if(a > c) {
        swap(a, c);
        swap(b, d);
    }
    m -= n * max(0ll, min(b - c, d - c));
    if(m <= 0) return (void) printf("0\n");
    gap = max(0ll, c - b);
    dif = 2 * (max(b, d) - a) - (b - a) - (d - c);
    k = dif - gap;
    LL i;
    //printf("k = %lld, dif = %lld\n", k, dif);
    for(i = 1; i <= n; i++) {
        if(m >= k) {
            ans += calc(k);
            m -= k;
        }
        else break;
    }
    if(i == 1) {
        ans = ans + calc(m);
    }
    else if(i != n + 1) {
        ans = min(ans - calc(k) + calc(m + k), ans + calc(m));
        //printf("case2\n");
    }
    else {
        ans = ans - calc(k) + calc(m + k);
    }
    cout << ans << endl;
}

int main() {
    LL T;
    cin >> T;
    for(LL i = 1; i <= T; i++) init();
    return 0;
}










/**********************************************************************************






























**********************************************************************************/
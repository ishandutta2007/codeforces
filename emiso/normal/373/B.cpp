#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll w, m, k, ans;

int main() {
    scanf("%lld %lld %lld", &w, &m, &k);
    w /= k;
    ll p10 = 10, len = 1;
    while(1) {
        while(p10 <= m) p10 *= 10LL, len++;
        ll num = p10 - m;
        if(w >= num * len) {
            ans += num;
            m = p10;
            w -= num * len;
        } else {
            ans += w / len;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
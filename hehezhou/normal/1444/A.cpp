#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll p, q;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &p, &q);
        if (p % q != 0) {
            printf("%lld\n", p);
            continue;
        }
        ll tmp = q, ans = 1;
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                while (tmp % i == 0) tmp /= i;
                ll cur = p;
                while (cur % q == 0) cur /= i;
                ans = max(ans, cur);
            }
        }
        if (tmp != 1) {
            ll cur = p;
            while (cur % q == 0) cur /= tmp;
            ans = max(ans, cur);
        }
        printf("%lld\n", ans);
    }
}
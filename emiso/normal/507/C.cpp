#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, h, cur, ans;

int main() {
    scanf("%lld %lld", &h, &n);
    n--;
    for (int i = h; i > 0; i--) {
        int right = (n & (1LL << (i-1))) != 0;
        if (right == cur) {
            ans++;
            cur = 1 - cur;
        } else {
            ans += (1LL << i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
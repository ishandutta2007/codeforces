#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans1, ans2, l, r;

int main() {
    scanf("%lld %lld %lld", &n, &l, &r);

    for(int i = 1, x = 1; i <= l; i++, x *= 2) {
        ans1 += x;
    }
    ans1 += (n - l);

    for(int i = 1, x = 1; i <= r; i++, x *= 2) {
        ans2 += x;
        if(i == r) ans2 += (n - r) * x;
    }

    printf("%lld %lld\n", ans1, ans2);
    return 0;
}
#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, ans;

int main() {
    scanf("%lld %lld", &n, &k);

    if(k - 1 <= n) {
        printf("%lld\n", (k - 1) / 2);
    } else {
        ll st = k - n;
        if(st >= n) printf("0\n");
        else {
            printf("%lld\n", (n - st + 1) / 2);
        }
    }

    return 0;
}
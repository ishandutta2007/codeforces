#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], can;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n, greater<ll>());

    ll last = -1, sz = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != last) {
            can += sz;
            sz = 1;
            last = a[i];
        } else {
            sz++;
        }

        if(can) {
            ans++;
            can--;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
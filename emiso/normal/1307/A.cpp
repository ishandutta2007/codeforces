#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, d, ans, a[MN];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &d);

        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i < n; i++) {
            while(d >= i && a[i]) {
                d -= i;
                a[0]++;
                a[i]--;
            }
        }

        printf("%lld\n", a[0]);
    }
    return 0;
}
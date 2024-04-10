#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, d, a[MN];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &d);

        ll maxi = 0, ex = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if(a[i] == d) ex = 1;
            maxi = max(maxi, a[i]);
        }

        if(ex) puts("1");
        else {
            if(maxi > d) puts("2");
            else printf("%lld\n", (d + maxi - 1) / maxi);
        }
    }
    return 0;
}
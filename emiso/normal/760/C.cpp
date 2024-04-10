#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], b[MN], sum, cyc;

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        sum += b[i];
    }
    if(sum % 2 == 0) ans++;

    for(int i = 1; i <= n; i++) {
        if(a[i] != 0) {
            cyc++;
            int nxt = a[i];
            a[i] = 0;
            while(nxt != i) {
                int nnxt = a[nxt];
                a[nxt] = 0;
                nxt = nnxt;
            }
        }
    }
    if(cyc > 1) ans += cyc;

    printf("%lld\n", ans);
    return 0;
}
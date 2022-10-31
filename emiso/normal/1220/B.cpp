#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a[1010][1010], ans[1010];

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    ll tmp = a[0][1] * a[0][2] / a[1][2];
    ll sq = round(sqrt(tmp));
    for(ll i = max(sq - 1, 0LL); i <= sq + 1; i++) {
        if(i * i == tmp) {
            ans[0] = i;
            break;
        }
    }
    printf("%lld", ans[0]);

    for(int i = 1; i < n; i++) {
        assert(a[0][i] % ans[0] == 0);
        ans[i] = a[0][i] / ans[0];
        printf(" %lld", ans[i]);
    }

    return 0;
}
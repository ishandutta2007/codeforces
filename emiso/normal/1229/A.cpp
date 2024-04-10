#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], b[MN], mark[MN];
map<ll, ll> f;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    for(int i = 0; i < n; i++) {
        if(f[a[i]] == 1) continue;
        for(int j = 0; j < n; j++) {
            if((a[i] | a[j]) == a[i] && !mark[j]) {
                mark[j] = 1;
                ans += b[j];
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
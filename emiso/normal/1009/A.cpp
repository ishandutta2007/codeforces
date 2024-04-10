#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, a[MN], c[MN], x;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        if(a[x] >= c[i]) {
            ans++;
            x++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
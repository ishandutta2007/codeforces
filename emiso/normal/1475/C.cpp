#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, k, a[MN], b[MN], fa[MN], fb[MN], ans;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld", &n, &m, &k);

    for(int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
        fa[a[i]]++;
    }
    for(int i = 0; i < k; i++) {
        scanf("%lld", &b[i]);
        fb[b[i]]++;
    }

    ans = 0;
    for(int i = 0; i < k; i++) {
        fa[a[i]]--;
        fb[b[i]]--;
        ans += (k-i-1) - fa[a[i]] - fb[b[i]];
    }
    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[55], b[55], ans = LLONG_MAX, cur = LLONG_MIN;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for(int i = 0; i < m; i++) scanf("%lld", &b[i]);

    for(int forbid = 0; forbid < n; forbid++) {
        cur = LLONG_MIN;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(i != forbid)
                    cur = max(cur, a[i] * b[j]);
        ans = min(ans, cur);
    }

    printf("%lld\n", ans);
    return 0;
}
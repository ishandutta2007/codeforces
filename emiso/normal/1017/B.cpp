#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, a[MN], b[MN];
ll ans, q00, q01, q10, q11;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%1d", &b[i]);
        if(!a[i] && !b[i]) q00++;
        if(!a[i] && b[i]) q01++;
        if(a[i] && !b[i]) q10++;
        if(a[i] && b[i]) q11++;
    }

    ans += q00 * (q10 + q11);
    ans += q01 * q10;
    
    printf("%lld\n", ans);
    return 0;
}
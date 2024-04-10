#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], so, se, ao[MN], ae[MN], mbo[MN], mbe[MN], mro[MN], mre[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    so = se = ans = ao[n+1] = ae[n+1] = 0;
    mbo[0] = mbe[0] = mro[n+1] = mre[n+1] = mro[n+2] = mre[n+2] = LLONG_MAX / 2;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if(i & 1) {
            so += a[i];
            ao[i] = ao[i-1] + a[i];
            ae[i] = ae[i-1];

            mbo[i] = min(mbo[i-1], ao[i] - ae[i]);
            mbe[i] = mbe[i-1];
        }
        else {
            se += a[i];
            ao[i] = ao[i-1];
            ae[i] = ae[i-1] + a[i];

            mbe[i] = min(mbe[i-1], ae[i] - ao[i]);
            mbo[i] = mbo[i-1];
        }
    }

    for(int i = n; i >= 1; i--) {
        if(i & 1) {
            mro[i] = min(mro[i+1], ao[i] - ae[i]);
            mre[i] = mre[i+1];
        }
        else {
            mre[i] = min(mre[i+1], ae[i] - ao[i]);
            mro[i] = mro[i+1];
        }
    }

    if(so == se) {
        ans = 1;
        for(int i = 1; ans && i < n; i++) {
            if(a[i] < 0) ans = 0;
            a[i+1] -= a[i];
        }
        if(a[n] != 0) ans = 0;
    } else {
        ll delta = so - se;
        for(int i = 1; !ans && i + 1 <= n; i++) {
            ll nd = 2*(a[i] - a[i+1]) * ((i & 1) ? 1 : -1);
            if(nd != delta) continue;

            if(i & 1) {
                if(mbo[i-1] >= 0 && mbe[i-1] >= 0 && (ao[i] - ae[i]) >= nd/2 /*&& (ae[i+1] - ao[i+1]) >= -nd/2*/ && mre[i+1] >= -nd && mro[i+1] >= nd) ans = 1;
            } else {
                if(mbe[i-1] >= 0 && mbo[i-1] >= 0 && (ae[i] - ao[i]) >= -nd/2 /*&& (ao[i+1] - ae[i+1]) >= nd/2*/ && mre[i+1] >= -nd && mro[i+1] >= nd) ans = 1;
            }
        }
    }

    puts(ans ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}

/**
1 2 1 3  2 1 3 1
1 1 0 3 -1 2 1 0

1 1 2 3  2 1 3 1
1 0 2 1  1 0 3 -2
**/
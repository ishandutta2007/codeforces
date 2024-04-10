#include <bits/stdc++.h>

#define MN 301000

using namespace std;
typedef long long ll;

int x, n;
int a[MN], tmp[MN], v[MN];
ll ans;

ll invcnt(int L, int R) {
    int l = L, r = R;
    if(l >= r) return 0;
    int m = (l + r) / 2;
    ll ret = invcnt(l, m) + invcnt(m + 1, r);

    int j = m + 1, z = 0;
    while(l <= m || j <= r) {
        if(l > m) v[z++] = tmp[j++];
        else if(j > r) v[z++] = tmp[l++];
        else {
            if(tmp[l] <= tmp[j]) v[z++] = tmp[l++];
            else v[z++] = tmp[j++], ret += (m - l + 1);
        }
    }

    for(int i = L, j = 0; i <= R; i++, j++)
        tmp[i] = v[j];

    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int b = 29; b >= 0; b--) {

        for(int i = 1; i <= n; i++)
            tmp[i] = a[i] ^ x;
        ll i1 = invcnt(1, n);

        int m = (1 << b);
        for(int i = 1; i <= n; i++)
            tmp[i] = a[i] ^ x ^ m;
        ll i2 = invcnt(1, n);

        if(i1 <= i2) {
        } else {
            x |= m;
        }
        ans = min(i1, i2);
    }

    printf("%lld %d\n", ans, x);
    return 0;
}
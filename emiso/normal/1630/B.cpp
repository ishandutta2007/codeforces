#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, ans, a[MN], f[MN];

bool ok(int x, int y) {
    return 2*(f[y] - f[x-1]) >= n + k;
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;

    scanf("%lld %lld", &n, &k);
    
    for(int i = 0; i <= n; i++) {
        f[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        f[i] += f[i-1];
    }

    int x = 1, y = n, l = 1;
    for (int r = 1; r <= n; r++) {
        while (ok(l, r)) {
            if (r - l < y - x) {
                x = l;
                y = r;
            }
            l++;
        }
    }

    printf("%lld %lld\n", x, y);
    int cnt = 0, inr = 0, outr = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x && a[i] <= y) inr++;
        else outr++;

        if (cnt + 1 < k && inr > outr) {
            cnt++;
            printf("%d %d\n", last + 1, i + 1);
            inr = outr = 0;
            last = i + 1;
        }
    }
    printf("%d %d\n", last + 1, n);

    if(--t) goto st;
    return 0;
}
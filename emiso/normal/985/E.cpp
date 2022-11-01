#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, k, d, dp[MN], bit[MN], a[MN];

void update(int idx, int delta) {
    if(idx < 1) return;
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += delta;
}

int read(int idx) {
    int ret = 0;
    for(; idx; idx -= (idx & -idx)) ret += bit[idx];
    return ret;
}

int main() {
    scanf("%d %d %d", &n, &k, &d);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    dp[n] = 1;
    update(n, 1);
    for(int i = n-1; i >= 0; i--) {
        int j = i + k;

        if(j > n) {
            dp[i] = 0;
            continue;
        }

        int l = i, r = n - 1, m;
        while(l < r) {
            m = (l + r + 1) / 2;
            if(a[m] - a[i] > d) r = m - 1;
            else l = m;
        }

        if(l + 1 < j) {
            dp[i] = 0;
            continue;
        }
        int cont = read(l + 1) - read(j - 1);
        if(cont > 0) {
            dp[i] = 1;
            update(i, 1);
        }
    }

    printf("%s\n", (dp[0]) ? "YES" : "NO");
    return 0;
}
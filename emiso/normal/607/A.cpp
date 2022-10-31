#include <bits/stdc++.h>

using namespace std;

struct beacon {
    int x, p;

    bool operator <(const beacon &o) const {
        return x > o.x;
    }
} b[100100];

int dp[100100], n;

int solve(int idx) {
    if(idx >= n - 1) return 0;
    if(dp[idx] != -1) return dp[idx];

    int nx = b[idx].x - b[idx].p;
    int l = idx, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if(b[m].x >= nx) l = m + 1;
        else r = m;
    }

    assert(l != idx);

    return dp[idx] = (l - idx - 1) + solve(l);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &b[i].x, &b[i].p);
    }

    sort(b, b + n);
    memset(dp, -1, sizeof dp);

    int ans = 200200;
    for(int i = 0; i < n; i++) {
        ans = min(ans, i + solve(i));
    }

    printf("%d\n", ans);
    return 0;
}
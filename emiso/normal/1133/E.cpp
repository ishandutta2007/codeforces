#include <bits/stdc++.h>

#define MN 5050

using namespace std;
typedef long long ll;

int n, k, ans, a[MN], dp[MN][MN], nxt[MN];

int solve(int pos, int k) {
    if(pos >= n || k == 0) return 0;

    int &x = dp[pos][k];
    if(x != -1) return x;
    return x = max(solve(pos + 1, k), (nxt[pos] - pos) + solve(nxt[pos], k - 1));;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        nxt[i] = i;
    }
    sort(a, a + n);

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(a[j] - a[i] <= 5)
                nxt[i]++;

    printf("%d\n", solve(0, k));
    return 0;
}
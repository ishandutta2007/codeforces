#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, adj[1000100], a, b;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a]++;
        adj[b]++;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += 1LL * adj[i] * (adj[i]-1);
        ans += 1LL * (n - adj[i] - 1) * (n - adj[i] - 2);
        ans -= 1LL * adj[i] * (n - adj[i] - 1);
    }

    printf("%lld\n", ans / 6);
    return 0;
}
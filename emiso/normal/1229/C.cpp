#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 101000

int n, m, q, x, L[MN], R[MN];
ll ans;
vector<int> lo[MN], hi[MN];

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        hi[a].push_back(b); R[a]++;
        L[b]++;
    }

    for(int i = 1; i <= n; i++) {
        ans += 1LL * L[i] * R[i];
    }
    printf("%lld\n", ans);

    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &x);

        ans -= 1LL * L[x] * R[x];
        for(int v : hi[x]) {
            ans -= 1LL * L[v] * R[v];
            L[v]--;
            hi[v].push_back(x); R[v]++;
            ans += 1LL * L[v] * R[v];
        }
        L[x] += R[x];
        R[x] = 0;
        hi[x].clear();

        printf("%lld\n", ans);
    }

    return 0;
}
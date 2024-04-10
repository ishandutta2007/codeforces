#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3010;
int n, a[maxn];
ll f[maxn][maxn], w[maxn], cur[maxn];

int main() {
    scanf("%d", &n);
    vector<ll> V;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), V.push_back(a[i] -= i);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < V.size(); j++) f[i][j] = 1e18;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < V.size(); j++) {
            cur[j] += abs(a[i] - V[j]);
            f[i][j] = w[j] + cur[j];
            if (j) f[i][j] = min(f[i][j], f[i][j - 1]);
            w[j] = min(w[j], f[i][j] - cur[j]);
        }
    }
    printf("%lld\n", *min_element(f[n], f[n] + V.size()));
    return 0;
}
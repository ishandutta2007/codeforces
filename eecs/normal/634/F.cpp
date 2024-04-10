#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int r, c, n, K, a[21];
long long ans;
vector<int> V[maxn];

int main() {
    scanf("%d %d %d %d", &r, &c, &n, &K);
    for (int _ = 0, x, y; _ < n; _++) {
        scanf("%d %d", &x, &y), V[x].push_back(y);
    }
    for (int _ = 1; _ <= r; _++) {
        multiset<int> S;
        long long cur = 0;
        for (int i = _; i <= r; i++) {
            for (int $ : V[i]) {
                auto R = S.insert(a[K] = $), L = R++;
                for (int j = 1; j <= K; j++) {
                    a[K - j] = L == S.begin() ? 0 : *--L;
                    a[K + j] = R == S.end() ? c + 1 : *R++;
                }
                for (int j = 1; j <= K; j++) {
                    cur += (a[K + j] - a[K + j - 1]) * (a[j] - a[j - 1]);
                }
            }
            ans += cur;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
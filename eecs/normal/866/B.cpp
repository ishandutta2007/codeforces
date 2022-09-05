#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, S, s[maxn], a[maxn], b[maxn];

int main() {
    scanf("%d %d", &n, &S);
    vector<array<int, 2>> V;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &s[i], &a[i], &b[i]);
        ans += 1LL * s[i] * a[i];
        V.push_back({b[i] - a[i], s[i]});
    }
    long long all = accumulate(s + 1, s + n + 1, 0LL);
    if (all % S) V.push_back({0, S - int(all % S)});
    sort(V.begin(), V.end(), greater<>());
    long long mx = 0, pre = 0;
    int val = 0;
    for (auto &p : V) {
        if (val + p[1] >= S) mx = max({mx, 1LL * p[0] * (S - val) + pre,
            1LL * p[0] * ((val + p[1]) / S * S - val) + pre});
        pre += 1LL * p[0] * p[1], (val += p[1]) %= S;
    }
    printf("%lld\n", ans + mx);
    return 0;
}
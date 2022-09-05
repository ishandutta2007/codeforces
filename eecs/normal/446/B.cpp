#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1010;
int n, m, K, p;
ll ans = LLONG_MIN, sr[maxn], sc[maxn], vr[maxn * maxn], vc[maxn * maxn];

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1, a; j <= m; j++) {
            scanf("%d", &a);
            sr[i] += a, sc[j] += a;
        }
    }
    priority_queue<ll> Q;
    for (int i = 1; i <= n; i++) {
        Q.push(sr[i]);
    }
    for (int i = 1; i <= K; i++) {
        ll v = Q.top(); Q.pop();
        vr[i] = vr[i - 1] + v, Q.push(v - p * m);
    }
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= m; i++) {
        Q.push(sc[i]);
    }
    for (int i = 1; i <= K; i++) {
        ll v = Q.top(); Q.pop();
        vc[i] = vc[i - 1] + v, Q.push(v - p * n);
    }
    for (int i = 0; i <= K; i++) {
        ans = max(ans, vr[i] + vc[K - i] - 1LL * i * (K - i) * p);
    }
    printf("%lld\n", ans);
    return 0;
}
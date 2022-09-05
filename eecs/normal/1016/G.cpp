#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, cnt1[1 << 20], cnt2[1 << 20];
ll X, Y, ans, a[maxn], b[maxn], c[maxn];

int main() {
    scanf("%d %lld %lld", &n, &X, &Y);
    if (Y % X) puts("0"), exit(0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) if (!(Y % a[i])) {
        b[i] = __gcd(Y / a[i], Y / X);
    }
    for (int i = 1; i <= n; i++) if (!(a[i] % X)) {
        c[i] = __gcd(a[i] / X, Y / X);
    }
    ll m = Y / X;
    vector<ll> pr;
    for (int i = 2; i <= 1000000; i++) if (!(m % i)) {
        pr.push_back(i);
        while (!(m % i)) m /= i;
    }
    if (m > 1) {
        ll t = max(0LL, (ll)sqrt(m) - 10);
        while ((t + 1) * (t + 1) <= m) t++;
        if (t * t == m) {
            pr.push_back(t);
        } else {
            for (int i = 1; i <= n; i++) if (b[i]) {
                ll z = __gcd(b[i], m);
                if (z > 1 && z < m) {
                    pr.push_back(z);
                    while (!(m % z)) m /= z;
                }
            }
            for (int i = 1; i <= n; i++) if (c[i]) {
                ll z = __gcd(c[i], m);
                if (z > 1 && z < m) {
                    pr.push_back(z);
                    while (!(m % z)) m /= z;
                }
            }
            if (m > 1) pr.push_back(m);
        }
    }
    for (int i = 1; i <= n; i++) if (b[i]) {
        int mask = 0;
        for (int j = 0; j < pr.size(); j++) {
            if (!(b[i] % pr[j])) mask |= 1 << j;
        }
        cnt1[mask]++;
    }
    for (int i = 1; i <= n; i++) if (c[i]) {
        int mask = 0;
        for (int j = 0; j < pr.size(); j++) {
            if (!(c[i] % pr[j])) mask |= 1 << j;
        }
        cnt2[mask]++;
    }
    for (int i = 0; i < pr.size(); i++) {
        for (int j = 0; j < 1 << pr.size(); j++) if (j >> i & 1) {
            cnt1[j ^ (1 << i)] += cnt1[j];
            cnt2[j ^ (1 << i)] += cnt2[j];
        }
    }
    for (int i = 0; i < 1 << pr.size(); i++) {
        ans += 1LL * (__builtin_popcount(i) & 1 ? -1 : 1) * cnt1[i] * cnt2[i];
    }
    printf("%lld\n", ans);
    return 0;
}
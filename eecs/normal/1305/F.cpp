#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, cnt;
ll a[maxn];
mt19937 rnd(time(0));

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) ans++;
        if (a[i] == 1) cnt++, i--, n--;
    }
    if (!n) printf("%d\n", ans), exit(0);
    auto chk = [&](ll g) {
        static unordered_set<ll> S;
        if (S.count(g)) return;
        S.insert(g);
        ll num = cnt * (g - 1);
        for (int i = 1; i <= n && num < ans; i++) if (a[i] % g) {
            if (a[i] < g) num += g - a[i] % g;
            else num += min(a[i] % g, g - a[i] % g);
        }
        if (num < ans) ans = num;
    };
    auto test = [&](ll x) {
        for (ll i = 2; i * i <= x; i++) if (!(x % i)) {
            chk(i);
            while (!(x % i)) x /= i;
        }
        if (x > 1) chk(x);
    };
    for (int $ = 0; $ < 20; $++) {
        int x = rnd() % n + 1;
        for (int p : {-1, 0, 1}) test(a[x] + p);
    }
    printf("%d\n", ans);
    return 0;
}
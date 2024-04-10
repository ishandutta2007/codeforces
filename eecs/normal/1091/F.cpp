#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, pre[maxn];
ll ans, a[maxn];
char s[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%s", s + 1);
    set<int> G, W;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] | (s[i] == 'W');
        if (s[i] == 'G') G.insert(i);
        if (s[i] == 'W') W.insert(i);
    }
    for (int i = 1; i <= n; i++) if (s[i] == 'L') {
        ans += a[i];
        while (a[i] && !W.empty()) {
            auto it = W.lower_bound(i);
            if (it == W.begin()) break;
            ll t = min(a[i], a[*--it]);
            ans += 3 * t;
            a[i] -= t, a[*it] -= t;
            if (!a[*it]) W.erase(it);
        }
        while (a[i] && !G.empty()) {
            auto it = G.lower_bound(i);
            if (it == G.begin()) break;
            ll t = min(a[i], a[*--it]);
            ans += 5 * t;
            a[i] -= t, a[*it] -= t;
            if (!a[*it]) G.erase(it);
        }
        if (pre[i]) ans += 3 * a[i];
        else ans += 5 * a[i];
    }
    for (int i = 1; i <= n; i++) if (s[i] == 'G') {
        while (a[i] && !W.empty()) {
            auto it = W.lower_bound(i);
            if (it == W.begin()) break;
            ll t = min(a[i], a[*--it]);
            ans += 4 * t;
            a[i] -= t, a[*it] -= t;
            if (!a[*it]) W.erase(it);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'G') ans += 3 * a[i];
        else if (s[i] == 'W') ans += 2 * a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
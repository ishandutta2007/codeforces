#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p, k;
int h[100010], a[100010];
int need[5010];
inline int check(ll ans) {
    ll sum = 0;
    for(int i = 1; i <= n; i++) sum += (max(0ll, 1ll * a[i] * m + h[i] - ans) + p - 1) / p;
    if(sum > m * k) return 0;
    for(int i = 1; i <= m; i++) need[i] = 0;
    for(int i = 1; i <= n; i++) {
        if(1ll * a[i] * m + h[i] - ans <= 0) continue; 
        ll now = h[i], d = 1, hei = (1ll * a[i] * m + h[i] - ans) % p;
        if(hei == 0) hei = p;
        for(int j = 1, end = (max(0ll, 1ll * a[i] * m + h[i] - ans) + p - 1) / p; j <= end; j++) {
            if(now < hei) {
                int delta = (hei - now + a[i] - 1) / a[i];
                d += delta;
                now += 1ll * d * a[i];
            }
            now -= hei;
            hei = p;
            if(d > m) return 0;
            need[d]++;
        }
    }
    int rest = 0;
    for(int i = 1; i <= m; i++) {
        rest += need[i];
        rest = max(rest - k, 0);
    } 
    return !rest;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for(int i = 1; i <= n; i++) scanf("%d%d", h + i, a + i);
    ll l = 0, r = 5e13, ans;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    return cout << ans << endl, 0;
}
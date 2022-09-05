#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll x1, y1_2, x2, y2;
char s[100010];

ll chk(ll x) {
    ll dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') dy++;
        if (s[i] == 'D') dy--;
        if (s[i] == 'L') dx--;
        if (s[i] == 'R') dx++;
    }
    ll y = x / n;
    dx *= y, dy *= y;
    for (int i = 0; i < x % n; i++) {
        if (s[i] == 'U') dy++;
        if (s[i] == 'D') dy--;
        if (s[i] == 'L') dx--;
        if (s[i] == 'R') dx++;
    }
    return abs(x2 - x1 - dx) + abs(y2 - y1_2 - dy) <= x;
}

int main() {
    scanf("%lld %lld %lld %lld %d %s", &x1, &y1_2, &x2, &y2, &n, s);
    ll l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
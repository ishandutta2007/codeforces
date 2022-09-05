#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int n;
ll C, a[maxn], d[maxn], ans[maxn];
set<ll> S;

int main() {
    scanf("%d %lld", &n, &C);
    ll tagk = 1, tagb = 0, lb = 0, rb = C;
    for (int i = 1; i <= n - 2; i++) {
        scanf("%lld", &a[i]);
        ll l = -tagk * tagb, r = tagk * (a[i] - tagb), o = r;
        if (l > r) swap(l, r);
        lb = max(lb, l), rb = min(rb, r);
        while (!S.empty() && *S.begin() < l) S.erase(S.begin());
        while (!S.empty() && *S.rbegin() > r) S.erase(*S.rbegin());
        if (S.empty() && lb > rb) puts("NO"), exit(0);
        if (S.count(o) || lb <= o && o <= rb) {
            lb = 0, rb = ans[i] = a[i], S.clear();
            tagk = 1, tagb = 0; continue;
        }
        if (lb <= rb) ans[i] = tagk * lb + tagb;
        else ans[i] = tagk * *S.begin() + tagb;
        tagk *= -1, tagb = a[i] - tagb;
        S.insert(tagk * (a[i] - tagb));
    }
    if (lb <= rb) d[n - 1] = tagk * lb + tagb;
    else d[n - 1] = tagk * *S.begin() + tagb;
    for (int i = n - 2; i; i--) {
        if (ans[i] == a[i]) d[i] = a[i];
        else d[i] = d[i + 1] == a[i] ? ans[i] : a[i] - d[i + 1];
    }
    for (int i = n - 2, x = 1; i; i--) {
        if (abs(d[i]) + abs(d[i + 1]) != a[i]) x *= -1;
        d[i] *= x;
    }
    for (int i = 1; i < n; i++) {
        d[i] += d[i - 1];
    }
    puts("YES");
    ll mn = *min_element(d, d + n);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", d[i - 1] - mn);
    }
    return 0;
}
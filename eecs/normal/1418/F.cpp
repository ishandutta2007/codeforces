#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m;
ll L, R;
vector<int> d[maxn];

int main() {
    scanf("%d %d %lld %lld", &n, &m, &L, &R);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) d[j].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        ll lb = (L + i - 1) / i, rb = min(1LL * m, R / i);
        if (lb > rb) { puts("-1"); continue; }
        lb--;
        bool flag = 0;
        for (int j : d[i]) {
            int l = i / j + 1, r = n / j;
            if (r > lb) {
                ll x = max(1LL * l, lb + 1);
                if (x <= min(1LL * r, rb)) {
                    printf("%d %lld %d %lld\n", i, x, j * x, i * x / j / x);
                    flag = 1; break;
                }
                r = lb;
            }
            if (l > r) continue;
            for (int p = l, q; p <= lb; p = q + 1) {
                q = lb / (lb / p);
                if (p > min(r, q)) continue;
                ll x = (lb / p + 1) * p;
                if (x <= rb) {
                    printf("%d %lld %d %lld\n", i, x, j * p, i * x / j / p);
                    flag = 1; break;
                }
            }
            if (flag) break;
        }
        if (!flag) puts("-1");
    }
    return 0;
}
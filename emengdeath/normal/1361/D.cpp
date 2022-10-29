#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e6;
vector<pair<pair<int, int>, long double> > f;
int n, k;
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (!x) {
            if (!y) continue;
            f.push_back({{0, y / abs(y)}, sqrtl(1ll * x *x + 1ll *y * y)});
        } else {
            if (!y) {
                f.push_back({{x / abs(x), 0}, sqrtl(1ll *x * x +1ll * y * y)});
            } else {
                int v = __gcd(abs(x), abs(y));
                f.push_back({{x / v , y / v}, sqrtl(1ll *x * x +1ll * y * y)});
            }
        }
    }
    sort(f.begin(), f.end());
    int l = 0;
    long double ans = 0;
    long double ans1 = 0;
    vector<long double> w;
    w.push_back(0);
    while (l < f.size()) {
        int r = l;
        while (r + 1 < f.size() && f[r + 1].first == f[l].first) ++ r;
        vector<long double> d, dd;
        for (int i = l ; i <= r; i ++)
            d.push_back(f[i].second), dd.push_back((i - l) * f[i].second);
        if (d.size() >= k) {
            vector<long double> ww;
            for (int j = 0; j < k / 2; j ++)
                ww.push_back(d[j]);
            for (int j = (k + 1) / 2; j >= 1; j--)
                ww.push_back(d[d.size() - j]);
            long double v1 = 0, v2 = 0;
            for (int i = 0; i < k; i ++)
            {
                if (i)
                    v1 += (ww[i] * (i - 1) - v2);
                v2 += ww[i];
            }
            ans1 = max(ans1, v1);
        }
        for (int i = 1; i < d.size(); i ++)
            d[i] += d[i - 1], dd[i] += dd[i - 1];

        vector<long double> v;
        for (int i = 1; i <= d.size() && i < k; i ++) {
            int x = k - i;
            int y;
            if (x < i) {
                y = x + (i - x) / 2;
            } else {
                y = i;
            }
            long double lv = 0, rv = 0, llv = 0, rrv = 0;
            if (i - y)
                lv = d[i - y - 1], llv = dd[i - y - 1];
            if (y == d.size())
                rv = d[d.size() - 1], rrv = dd[dd.size() - 1];
            else
                rv = d[d.size() - 1] - d[d.size() - y - 1], rrv = dd[dd.size() - 1] - dd[dd.size() - y - 1] - (dd.size() - y - (i - y)) * rv;
            v.push_back((lv + rv) * x + (llv + rrv) * 2 - (lv + rv) * (i - 1));
        }
        w.push_back(v[0]);
        for (int i = 1; i < v.size(); i ++)
            w.push_back(v[i] - v[i - 1]);
        l = r + 1;
    }
    sort(w.rbegin(), w.rend());
    for (int i = 0; i < k; i ++)
        ans += w[i];
    printf("%.10Lf\n", max(ans, ans1));
    return 0;
}
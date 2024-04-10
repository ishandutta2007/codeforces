#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, a[maxn], cnt[maxn], lst[maxn], fir[maxn], sec[maxn], _fir[maxn], _sec[maxn];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), cnt[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < maxn; i++) {
        lst[i] = cnt[i] ? i : lst[i - 1];
        cnt[i] += cnt[i - 1];
    }
    for (int y = 2; y < maxn; y++) {
        long long num = 0;
        for (int i = 0; i < maxn; i += y) {
            num += 1LL * i / y * (cnt[min(maxn, i + y) - 1] - cnt[i - 1]);
            fir[i] = lst[min(maxn, i + y) - 1];
            if (fir[i] < i) { fir[i] = sec[i] = 0; continue; }
            sec[i] = cnt[fir[i]] - cnt[fir[i] - 1] > 1 ? fir[i] : lst[fir[i] - 1];
            if (sec[i] < i) sec[i] = 0;
        }
        for (int i = 0; i < maxn; i += y) {
            _fir[i] = fir[i], _sec[i] = sec[i];
        }
        auto comp = [&](int p, int q) { return !q || p % y > q % y; };
        for (int i = (maxn - 1) / y * y - y; i >= 0; i -= y) {
            if (comp(fir[i + y], fir[i])) sec[i] = fir[i], fir[i] = fir[i + y];
            else if (comp(fir[i + y], sec[i])) sec[i] = fir[i + y];
            if (comp(sec[i + y], fir[i])) sec[i] = fir[i], fir[i] = sec[i + y];
            else if (comp(sec[i + y], sec[i])) sec[i] = sec[i + y];
        }
        auto chk = [&](int x) {
            int ans1 = 0, ans2 = 0;
            auto chk = [&](int val) {
                if (val < x) return;
                if (comp(val, ans1)) ans2 = ans1, ans1 = val;
                else if (comp(val, ans2)) ans2 = val;
            };
            int t = (x + y - 1) / y * y;
            if (t < maxn) chk(fir[t]), chk(sec[t]);
            t -= y;
            if (t >= 0 && t < maxn) chk(_fir[t]), chk(_sec[t]);
            if (ans2 >= x && ans1 / y + ans2 / y - (ans1 - x) / y - (ans2 - x) / y <= num - x) {
                ans = max(ans, 1LL * x * y); return 1;
            }
            // single
            ans1 = 0;
            auto chk2 = [&](int val) {
                ans1 = max(ans1, val);
            };
            t = (2 * x + y - 1) / y * y;
            if (t < maxn) chk2(fir[t]);
            t -= y;
            if (t >= 0 && t < maxn) chk2(_fir[t]);
            if (ans1 >= 2 * x && ans1 / y - (ans1 - 2 * x) / y <= num - x) {
                ans = max(ans, 1LL * x * y); return 1;
            }
            return 0;
        };
        int l = 2, r = min(1LL * a[n], num);
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? l = mid + 1 : r = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
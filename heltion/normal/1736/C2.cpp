#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i += 1)
        vp.emplace_back(a[i] - i, i);
    ranges::sort(vp);
    set<int> s = {n + 1, n + 2};
    vector<int> one(n + 1), two(n + 1);
    vector<LL> sum_one(n + 1), sum_two(n + 1);
    for (int i = n, j = 0; i >= 1; i -= 1) {
        while (j < n and vp[j].first <= -i)
            s.insert(vp[j ++].second);
        one[i] = *s.lower_bound(i);
        two[i] = *next(s.lower_bound(i));
    }
    for (int i = 1; i <= n; i += 1) {
        sum_one[i] = sum_one[i - 1] + one[i];
        sum_two[i] = sum_two[i - 1] + two[i];
    }
    vector<int> L(n + 3, -1), R(n + 3, -1);
    for (int i = 1; i <= n; i += 1) {
        R[one[i]] = i;
        if (L[one[i]] == -1)
            L[one[i]] = i;
    }
    int q;
    cin >> q;
    for (int qi = 0, p, x; qi < q; qi += 1) {
        cin >> p >> x;
        LL res = sum_one[n] - (LL)(1 + n) * n / 2;
        if (a[p] > x) {
            int k = p - x;
            if (k >= 1 and one[k] > p) {
                int L = 1, R = k;
                while (L < R) {
                    int M = (L + R) >> 1;
                    if (one[M] > p) R = M;
                    else L = M + 1;
                }
                res -= sum_one[k] - sum_one[L - 1];
                res += (LL)p * (k - L + 1);
            }
        }
        if (a[p] < x and L[p] != -1) {
            int k = max(p - x + 1, 1);
            int l = max(L[p], k), r = R[p];
            if (l <= r) {
                res += sum_two[r] - sum_two[l - 1];
                res -= sum_one[r] - sum_one[l - 1];
            }
        }
        cout << res << "\n";
    }
}
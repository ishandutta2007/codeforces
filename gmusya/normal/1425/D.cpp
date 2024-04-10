#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(int i = 0; i < n; ++i)
#define ar array

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int INFi = 2e9;
const int md = 1e9 + 7;

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 1e6 + 1;
int fact[maxF], invfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(i, fact[i - 1]);
    invfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 2; i >= 1; --i) invfact[i] = mul(invfact[i + 1], i + 1);
    invfact[0] = 1;
}

int C(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void solve() {
    init();
    int n, m, r;
    cin >> n >> m >> r;
    int d = 1001;
    vector<vector<int>> a(d, vector<int>(d, 0));
    vector<ar<int, 3>> z(n);
    range(i, n) {
        range(j, 3) cin >> z[i][j];
        a[z[i][0]][z[i][1]] = 1;
    }
    range(i, d) {
        range(j, d) {
            if (i) a[i][j] += a[i - 1][j];
            if (j) a[i][j] += a[i][j - 1];
            if (i && j) a[i][j] -= a[i - 1][j - 1];
        }
    }
    auto get = [&](int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return 0;
        y2 = min(y2, d - 1);
        x2 = min(x2, d - 1);
        x1 = max(x1, 1);
        y1 = max(y1, 1);
        return a[x2][y2] + a[x1 - 1][y1 - 1] - a[x1-1][y2] - a[x2][y1-1];
    };
    int ans = 0;
    for (auto &[x, y, b]: z) {
        int x1 = x - r, y1 = y - r, x2 = x + r, y2 = y + r;
        int cnt = n - get(x1, y1, x2, y2);
        int s = mul(mul(b, b), sub(C(n, m), C(cnt, m)));
        ans = add(ans, s);
    }
    for (auto &[x2, y2, b2]: z) {
        for (auto &[x1, y1, b1]: z) {
            if (x1 == x2 && y1 == y2) continue;
            int bb = mul(b1, b2);
            //cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
            int cnt1 = get(x1-r, y1-r, x1+r, y1+r);
            int cnt2 = get(x2-r, y2-r, x2+r, y2+r);
            int cnt3 = get(max(x1-r, x2-r), max(y1-r, y2-r), min(x1+r, x2+r), min(y1+r, y2+r));
            //cout << cnt1 << " " << cnt2 << " " << cnt3 << "\n";
            int no_one_or_two = C(n-(cnt1+cnt2-cnt3), m); // 0
            int no_one_with_two = sub(C(n-cnt1, m), no_one_or_two); //
            int no_two_with_one = sub(C(n-cnt2, m), no_one_or_two);
            int res = sub(sub(C(n, m), no_one_or_two), add(no_one_with_two, no_two_with_one));
            //cout << res << "\n";
            //cout << bb << "\n";
            ans = add(ans, mul(res, bb));
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
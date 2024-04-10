#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(time(0));

int md;
const int Mx = 100 * 100 + 7;
const int N = 107;

int fact[N];
int rfact[N];

bool prime(int x) {
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) return false;
    }
    return true;
}

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int power(int a, ll b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, md - 2);
}

int C(int n, int k) {
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    md = 5e8 + (rnd() % (int)5e8);
    while (!prime(md)) --md;
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
    for (int i = 0; i < N; ++i) rfact[i] = inv(fact[i]);
    int n;
    cin >> n;
    int sum = 0;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    vector <vector <int>> dp(n + 1, vector <int> (Mx));
    vector <vector <int>> ndp(n + 1, vector <int> (Mx));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < Mx; ++k) {
                ndp[j][k] = dp[j][k];
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k + a[i] < Mx; ++k) {
                add(ndp[j + 1][k + a[i]], dp[j][k]);
            }
        }
        swap(ndp, dp);
    }
    vector <int> cnt(101);
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
        if (cnt[a[i]] == 1) ++diff;
    }
    if (diff <= 2) {
        cout << n << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= cnt[i]; ++j) {
            int need = i * j;
            int cur = dp[j][need];
            int have = C(cnt[i], j);
            if (have == cur) ans = max(ans, j);
            int other = dp[n - j][sum - need];
            int other_have = C(cnt[i], cnt[i] - j);
            if (other == other_have) ans = max(ans, j);
        }
    }
    cout << ans << '\n';
}
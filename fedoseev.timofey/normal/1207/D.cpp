#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

void add(int &a, int b) {
    a += b;
    a %= md;
    a += md;
    a %= md;
}

vector <int> fac;

int n;

int cnt(vector <int> a) {
    vector <int> c = a;
    sort(c.begin(), c.end());
    int res = 1;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (c[i] == c[i - 1]) ++cnt;
        else {
            res = mul(res, fac[cnt]);
            cnt = 1;
        }
    }
    res = mul(res, fac[cnt]);
    return res;
}

int cnt(vector <int> a, vector <int> b) {
    vector <pair <int, int>> c;
    for (int i = 0; i < n; ++i) c.push_back({a[i], b[i]});
    sort(c.begin(), c.end());
    bool fl = true;
    for (int i = 1; i < n; ++i) {
        fl &= (c[i].first >= c[i - 1].first) && (c[i].second >= c[i - 1].second);
    }
    if (!fl) return 0;
    int res = 1;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (c[i] == c[i - 1]) ++cnt;
        else {
            res = mul(res, fac[cnt]);
            cnt = 1;
        }
    }
    res = mul(res, fac[cnt]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int ans = fac[n];
    add(ans, -cnt(a) + md);
    add(ans, -cnt(b) + md);
    add(ans, cnt(a, b));
    cout << ans << '\n';
}
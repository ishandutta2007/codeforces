#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll cnt(vector <int> a, vector <int> b) {
    ll res = 0;
    for (int i = 0; i < (int)a.size(); ++i) res += max(a[i] + 1, b[i] + 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; ll k;
    cin >> n >> k;
    if ((ll)n * (n + 1) / 2 > k) {
        cout << "-1\n";
        return 0;
    }
    vector <int> a(n), b(n);
    iota(a.begin(), a.end(), 0);
    iota(b.begin(), b.end(), 0);
    reverse(b.begin(), b.end());
    k = min(k, cnt(a, b));
    reverse(b.begin(), b.end());
    k -= cnt(a, b);
    int shift = 0; ll cur = 0;
    while (true) {
        int st = shift;
        int ed = n - shift - 1;
        if (cur + ed - st >= k) {
            rotate(b.begin(), b.begin() + shift, b.end());
            swap(b[0], b[st + k - cur]);
            break;
        }
        cur += ed - st;
        ++shift;
    }
    cout << cnt(a, b) << '\n';
    for (int i = 0; i < n; ++i) cout << a[i] + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i) cout << b[i] + 1 << ' ';
}
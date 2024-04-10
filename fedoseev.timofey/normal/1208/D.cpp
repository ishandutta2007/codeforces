#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

ll f[N];

void modify(int x, ll y) {
    for (int i = x; i < N; i |= i + 1) f[i] += y;
}

ll sum(int r) {
    ll res = 0;
    for (; r >= 0; r &= r + 1, --r) res += f[r];
    return res; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <ll> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) {
        modify(i, i);
    }
    vector <int> p(n);
    for (int i = n - 1; i >= 0; --i) {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (sum(m) <= s[i]) l = m;
            else r = m;
        }
        p[i] = l + 1;
        modify(p[i], -p[i]);
    }
    for (int i = 0; i < n; ++i) cout << p[i] << ' ';
}
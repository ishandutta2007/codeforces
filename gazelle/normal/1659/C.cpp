#include <bits/stdc++.h>
#define FOR(i, n, m) for (long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if (i) os << " ";
        os << v[i];
    }
    return os;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i, t) {
        int n;
        ll a, b;
        cin >> n >> a >> b;
        vector<int> x(n + 1);
        x[0] = 0;
        REP(i, n) cin >> x[i + 1];

        vector<ll> v1(n + 1, 0), v2(n + 1, 0);
        FOR(i, 1, n + 1) { v1[i] = v1[i - 1] + (a + b) * (x[i] - x[i - 1]); }
        for (int i = n - 1; i >= 0; i--) {
            v2[i] = v2[i + 1] + b * (n - i) * (x[i + 1] - x[i]);
        }

        ll ans = inf * inf;
        REP(i, n + 1) ans = min(ans, v1[i] + v2[i]);
        cout << ans << endl;
    }
    return 0;
}
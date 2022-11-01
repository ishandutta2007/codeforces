#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
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
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if(i)
            os << " ";
        os << v[i];
    }
    return os;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(testcase, t) {
        int n;
        cin >> n;
        vector<ll> a(n);
        REP(i, n) cin >> a[i];
        int cnt = 0;
        REP(i, n) {
            while(a[i] % 2 == 0) {
                cnt += 1;
                a[i] /= 2;
            }
        }
        ll mx = 0;
        REP(i, n) mx = max(mx, a[i]);
        ll ans = 0;
        REP(i, n) {
            if(mx == a[i]) {
                REP(j, cnt)
                a[i] *= 2;
                mx = 1000;
            }
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
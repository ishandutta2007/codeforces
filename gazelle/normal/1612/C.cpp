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

ll inc_sum(ll a, ll b) { return (a + b) * (b - a + 1) / 2; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    REP(testcase, t) {
        ll k, x;
        cin >> k >> x;

        ll ok = 1, ng = 2 * k;

        while(ng - ok > 1) {
            ll mid = (ok + ng) / 2;

            ll sum = 0;
            if(mid - 1 <= k) {
                sum = inc_sum(1, mid - 1);
            } else {
                sum = inc_sum(1, k);
                sum += inc_sum(2 * k - (mid - 1), k - 1);
            }
            if(sum < x)
                ok = mid;
            else
                ng = mid;
        }

        cout << ok << "\n";
    }

    return 0;
}
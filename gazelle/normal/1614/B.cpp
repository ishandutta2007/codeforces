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
        vector<pair<int, int>> a(n);
        REP(i, n) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(ALL(a), greater<pair<int, int>>());
        ll num_ans = 0;
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        ll pos = 1;
        for(auto [c, i] : a) {
            num_ans += abs(pos) * c;
            ans[i + 1] = pos;
            if(pos < 0)
                pos = abs(pos) + 1;
            else
                pos = -pos;
        }
        cout << 2 * num_ans << "\n";
        cout << ans << "\n";
    }

    return 0;
}
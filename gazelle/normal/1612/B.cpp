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
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> rems;
        for(int i = 1; i <= n; i++) {
            if(i != a && i != b)
                rems.pb(i);
        }
        vector<int> left, right;
        left.pb(a);
        right.pb(b);
        REP(i, n / 2 - 1) { left.pb(rems[n - 3 - i]); }
        REP(i, n / 2 - 1) { right.pb(rems[i]); }

        int min_left = left[0], max_right = right[0];
        REP(i, n / 2) {
            min_left = min(min_left, left[i]);
            max_right = max(max_right, right[i]);
        }

        if(min_left == a && max_right == b)
            cout << left << " " << right << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}
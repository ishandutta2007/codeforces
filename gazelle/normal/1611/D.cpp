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

        vector<int> anc(n, -1);
        int r = -1;

        REP(i, n) {
            int a;
            cin >> a;
            if(a == i + 1) {
                r = i;
                continue;
            }
            anc[i] = a - 1;
        }

        vector<int> p(n), rev_p(n);
        REP(i, n) {
            cin >> p[i];
            p[i] -= 1;
            rev_p[p[i]] = i;
        }

        vector<int> ans(n, 0);

        REP(i, n) {
            if(i == r)
                continue;
            if(rev_p[i] < rev_p[anc[i]])
                continue;
            ans[i] = rev_p[i] - rev_p[anc[i]];
        }

        if(count(ALL(ans), 0) != 1)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}
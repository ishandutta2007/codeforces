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
        int n, k;
        cin >> n >> k;
        int K = k;
        string s;
        cin >> s;
        string ans = "";
        vector<int> c(n, 0);
        REP(i, n) {
            if (i == n - 1 && k > 0) {
                c[i] += k;
                k = 0;
            } else if (K % 2 == 1 && s[i] == '1' && k > 0) {
                c[i] += 1;
                k -= 1;
            } else if (K % 2 == 0 && s[i] == '0' && k > 0) {
                c[i] += 1;
                k -= 1;
            }
        }
        REP(i, n) {
            if (s[i] == '0') {
                if ((K + c[i]) % 2 == 0)
                    ans += '0';
                else
                    ans += '1';
            } else {
                if ((K + c[i]) % 2 == 0)
                    ans += '1';
                else
                    ans += '0';
            }
        }
        cout << ans << endl;
        cout << c << endl;
    }
    return 0;
}
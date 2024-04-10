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

bool palindrome(const vector<int> &a) {
    int n = (int)a.size();

    bool ok = true;

    REP(i, n) {
        if(a[i] != a[n - 1 - i])
            ok = false;
    }

    return ok;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    REP(testcase, t) {
        int n;
        cin >> n;

        vector<int> a(n);
        REP(i, n) cin >> a[i];

        bool ok = false;

        if(palindrome(a))
            ok = true;

        REP(i, n) {
            if(a[i] != a[n - 1 - i]) {
                int x = a[i], y = a[n - 1 - i];
                vector<int> b, c;
                REP(i, n) {
                    if(a[i] != x)
                        b.pb(a[i]);
                    if(a[i] != y)
                        c.pb(a[i]);
                }
                if(palindrome(b) || palindrome(c))
                    ok = true;
                break;
            }
        }

        if(ok)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }

    return 0;
}
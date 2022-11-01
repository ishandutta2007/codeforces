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
        string n;
        cin >> n;

        vector<int> evens;

        REP(i, n.size()) {
            if((n[i] - '0') % 2 == 0)
                evens.pb(i);
        }

        if(evens.empty())
            cout << -1 << "\n";
        else if(evens.back() == (int)n.size() - 1)
            cout << 0 << "\n";
        else if(evens.front() == 0)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
    return 0;
}
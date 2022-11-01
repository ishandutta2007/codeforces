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
        string s;
        cin >> s;
        if(n == 1 || s[0] == s[1]) {
            cout << s[0] << s[0] << "\n";
            continue;
        }
        string ans = "";
        REP(i, n) {
            ans += s[i];
            if(i == n - 1 || s[i] < s[i + 1]) {
                for(int j = i; j >= 0; j--)
                    ans += s[j];
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
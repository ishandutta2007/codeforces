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
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        int x;
        cin >> x;

        if(n == 1) {
            cout << 1 << "\n";
            continue;
        }

        REP(i, n) a[i] = a[i] - x;
        vector<vector<int>> dp(n, vector<int>(4, -inf));
        dp[1][0] = 0;
        dp[1][1] = dp[1][2] = 1;
        if(a[0] + a[1] >= 0)
            dp[1][3] = 2;
        for(int i = 2; i < n; i++) {
            for(int bit = 0; bit <= 3; bit++) {
                for(int p_bit = 0; p_bit <= 3; p_bit++) {
                    if(((p_bit >> 1) & 1) != (bit & 1))
                        continue;
                    if((bit & 2) && (bit & 1) && a[i] + a[i - 1] < 0)
                        continue;
                    if((bit & 2) && (bit & 1) && (p_bit & 1) &&
                       a[i] + a[i - 1] + a[i - 2] < 0)
                        continue;
                    if(bit & 2)
                        dp[i][bit] = max(dp[i][bit], dp[i - 1][p_bit] + 1);
                    else
                        dp[i][bit] = max(dp[i][bit], dp[i - 1][p_bit]);
                }
            }
        }

        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]})
             << "\n";
    }
    return 0;
}
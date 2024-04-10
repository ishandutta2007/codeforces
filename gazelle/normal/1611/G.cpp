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

int lis(vector<vector<int>> v) {
    int n = (int)v.size();
    vector<int> dp(n + 1, 1e9);
    dp[0] = -1e9;

    REP(i, n) {
        sort(ALL(v[i]));
        reverse(ALL(v[i]));
        for(auto e: v[i]) {
            auto iter = lower_bound(ALL(dp), e);
            if(iter == dp.end())
                continue;
            if((*iter) > e)
                (*iter) = e;
        }
    }

    int ret = 0;
    REP(i, n + 1) {
        if(dp[i] < 1e9 - 1)
            ret = i;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    REP(testcase, t) {
        int n, m;
        cin >> n >> m;

        vector<string> g(n);
        REP(i, n) cin >> g[i];

        vector<vector<int>> v1(n + m), v2(n + m);

        REP(i, n) REP(j, m) {
            if(g[i][j] == '0')
                continue;
            if((i + j) % 2 == 0) {
                v1[i + j].pb(j - i);
            } else {
                v2[i + j].pb(j - i);
            }
        }

        cout << lis(v1) + lis(v2) << endl;
    }

    return 0;
}
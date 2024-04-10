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

        set<int> st;
        map<int, int> mp;

        REP(i, n) {
            st.insert(a[i]);
            mp[a[i]] += 1;
        }

        int ans = 0;
        set<int> used_diff;

        REP(i, n - 1) {
            if(used_diff.count(a[i + 1] - a[i]) > 0)
                continue;
            int cnt = mp[a[i]];
            st.erase(a[i]);
            int crt = a[i];
            while(true) {
                auto iter = st.lower_bound(2 * crt - a[i]);
                if(iter == st.end())
                    break;
                crt = (*iter);
                cnt += 1;
            }
            st.insert(a[i]);
            ans = max(ans, cnt);
        }

        cout << n - ans << "\n";
    }

    return 0;
}
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

    vector<bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;
    FOR(i, 2, 1000001) {
        for(int j = 2; i * j <= 1000000; j++)
            is_prime[i * j] = false;
    }

    int t;
    cin >> t;
    REP(testcase, t) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<pair<pair<int, int>, pair<int, int>>> lasts(e, {{n, 0}, {n, 0}});
        ll ans = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(a[i] != 1) {
                lasts[i % e].second = lasts[i % e].first;
                lasts[i % e].first = {i, 0};
                if(is_prime[a[i]])
                    lasts[i % e].first.second = 1;
            }
            if(lasts[i % e].first.second == 1) {
                //cout << i << " " << lasts[i % e].first.first << " "
                    // << lasts[i % e].second.first << endl;
                ans +=
                    (lasts[i % e].second.first - lasts[i % e].first.first - 1) /
                        e +
                    1;
                if(lasts[i % e].first.first == i)
                    ans -= 1;
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
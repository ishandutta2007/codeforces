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

int f(int mask, int lb) {
    for(int i = 21; i >= 0; i--) {
        if(mask >= lb) {
            break;
        }
        if(lb & (1 << i) && not (mask & (1 << i))) {
            mask += (1 << i);
        }
    }
    return mask;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i, t) {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        for(int mask = 0; mask <= 2 * b; mask++) {
            int a_ = f(mask, a), b_ = f(mask, b);
            ans = min(ans, a_ - a + b_ - b + a_ - mask + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
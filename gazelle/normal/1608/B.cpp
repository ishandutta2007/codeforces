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
    REP(i, t) {
        int n, a, b;
        cin >> n >> a >> b;
        if(a + b > n - 2 || abs(a - b) > 1) {
            cout << -1 << "\n";
            continue;
        }
        deque<int> dq;
        REP(i, n) dq.push_back(i + 1);
        deque<int> ans;
        REP(i, min(a, b)) {
            ans.pb(dq.front());
            ans.pb(dq.back());
            dq.pop_front();
            dq.pop_back();
        }
        if(a == b + 1) {
            ans.push_front(dq.back());
            dq.pop_back();
        }
        if(b == a + 1) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        if(max(a, b) != 0) {
            ans.push_front(dq.front());
            dq.pop_front();
        }
        while(not dq.empty()) {
            if(b != a + 1) {
                ans.push_back(dq.back());
                dq.pop_back();
            } else {
                ans.push_back(dq.front());
                dq.pop_front();
            }
        }
        REP(i, ans.size()) {
            if(i > 0)
                cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
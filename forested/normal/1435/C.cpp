// Template
#include "bits/stdc++.h"
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &element : vec) is >> element;
    return is;
}
template <typename T>
vector<T> operator--(vector<T> &vec) {
    for (T &element : vec) --element;
    return vec;
}

// Main
int main() {
    vector<ll> a(6);
    cin >> a;
    int n;
    cin >> n;
    vector<ll> b(n);
    cin >> b;
    
    vector<vector<ll>> x(n, vector<ll>(6));
    rep(i, n) rep(j, 6) x[i][j] = b[i] - a[j];
    
    vector<ll> vec;
    rep(i, n) rep(j, 6) vec.push_back(x[i][j]);
    
    sort(all(vec));
    
    ll ans = INF;
    set<pair<ll, int>> st;
    rep(i, n) st.insert({*min_element(all(x[i])), i});
    for (ll v : vec) {
        bool end = false;
        while (begin(st)->first < v) {
            pair<ll, int> p = *begin(st);
            st.erase(p);
            int idx = p.second;
            ll mn = INF;
            rep(i, 6) if (x[idx][i] >= v) chmin(mn, x[idx][i]);
            if (mn == INF) end = true;
            st.insert({mn, idx});
        }
        if (end) break;
        chmin(ans, rbegin(st)->first - v);
    }
    
    cout << ans << "\n";
}
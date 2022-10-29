// Template
#include "bits/stdc++.h"
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll infll = 3003003003003003003LL;
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
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &element : vec) is >> element;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (int i = 0, vec_len = (int)vec.size(); i < vec_len; ++i) {
        os << vec[i] << (i + 1 == vec_len ? "" : " ");
    }
    return os;
}
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;

// Main
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> t(n), x(n);
        rep(i, n) cin >> t[i] >> x[i];
        
        t.push_back(infll);
        
        ll ct = 0, cx = 0, ot = 0, ox = 0;
        int ans = 0;
        rep(i, n) {
            if (t[i] >= ct) {
                ot = t[i];
                ox = cx;
                ct = t[i] + abs(x[i] - cx);
                cx = x[i];
                if (ct <= t[i + 1]) ++ans;
            } else {
                if (ox < cx) {
                    ll a = ox + t[i] - ot;
                    ll b = min(ox + t[i + 1] - ot, cx);
                    if (a <= x[i] && x[i] <= b) ++ans;
                } else {
                    ll a = ox - (t[i] - ot);
                    ll b = max(ox - (t[i + 1] - ot), cx);
                    if (b <= x[i] && x[i] <= a) ++ans;
                }
            }
        }
        cout << ans << "\n";
    }
}
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        bool roop0 = true, roop1 = true;
        rep(i, n) if (s[i] == '<') roop0 = false;
        rep(i, n) if (s[i] == '>') roop1 = false;
        if (roop0 || roop1) {
            cout << n << "\n";
            continue;
        }
        int ans = 0;
        rep(i, n) {
            if (s[i] == '-' || s[(i + n - 1) % n] == '-') ++ans;
        }
        cout << ans << "\n";
    }
}
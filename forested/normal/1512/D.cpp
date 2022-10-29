// Template
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <tuple>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <cassert>
#include <cmath>
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
void solve() {
    int n;
    cin >> n;
    vector<ll> b(n + 2);
    cin >> b;
    
    sort(all(b));
    ll sum = 0;
    rep(i, n + 2) sum += b[i];
    
    rep(i, n + 1) {
        if (sum - b[i] - b[n + 1] == b[n + 1]) {
            vector<int> a;
            a.reserve(n);
            rep(j, n + 1) if (i != j) a.push_back(b[j]);
            cout << a << '\n';
            return;
        }
    }
    
    if (sum - b[n] - b[n + 1] == b[n]) {
        rep(i, n) cout << b[i] << " \n"[i == n - 1];
        return;
    }
    
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
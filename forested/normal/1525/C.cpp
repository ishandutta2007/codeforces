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
    int n, m;
    cin >> n >> m;
    vector<int> x(n), d(n);
    cin >> x;
    rep(i, n) {
        char c;
        cin >> c;
        d[i] = (c == 'R');
    }
    
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        return x[i] < x[j];
    });
    
    vector<int> ans(n, -1);
    deque<pair<int, int>> deven, dodd;
    for (int i : idx) {
        if (x[i] & 1) {
            if (d[i] == 0 && !dodd.empty() && dodd.back().second == 1) {
                int j = dodd.back().first;
                ans[i] = ans[j] = (x[i] - x[j]) / 2;
                //cout << i << ' ' << j << '\n';
                dodd.pop_back();
            } else {
                dodd.emplace_back(i, d[i]);
            }
        } else {
            if (d[i] == 0 && !deven.empty() && deven.back().second == 1) {
                int j = deven.back().first;
                ans[i] = ans[j] = (x[i] - x[j]) / 2;
                //cout << i << ' ' << j << '\n';
                deven.pop_back();
            } else {
                deven.emplace_back(i, d[i]);
            }
        }
    }
    
    while (!deven.empty() && deven.front().second == 0) {
        int i = deven.front().first;
        deven.pop_front();
        if (deven.empty() || deven.front().second == 1) {
            deven.emplace_front(i, 0);
            break;
        }
        int j = deven.front().first;
        deven.pop_front();
        ans[i] = ans[j] = (x[i] + x[j]) / 2;
    }
    while (!deven.empty() && deven.back().second == 1) {
        int i = deven.back().first;
        deven.pop_back();
        if (deven.empty() || deven.back().second == 0) {
            deven.emplace_back(i, 1);
            break;
        }
        int j = deven.back().first;
        deven.pop_back();
        ans[i] = ans[j] = (m - x[i] + m - x[j]) / 2;
    }
    if (deven.size() >= 2) {
        int i = deven.front().first;
        int j = deven.back().first;
        ans[i] = ans[j] = (x[i] + m - x[j] + m) / 2;
    }
    
    #define deven dodd
    while (!deven.empty() && deven.front().second == 0) {
        int i = deven.front().first;
        deven.pop_front();
        if (deven.empty() || deven.front().second == 1) {
            deven.emplace_front(i, 0);
            break;
        }
        int j = deven.front().first;
        deven.pop_front();
        ans[i] = ans[j] = (x[i] + x[j]) / 2;
    }
    while (!deven.empty() && deven.back().second == 1) {
        int i = deven.back().first;
        deven.pop_back();
        if (deven.empty() || deven.back().second == 0) {
            deven.emplace_back(i, 1);
            break;
        }
        int j = deven.back().first;
        deven.pop_back();
        ans[i] = ans[j] = (m - x[i] + m - x[j]) / 2;
    }
    if (deven.size() >= 2) {
        int i = deven.front().first;
        int j = deven.back().first;
        ans[i] = ans[j] = (x[i] + m - x[j] + m) / 2;
    }
    #undef deven
    
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
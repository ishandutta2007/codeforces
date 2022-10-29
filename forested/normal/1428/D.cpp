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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    int y = 0;
    set<int> st0;
    set<pair<int, int>> st1;
    vector<vector<int>> vec(n);
    per(i, n) {
        if (a[i] == 1) {
            vec[i].push_back(y);
            ++y;
            st0.insert(i);
            st1.insert({1, i});
        }
        if (a[i] == 2) {
            if (st0.empty()) {
                cout << "-1\n";
                return 0;
            }
            int x = *begin(st0);
            st0.erase(x);
            st1.erase({1, x});
            vec[i].push_back(vec[x][0]);
            st1.insert({0, i});
        }
        if (a[i] == 3) {
            if (st1.empty()) {
                cout << "-1\n";
                return 0;
            }
            auto p = *begin(st1);
            if (p.first) st0.erase(p.second);
            st1.erase(p);
            vec[i].push_back(y);
            vec[p.second].push_back(y);
            ++y;
            st1.insert({0, i});
        }
    }
    
    int t = 0;
    rep(i, n) t += (int)vec[i].size();
    cout << t << "\n";
    rep(i, n) for (int x : vec[i]) cout << n - x << " " << i + 1 << "\n";
}
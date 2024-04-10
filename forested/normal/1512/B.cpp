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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        cin >> s;
        
        int a = -1, b = -1, c = -1, d = -1;
        rep(i, n) rep(j, n) if (s[i][j] == '*') {
            if (a == -1) a = i;
            else if (a != i) b = i;
            if (c == -1) c = j;
            else if (c != j) d = j;
        }
        
        if (b == -1) {
            if (a == 0) s[1][c] = s[1][d] = '*';
            else s[0][c] = s[0][d] = '*';
        } else if (d == -1) {
            if (c == 0) s[a][1] = s[b][1] = '*';
            else s[a][0] = s[b][0] = '*';
        } else {
            s[a][c] = s[a][d] = s[b][c] = s[b][d] = '*';
        }
        
        rep(i, n) cout << s[i] << '\n';
    }
}
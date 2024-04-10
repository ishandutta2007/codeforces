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
        vector<int> a(2 * n, 0);
        rep(i, n) {
            int x;
            cin >> x;
            a[x - 1] = 1;
        }
        vector<int> b, c;
        rep(i, 2 * n) {
            if (a[i]) b.push_back(i);
            else c.push_back(i);
        }
        int l = 0, r = 0;
        {
            int ok = n, ng = -1;
            while (ok - ng > 1) {
                int mid = (ok + ng) / 2;
                bool judge = true;
                rep(i, n - mid) {
                    if (c[i] > b[mid + i]) judge = false;
                }
                (judge ? ok : ng) = mid;
            }
            l = ok;
        }
        {
            int ok = 0, ng = n + 1;
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                bool judge = true;
                rep(i, mid) {
                    if (c[n - mid + i] < b[i]) judge = false;
                }
                (judge ? ok : ng) = mid;
            }
            r = ng;
        }
        cout << r - l << "\n";
    }
}
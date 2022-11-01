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

struct segment_tree {
    int n;
    vector<vector<vector<int>>> t;
    segment_tree(int _n) {
        n = 1;
        while(n < _n)
            n *= 2;
        t.resize(2 * n - 1, vector<vector<int>>(3, vector<int>(3, 0)));
    }

    void update(int k, int num) {
        k += n - 1;
        REP(i, 3) FOR(j, i, 3) {
            if(i == j && i == num)
                t[k][i][j] = 1;
            else
                t[k][i][j] = 0;
        }
        while(k > 0) {
            k = (k - 1) / 2;
            REP(i, 3) FOR(j, i, 3) {
                t[k][i][j] = 1e9;
                for(int m = i; m <= j; m++) {
                    t[k][i][j] = min(t[k][i][j],
                                     t[k * 2 + 1][i][m] + t[k * 2 + 2][m][j]);
                }
            }
        }
    }
};

int ctoi(char c) {
    if(c == 'a')
        return 0;
    if(c == 'b')
        return 1;
    if(c == 'c')
        return 2;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segment_tree seg(n + 1);
    REP(i, n) seg.update(i, ctoi(s[i]));

    REP(i, q) {
        int x;
        char c;
        cin >> x >> c;
        x--;
        seg.update(x, ctoi(c));
        cout << seg.t[0][0][2] << endl;
    }
    return 0;
}
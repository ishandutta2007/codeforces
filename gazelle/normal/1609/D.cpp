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

struct union_find {
    union_find(int n) : par_(n, -1) {}
    void init(int n) { par_.assign(n, -1); }
    int root(int x) { return par_[x] < 0 ? x : par_[x] = root(par_[x]); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y)
            return false;
        if(par_[x] < par_[y]) {
            par_[x] += par_[y];
            par_[y] = x;
        } else {
            par_[y] += par_[x];
            par_[x] = y;
        }
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par_[root(x)]; }
    vector<int> par_;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;

    union_find uf(n);
    int plus = 0;

    REP(i, d) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(uf.same(x, y))
            plus += 1;
        else
            uf.unite(x, y);
        vector<bool> r(n, false);
        vector<int> s;
        REP(i, n) {
            if(r[uf.root(i)])
                continue;
            r[uf.root(i)] = true;
            s.pb(uf.size(i));
        }
        sort(ALL(s), greater<int>());
        int sum = 0;
        REP(i, plus + 1)
        sum += s[i];
        cout << sum - 1 << "\n";
    }
    return 0;
}
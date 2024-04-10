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

int n, m;
map<pair<int, int>, int> memo;
set<pair<int, int>> synergies;

int dfs(int x, int y) {
    if(memo.count({x, y}))
        return memo[{x, y}];

    if(x == n && y == m)
        return 0;

    int power = x + y;
    if(synergies.count({x, y}))
        power += 1;

    int new_x = min(n, power), new_y = min(m, power);
    int cost = numeric_limits<int>::max();
    if(new_x != x && (new_x + y >= x + new_y - 3 || new_x == n))
        cost = min(cost, dfs(new_x, y));
    if(new_y != y && (x + new_y >= new_x + y - 3 || new_y == m))
        cost = min(cost, dfs(x, new_y));

    return memo[{x, y}] = cost + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    int q;
    cin >> q;

    REP(i, q) {
        int a, b;
        cin >> a >> b;
        if(n > m)
            swap(a, b);
        synergies.insert({a, b});
    }

    if(n > m)
        swap(n, m);

    cout << dfs(1, 1) << endl;

    return 0;
}
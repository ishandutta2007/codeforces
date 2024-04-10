#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

vi p, r;

int findSet(int x) {
    if (x == p[x]) return x;
    return p[x] = findSet(p[x]);
}

bool unionSet(int x, int y) {
    int px = findSet(x), py = findSet(y);
    if (px == py) return false;

    if (r[px] < r[py]) swap(px, py);
    else if (r[px] == r[py]) r[px]++;

    p[py] = px;
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    p.resize(n);
    r.resize(n);
    iota(all(p), 0);

    vii rm;
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (!unionSet(x, y)) rm.eb(x, y);
    }

    vi groups;
    rep(i, n) {
        if (i == findSet(i)) groups.pb(i);
    }

    cout << sz(rm) << '\n';
    while (!rm.empty()) {
        cout << rm.back().fi + 1 << ' ' << rm.back().se + 1 << ' ';
        rm.pop_back();

        int cur = groups.back();
        groups.pop_back();
        cout << cur + 1 << ' ' << groups.back() + 1 << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

vector <ll> sq;

const ll lim = 1e13 + 7;

void init() {
    for (ll d = 1; d * d <= lim; ++d) {
        sq.push_back(d * d);
    }
}

void no() {
    cout << "No\n";
    exit(0);
}

bool check(ll x) {
    auto it = lower_bound(sq.begin(), sq.end(), x);
    if (it == sq.end()) return false;
    if ((*it) != x) return false;
    return true;
}

int get_id(ll x) {
    return lower_bound(sq.begin(), sq.end(), x) - sq.begin();
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    int n;
    cin >> n;
    int m = n / 2;
    vector <int> x(m);
    for (int i = 0; i < m; ++i) cin >> x[i];
    int uk = 0;
    vector <ll> ps;
    int q = sq.size();
    for (int i = 0; i < m; ++i) {
        while (uk < q && !check(sq[uk] + x[i])) ++uk;
        if (uk == q) no();
        ps.push_back(sq[uk]);
        ps.push_back(sq[uk] + x[i]);
        uk = get_id(sq[uk] + x[i]) + 1;
    }
    vector <ll> cur;
    cur.push_back(ps[0]);
    for (int i = 1; i < ps.size(); ++i) {
        cur.push_back(ps[i] - ps[i - 1]);
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << cur[i] << ' ';
    }
}
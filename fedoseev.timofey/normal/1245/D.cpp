#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
    int a, b; ll c;
    bool operator <(const Edge &other) const {
        return c < other.c;
    }
};

const int N = 2007;

int p[N];
int cost[N];

int get(int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
}

void join(int u, int v) {
    u = get(u);
    v = get(v);
    if (cost[u] < cost[v]) swap(u, v);
    p[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> x(n), y(n), c(n), k(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }  
    vector <Edge> E;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            E.push_back({i, j, (ll)(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j])});
        }
    }

    sort(E.begin(), E.end());

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        p[i] = i;
        cost[i] = c[i];
        ans += c[i];
    }
    vector <pair <int, int>> rd;

    for (auto e : E) {
        int u = e.a;
        int v = e.b;
        if (get(u) != get(v) && e.c < max(cost[get(u)], cost[get(v)])) {
            ans += e.c;
            ans -= max(cost[get(u)], cost[get(v)]);
            join(u, v);
            rd.push_back({u, v});
        }
    }
    vector <int> el;
    for (int i = 0; i < n; ++i) el.push_back(get(i));
    sort(el.begin(), el.end());
    el.resize(unique(el.begin(), el.end()) - el.begin());
    cout << ans << '\n';
    cout << el.size() << '\n';
    for (int x : el) cout << x + 1 << ' ';
    cout << '\n';
    cout << rd.size() << '\n';
    for (auto p : rd) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}
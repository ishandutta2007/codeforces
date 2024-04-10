#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1000;
int dsu[MAXN + 5];

int get(int x) {
    if (dsu[x] < 0)
        return x;
    return dsu[x] = get(dsu[x]);
}

bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return false;
    if (-dsu[a] < -dsu[b])
        swap(a, b);
    dsu[a] += dsu[b];
    dsu[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    fill_n(dsu, n, -1);

    int best = 1;
    vector<int> comps;
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (!unite(x, y))
            ++best;
        comps.clear();
        for (int j = 0; j < n; ++j)
            if (dsu[j] < 0)
                comps.push_back(dsu[j]);
        sort(all(comps));
        int ans = -1;
        for (int j = 0; j < best; ++j)
            ans -= comps[j];
        cout << ans << '\n';
    }
}
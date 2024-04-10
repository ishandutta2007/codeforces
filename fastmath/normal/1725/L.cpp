#include <bits/stdc++.h>

using ll = long long;
#define int ll
using namespace std;
struct edge {
    int next, w;
};
template<typename T>
using pqg = priority_queue<T, vector<T>, greater<>>;

struct SumTree {
    int n;
    vector<int> data;

    SumTree(int n) : n(n), data(2 * n) {}

    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res += data[l++];
            if (r & 1) res += data[--r];
        }
        return res;
    }

    void add(int i, int x) {
        data[i += n] += x;
        for (i /= 2; i > 0; i /= 2) data[i] = data[2 * i] + data[2 * i + 1];
    }
};

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
    if (all_of(p.begin(), p.end(), [&](int x) { return x >= p[0]; }) && all_of(p.begin(), p.end(), [&](int x) { return x <= p[n]; })) {
        auto vals = p;
        sort(vals.begin(), vals.end());
        for (int &x : p) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        vector<int> ind(n + 1);
        iota(ind.begin(), ind.end(), 0);
        stable_sort(ind.begin(), ind.end(), [&](int i, int j) { return p[i] < p[j]; });
        SumTree s(n + 1);
        int ans = 0;
        for (int i : ind) {
            s.add(i, 1);
            ans += s.get(i + 1, n + 1);
        }
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int M = 1e6 + 1;

const int N = 3e5 + 1;

ll t[4 * N];

void build(int l, int r, int v, const vector <int> &a) {
    if (l == r) {
        t[v] = a[l];
    }
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v, a);
        build(m + 1, r, 2 * v + 1, a);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll get(int l, int r, int v, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) >> 1;
    return get(l, m, 2 * v, ql, qr) + get(m + 1, r, 2 * v + 1, ql, qr);
}

void change(int ind, int val, int l, int r, int v) {
    if (ind < l || r < ind) return;
    if (l == r) {
        t[v] = val;
    }
    else {
        int m = (l + r) >> 1;
        change(ind, val, l, m, 2 * v);
        change(ind, val, m + 1, r, 2 * v + 1);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}


int d[M];

void init() {
    for (int i = 1; i < M; ++i) {
        for (int j = i; j < M; j += i) {
            ++d[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    set <int> have;
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] != d[a[i]]) {
            have.insert(i);
        }
    }
    build(0, n - 1, 1, a);
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 2) {
            cout << get(0, n - 1, 1, l, r) << endl;
        }
        else {
            auto it = have.lower_bound(l);
            vector <int> to_del;
            while (it != have.end() && l <= *it && *it <= r) {
                int ind = *it;
                to_del.push_back(ind);
                a[ind] = d[a[ind]];
                change(ind, a[ind], 0, n - 1, 1);
                ++it;
            }
            for (auto ind : to_del) {
                if (a[ind] == d[a[ind]]) {
                    have.erase(ind);
                }
            }
        }
    }
}
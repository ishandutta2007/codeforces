#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = (int)4e4;
const int Inf = 1e9;

vector <int> t(4 * N);
vector <int> mod(4 * N);

void update(int v, int x) {
    t[v] += x;
    mod[v] += x;
}

void push(int v) {
    if (mod[v] != 0) {
        update(2 * v + 1, mod[v]);
        update(2 * v + 2, mod[v]);
        mod[v] = 0;
    }
}

void build(int l, int r, int v, vector <int> &a) {
    if (l == r) {
        t[v] = a[l];
    }
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v + 1, a);
        build(m + 1, r, 2 * v + 2, a);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
}

void modify(int ql, int qr, int x, int l, int r, int v) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr) {
        update(v, x);
    }
    else {
        push(v);
        int m = (l + r) >> 1;
        modify(ql, qr, x, l, m, 2 * v + 1);
        modify(ql, qr, x, m + 1, r, 2 * v + 2);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
}

int get(int ql, int qr, int l, int r, int v) {
    if (r < ql || qr < l) return -Inf;
    if (ql <= l && r <= qr) return t[v];
    else {
        push(v);
        int m = (l + r) >> 1;
        return max(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m + 1, r, 2 * v + 2));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> f(n);
    vector <int> x(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        f[i] = x[a[i]];
        if (f[i] == -1) f[i] = 0;
        x[a[i]] = i;
    }
    vector <int> ndp(n);
    set <int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        ndp[i] = (int)s.size();
    }
    build(0, n - 1, 0, ndp);
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            modify(f[j], j - 1, 1, 0, n - 1, 0);
            ndp[j] = get(0, j - 1, 0, n - 1, 0);
        }
        for (int i = 0; i < 4 * N; ++i) {
            mod[i] = 0;
        }
        build(0, n - 1, 0, ndp);
    }
    cout << get(0, n - 1, 0, n - 1, 0) << '\n';
}
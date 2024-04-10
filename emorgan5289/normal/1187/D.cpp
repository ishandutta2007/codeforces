#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int size) {
        length = size+1;
        tree.assign(length+1, 0);
    }

    // insert val at index i
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] = max(tree[i], val);
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out = max(out, tree[i]);
            i -= i & -i;
        }
        return out;
    }
};

const int N = 3e5+5;
ll a[N], b[N], p[N];
deque<int> q[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fenwick<int> f(n);
        bool v = 1;
        for (int i = 0; i <= n; i++)
            q[i].clear();
        for (int i = 0; i < n; i++)
            cin >> a[i], q[a[i]].pb(i);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (q[b[i]].empty()) {
                v = 0; continue;
            }
            p[q[b[i]].front()] = i;
            q[b[i]].pop_front();
        }
        for (int i = n-1; i >= 0; i--) {
            v = v && f.prefix(p[i]) <= a[i];
            f.update(p[i], a[i]);
        }
        cout << (v ? "YES\n" : "NO\n");
    }
}
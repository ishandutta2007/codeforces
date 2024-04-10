//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

vector<int> g[100100];
int parity[100100];
char was[100100];
vector<int> order;

void add(int v) {
    order.push_back(v);
    parity[v] ^= 1;
}

void dfs(int v, int p = -1) {
    was[v] = true;
    add(v);
    for (int to : g[v]) {
        if (!was[to]) {
            dfs(to, v);
            add(v);
            if (parity[to]) {
                add(to);
                add(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) cin >> parity[i];

    bool good = true;
    for (int i = 1; i <= n; ++i) {
        if (!was[i] && parity[i]) {
            if (order.empty()) {
                dfs(i);
                if (parity[i]) {
                    order.pop_back();
                    parity[i] = 0;
                }
            } else {
                good = false;
                break;
            }
        }
    }
    if (!good) {
        cout << "-1\n";
    } else {
        cout << order.size() << '\n';
        for (int i : order)
            cout << i << ' ';
        cout << '\n';
    }
}
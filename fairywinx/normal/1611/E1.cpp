#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 2e5 + 228;

vector<int> G[N];

vector<int> dist(int n, vector<int> s) {
    vector<int> d(n, -1);
    queue<int> q;
    for (int i : s) {
        d[i] = 0;
        q.push(i);
    }

    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i : G[v]) {
            if (d[i] == -1) {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    return d;
}

bool solve(int v, vector<int> &d1, vector<int> &d2, int p = -1) {
    if (v != 0 && G[v].size() == 1) {
        return true;
    }
    for (int i : G[v]) {
        if (i != p && d1[i] < d2[i]) {
            if (solve(i, d1, d2, v)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int &i : a) {
        cin >> i;
        --i;
    }
    for (int i = 0; i < n; ++i)
        G[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].emplace_back(b - 1);
        G[b - 1].emplace_back(a - 1);
    }
    auto d1 = dist(n, {0});
    auto d2 = dist(n, a);
    if (solve(0, d1, d2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}
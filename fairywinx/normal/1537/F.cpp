#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 2e5 + 228;
vector<int> G[N];
int used[N];
int col[N];

bool dfs(int v, int c) {
    col[v] = c;
    used[v] = 1;
    for (int i : G[v]) {
        if (!used[i]) {
            if (dfs(i, c ^ 1))
                return true;
        } else if (col[i] == c) {
            return true;
        }
    }
    return false;
}

void dfs(int v, vector<long long> &a, vector<long long> &b) {
    used[v] = 1;
    for (int i : G[v]) {
        if (!used[i]) {
            dfs(i, a, b);
            a[v] += (b[i] - a[i]);
            a[i] = b[i];
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        used[i] = 0;
        col[i] = -1;
        G[i].clear();
    }
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += b[i] + a[i];
    }
    for (int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        G[c - 1].push_back(d - 1);
        G[d - 1].push_back(c - 1);
    }
    if (sum % 2 != 0) {
        cout << "NO\n";
        return;
    }
    if (dfs(0, 0)) {
        cout << "YES\n";
        return;
    }
    fill(used, used + n, 0);
    dfs(0, a, b);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
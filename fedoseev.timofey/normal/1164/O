#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

const int N = 3007;

int col[N];
bool fl = false;

vector <pair <int, int>> g[N];

void dfs(int u) {
    for (auto &[v, w] : g[u]) {
        if (col[v] == -1) {
            col[v] = col[u] ^ w;
            dfs(v);
        }
        else if (col[v] != (col[u] ^ w)) {
            fl = true;
        }
    }
}

void clear() {
    for (int i = 0; i < N; ++i) col[i] = -1;
    fl = false;
    for (int i = 0; i < N; ++i) g[i].clear();
    col[N - 1] = 0;
    col[N - 2] = 1;
}

void add(int a, int b, int t) {
    g[a].push_back({b, t});
    g[b].push_back({a, t});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    // N - 1 -- 0
    // N - 2 -- 1
    for (int i = 1; i < n; ++i) {
        clear();
        add(N - 2, 0, 0);
        for (int j = 0; j < i; ++j) {
            add(N - 1, n + j, 0);
        }
        add(N - 2, n + i, 0);
        for (int j = 0; j < n / 2; ++j) {
            add(j, n - j - 1, 0);
        }
        for (int j = i; j < n; ++j) {
            int k = n - (j - i) - 1;
            if (j < k) add(n + j, n + k, 0);
        }
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                add(j, n + j, 1);
            }
            else if (s[j] == '0') {
                add(j, n + j, 0);
            }
        }
        dfs(N - 1);
        dfs(N - 2);
        int cur = (fl ? 0 : 1);
        for (int i = 0; i < 2 * n; ++i) {
            if (col[i] == -1) {
                col[i] = 0;
                dfs(i);
                if (fl) {
                    cur = 0;
                }
                cur = mul(cur, 2);
            }
        }
        add(ans, cur);
    }
    cout << ans << '\n';
}
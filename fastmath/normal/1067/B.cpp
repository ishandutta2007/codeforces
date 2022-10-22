#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n, k;
vector <int> g[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
}

int pw[MAXN];
bool used[MAXN];
int cnt[MAXN];
void bfs() {
    vector <int> t;
    for (int i = 0; i < n; ++i) {
        if (!used[i] && pw[i] == 1) {
            t.push_back(i);
            used[i] = 1;
        }
    }
    if (t.empty()) {
        cout << "No\n";
        exit(0);
    }   
    for (int i = 0; i < n; ++i) cnt[i] = 0;
    for (int u : t) {
        for (int v : g[u]) {
            --pw[v];
            ++cnt[v];
        }
    }   
    for (int i = 0; i < n; ++i) {
        if (!used[i] && cnt[i] && cnt[i] < 3) {
            cout << "No\n";
            exit(0);
        }
    }
}

void solve() {  
    for (int i = 0; i < n; ++i) pw[i] = g[i].size();
    for (int i = 0; i < k; ++i) {
        bfs();
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += !used[i];
    if (cnt != 1) {
        cout << "No\n";
        exit(0);
    }   
}

void print() {
    cout << "Yes\n";
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}
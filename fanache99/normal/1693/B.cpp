#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int l[1 + MAXN], r[1 + MAXN], v[1 + MAXN], ans;

void DFS(int node) {
    int mx = 0;
    long long sum = 0;
    for (auto son : g[node]) {
        DFS(son);
        mx = max(mx, v[son]);
        sum += v[son];
    }
    if (sum >= l[node]) {
        v[node] = min((long long) r[node], sum);
    } else {
        ans++;
        v[node] = r[node];
    }
}

int main() {
    // ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            g[p].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }
        ans = 0;
        DFS(1);
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}
#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(int i = 0; i < n; ++i)
#define ar array

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int maxN = 5e4 + 1;
const int md = 1e9 + 7;

vector<int> g[maxN];
int a[maxN];
int last[maxN];
int h[maxN];
int cur = 0;
int ans = 0;
int cnt = 0;

void dfs(int v) {
    if (cur - last[v] >= a[v]) {
        ans += h[v];
        cnt++;
        last[v] = cur;
    }
    for (auto &u: g[v]) {
        dfs(u);
    }
}

void dfs2(int v) {
    for (auto &u: g[v]) {
        h[u] = h[v] + 1;
        dfs2(u);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    cur = maxN;
    q += maxN;
    dfs2(1);
    for (; cur < q; ++cur) {
        int x;
        cin >> x;
        cnt = ans = 0;
        if (x != 1) {
            dfs(x);
            ans -= h[x] * cnt;
        } else {
            for (int v = 1; v <= n; ++v) {
                if (cur - last[v] >= a[v]) {
                    ans += h[v];
                    cnt++;
                    last[v] = cur;
                }
            }
        }
        cout << ans << " " << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
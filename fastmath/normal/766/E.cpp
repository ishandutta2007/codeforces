#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int LG = 20;

int n;
int a[MAXN];
vector <int> g[MAXN];

int cnt[MAXN][2];
int c[MAXN];

int ans = 0;
void dfs(int u, int parent, int f) {
    if (c[u]) {
        cnt[u][0] = 0;
        cnt[u][1] = 1;
    }
    else {
        cnt[u][0] = 1;
        cnt[u][1] = 0;
    }

    for (int v : g[u]) {
        if (v != parent) {
            dfs(v, u, f);
            if (c[u]) {
                cnt[u][0] += cnt[v][1];
                cnt[u][1] += cnt[v][0];
            }   
            else {
                cnt[u][0] += cnt[v][0];
                cnt[u][1] += cnt[v][1];
            }   
        }   
    }

    int c0 = 0, c1 = 0;

    if (c[u]) {
        c0 = 0;
        c1 = 1;
    }          
    else {
        c0 = 1;
        c1 = 0;
    }   

    for (int v : g[u]) {
        if (v != parent) {
            ans += f * c0 * cnt[v][1];
            ans += f * c1 * cnt[v][0];
            if (c[u]) {
                c0 += cnt[v][1];
                c1 += cnt[v][0];
            }
            else {
                c0 += cnt[v][0];
                c1 += cnt[v][1];
            }   
        }   
    }   
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);                

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   

    for (int i = 0; i < LG; ++i) {
        for (int u = 0; u < n; ++u) {
            c[u] = (a[u] >> i) & 1;
        }   
        dfs(0, 0, 1 << i);
    }   

    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>
 
using namespace std;
#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN];
vector <int> g[MAXN];

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int t1[MAXN], t2[MAXN], cnt[MAXN];
void calc(int u, int parent, int h) {
    if (h % 2) ++t1[u];
    else ++t2[u];
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        calc(v, u, h + 1);
        t1[u] += t1[v];
        t2[u] += t2[v];
        cnt[u] += cnt[v];
    }
}

int n;
int ans = 0;
void jfs(int u, int parent, int h) {
    for (int v : g[u]) {
        if (v == parent) continue;
        jfs(v, u, h + 1);
    }

    ans += a[u] * n;
    ans = mod(ans);

    int sum1 = t1[0];
    int sum2 = t2[0];
    for (int v : g[u]) {
        int n1, n2, sz;
        if (v == parent) {
            n1 = sum1 - t1[u];
            n2 = sum2 - t2[u];
            sz = cnt[u];
        }
        else {
            n1 = t1[v];
            n2 = t2[v];
            sz = n - cnt[v];
        }

        if (h % 2) {
            ans += n1 * sz * a[u];
            ans = mod(ans);
            ans -= n2 * sz * a[u];
            ans = mod(ans);
        }
        else {
            ans -= n1 * sz * a[u];
            ans = mod(ans);
            ans += n2 * sz * a[u];
            ans = mod(ans);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    
    calc(0, 0, 0);
    jfs(0, 0, 0);

    cout << ans << '\n';
    return 0;
}
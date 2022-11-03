#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e8 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
*/

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;
    return res;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

vector<int> g[N];
int dp[N], up[N];

void dfs1(int v, int par) {
    dp[v] = 1;

    for(auto u : g[v]) {
        if(u == par)
            continue;

        dfs1(u, v);

        dp[v] = dp[v] * 1ll * (dp[u] + 2) % M;
    }

    dp[v] = dif(dp[v], 1);
}

void dfs2(int v, int par) {
    vector<int> a;
    for(auto u : g[v])
        if(u != par)
            a.push_back(u);
    vector<int> p(a.size() + 1), s(a.size() + 1);
    p[0] = 1;
    for(int i = 1; i <= a.size(); i++) {
        p[i] = p[i - 1] * 1ll * (dp[a[i - 1]] + 2) % M;
    }

    s[a.size()] = 1;
    for(int i = a.size() - 1; i >= 0; i--) {
        s[i] = s[i + 1] * 1ll * (dp[a[i]] + 2) % M;
    }

//    cout << v << ' ' << up[v] << endl;

    for(int i = 0; i < a.size(); i++) {
        up[a[i]] = p[i] * 1ll * s[i + 1] % M * 1ll * (up[v] + 1) % M;
    }

    for(auto u : a)
        dfs2(u, v);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

        p--;

        g[p].push_back(i);
    }

    dfs1(0, 0);

    up[0] = 0;
    dfs2(0, 0);

//    cout << dp[0] + 1 << ' ';
    for(int i = 0; i < n; i++) {
        cout << (dp[i] + 1) * 1ll * (up[i] + 1) % M << ' ';
    }
}
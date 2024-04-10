#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 5e5+5, A = 1<<22;
vector<pair<int, int>> adj[N];
int r[N], m[A], s[N], k[N], in[N], out[N], t = 0, a[N], b[N];

void upd(int i, int x, int d) {
    s[i] = 1, k[i] = -1, in[i] = t++;
    a[in[i]] = x, b[in[i]] = d;
    for (auto& [y, j] : adj[i]) {
        upd(j, x^y, d+1);
        s[i] += s[j];
        if (k[i] == -1 || s[j] > s[k[i]]) k[i] = j;
    }
    out[i] = t;
}

void chk(int i, int x) {
    for (int y = 1; y < A; y <<= 1)
        r[i] = max(r[i], m[a[x]^y]+b[x]-2*b[in[i]]);
    r[i] = max(r[i], m[a[x]]+b[x]-2*b[in[i]]);
}

void dfs(int i) {
    for (auto& [y, j] : adj[i])
        if (j != k[i]) {
            dfs(j);
            r[i] = max(r[i], r[j]);
            for (int x = in[j]; x < out[j]; x++)
                m[a[x]] = -inf;
        }
    if (k[i] != -1) {
        dfs(k[i]);
        r[i] = max(r[i], r[k[i]]);
    }
    chk(i, in[i]);
    m[a[in[i]]] = max(m[a[in[i]]], b[in[i]]);
    for (auto& [y, j] : adj[i])
        if (j != k[i]) {
            for (int x = in[j]; x < out[j]; x++)
                chk(i, x);
            for (int x = in[j]; x < out[j]; x++)
                m[a[x]] = max(m[a[x]], b[x]);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        char c; int j; cin >> j >> c;
        adj[j-1].pb({1<<(c-'a'), i});
    }
    upd(0, 0, 0);
    fill(m, m+A, -inf);
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << r[i] << " \n"[i==n-1];
}
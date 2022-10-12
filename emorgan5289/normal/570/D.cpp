#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int size) {
        length = size+1;
        tree.assign(length+1, 0);
    }

    // insert val at index i
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] ^= val;
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out ^= tree[i];
            i -= i & -i;
        }
        return out;
    }

    // sum over a..b, inclusive
    T query(int a, int b) {
        return prefix(b)^prefix(a-1);
    }
};

const int maxn = 500005;
vector<int> adj[maxn], v[maxn];
vector<pair<int, int>> q[maxn];
int a[maxn], d[maxn], vin[maxn], vout[maxn], res[maxn];
fenwick<int> f(maxn);
int t = 0;

void dfs(int i) {
    v[d[i]].pb(i);
    vin[i] = t++;
    for (auto& j : adj[i]) {
        d[j] = d[i]+1;
        dfs(j);
    }
    vout[i] = t-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int p; cin >> p; adj[p-1].pb(i);
    }
    for (int i = 0; i < n; i++) {
        char c; cin >> c; a[i] = 1<<int(c-'a');
    }
    for (int i = 0; i < m; i++) {
        int w, h; cin >> w >> h;
        q[h-1].pb({w-1, i});
    }
    d[0] = 0;
    dfs(0);
    for (int i = 0; i < n; i++) {
        for (auto& j : v[i])
            f.update(vin[j], a[j]);
        for (auto& [j, k] : q[i])
            res[k] = __builtin_popcount(f.query(vin[j], vout[j])) <= 1;
        for (auto& j : v[i])
            f.update(vin[j], a[j]);
    }
    for (int i = 0; i < m; i++)
        cout << (res[i] ? "Yes" : "No") << "\n";
}
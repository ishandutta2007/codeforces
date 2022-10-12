#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5, K = 20;
int c[K][K], dp[K][(1<<K)+5];

struct unionfind {

    vector<int> p, sz;

    unionfind(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a != b) p[b] = a, sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        unionfind uf(K);
        int ans = 0;
        bool v = 0;
        for (int i = 0; i < n; i++) {
            c[a[i]-'a'][b[i]-'a'] = 1;
            if (a[i] > b[i]) v = 1;
            if (!uf.query(a[i]-'a', b[i]-'a')) ans++;
            uf.unite(a[i]-'a', b[i]-'a');
        }
        cout << (v ? -1 : ans) << "\n";
    }
}
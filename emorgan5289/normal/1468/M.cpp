#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// Transform the contents of [first, last) into elements of [0..N],
// while preserving the relative ordering/equality of the data.
// Runs in O(nlogn).

template<typename it1, typename it2, typename cmp = less<>>
void compress(it1 first, it1 last, it2 result, cmp ord = less<>()) {
    using T = typename remove_reference<decltype(*first)>::type;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [_, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

const int N = 2e5+5, S = 450;
vector<int> s[N], g[N], b;
int n, u;

void solve() {
    vector<vector<int>> big(b.size(), vector<int>(u, 0));
    // large set + any set
    for (int i = 0; i < b.size(); i++)
        for (int x : s[b[i]]) big[i][x] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b.size(); j++) {
            if (s[i].size() >= S && i >= b[j]) continue;
            int c = 0;
            for (int x : s[i]) c += big[j][x];
            if (c >= 2) {
                cout << b[j]+1 << " " << i+1 << "\n";
                return;
            }
        }
    }
    for (int i = 0; i < u; i++) g[i].clear();
    big.clear();
    // large group + any group
    b.clear();
    for (int i = 0; i < n; i++) {
        if (s[i].size() >= S) continue;
        for (int x : s[i]) g[x].pb(i);
    }
    for (int i = 0; i < u; i++)
        if (g[i].size() >= S) b.pb(i), big.pb(vector<int>(n, 0));
    for (int i = 0; i < b.size(); i++)
        for (int x : g[b[i]]) big[i][x] = 1;
    vector<int> c;
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < b.size(); j++) {
            if (g[i].size() >= S && i >= b[j]) continue;
            c.clear();
            for (int x : g[i]) if (big[j][x]) c.pb(x);
            if (c.size() >= 2) {
                cout << c[0]+1 << " " << c[1]+1 << "\n";
                return;
            }
        }
    }
    vector<bool> seen(n);
    // small set, small group
    for (int i = 0; i < n; i++) {
        if (s[i].size() >= S) continue;
        for (int x : s[i]) {
            if (g[x].size() >= S) continue;
            for (int j : g[x]) seen[j] = 0;
        }
        for (int x : s[i]) {
            if (g[x].size() >= S) continue;
            for (int j : g[x]) {
                if (j == i) continue;
                if (seen[j]) {
                    cout << j+1 << " " << i+1 << "\n";
                    return;
                }
                seen[j] = 1;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ks, dump;
        b.clear();
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            ks.pb(k);
            s[i].clear();
            if (k >= S) b.pb(i);
            while (k--) {
                int x; cin >> x;
                dump.pb(x);
            }
        }
        compress(all(dump), dump.begin());
        u = *max_element(all(dump))+1;
        int j = 0;
        for (int i = 0; i < n; i++)
            while (ks[i]--) s[i].pb(dump[j++]);
        solve();
    }
}
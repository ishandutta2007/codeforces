#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ull t; fin >> t;
    while (t--) {
        ull n, m; fin >> n >> m;
        vector<ull> c(n); for (auto& x : c) fin >> x;
        vector<vector<ull>> adj(n);
        for (ull i = 0; i < m; i++) {
            ull u, v; fin >> u >> v;
            adj[v-1].push_back(u-1);
        }
        unordered_map<ull, ull> s;
        for (ull i = 0; i < n; i++) {
            ull h = 0;
            for (auto x : adj[i])
                h ^= hash<string>()(to_string(x));
            if (h > 0) s[h] += c[i];
        }
        ull out = 0;
        for (auto [ignore, x] : s)
            out = __gcd(out, x);
        // debug(out);
        cout << out << "\n";
    }
}
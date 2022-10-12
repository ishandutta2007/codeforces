#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<int> p(n), c(n);
        for (auto& x : p) {fin >> x; x--;}
        for (auto& x : c) fin >> x;
        vector<vector<int>> d(n+1);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j += i)
                d[j].pb(i);
        debug(t);
        vector<bool> v(n);
        int out = inf;
        for (int i = 0; i < n; i++) {
            if (v[i]) continue;
            int x = p[i]; v[i] = 1;
            vector<int> path = {c[i]};
            while (x != i) {
                path.pb(c[x]);
                v[x] = 1; x = p[x];
            }
            // debug(path);
            for (auto& y : d[path.size()])
                for (int j = 0; j < y; j++) {
                    bool va = 1; int cl = path[j];
                    for (int k = (j+y)%path.size(); k != j; k = (k+y)%path.size())
                        va &= (path[k] == cl);
                    // debug(y, j, va);
                    if (va) {
                        out = min(out, y); goto end;
                    }
                }
            end:;
        }
        cout << out << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct unionfind {

    int length;
    vector<int> parent;

    unionfind(int s) {
        length = s;
        parent.assign(s, 0);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int rep(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = rep(a);
        b = rep(b);
        if (a == b)
            return;
        parent[b] = a;
    }

    // returns true if a and b are in the same set.
    inline bool query(int a, int b) {
        return rep(a) == rep(b);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> a(n);
    vector<vector<pair<int, bool>>> adj(k);
    for (int i = 0; i < k; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int x; cin >> x;
            a[x-1].pb(i);
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i].size() == 2) {
            adj[a[i][0]].pb({a[i][1], s[i] == '1'});
            adj[a[i][1]].pb({a[i][0], s[i] == '1'});
        }
    vector<int> red(k, 0), blue(k, 0), stack;
    vector<bool> col(k, 0);
    for (int p = 0; p < k; p++)
        if (red[p] == 0 && blue[p] == 0) {
            stack.pb(p);
            red[p] = 1;
            while (!stack.empty()) {
                int i = stack.back(); stack.pop_back();
                for (auto& [j, t] : adj[i])
                    if (red[j] == 0 && blue[j] == 0) {
                        if (red[i] == int(t))
                            red[j] = 1;
                        else
                            blue[j] = 1;
                        stack.pb(j);
                    }
            }
        }
    for (int i = 0; i < k; i++)
        col[i] = red[i];

    unionfind u(k);
    int out = 0;
    vector<int> forced(k, -1);
    for (int i = 0; i < n; i++) {
        if (a[i].size() == 1) {
            int x = u.rep(a[i][0]);
            if (forced[x] == -1)
                out -= min(red[x], blue[x]);
            else if (forced[x] == 0)
                out -= red[x];
            else if (forced[x] == 1)
                out -= blue[x];
            forced[x] = (col[a[i][0]] == (s[i] == '1')) ? 1 : 0;
            if (forced[x] == -1)
                out += min(red[x], blue[x]);
            else if (forced[x] == 0)
                out += red[x];
            else if (forced[x] == 1)
                out += blue[x];
        }
        if (a[i].size() == 2) {
            int x = u.rep(a[i][0]);
            int y = u.rep(a[i][1]);
            if (!u.query(x, y)) {
                if (forced[x] == -1)
                    out -= min(red[x], blue[x]);
                else if (forced[x] == 0)
                    out -= red[x];
                else if (forced[x] == 1)
                    out -= blue[x];
                if (forced[y] == -1)
                    out -= min(red[y], blue[y]);
                else if (forced[y] == 0)
                    out -= red[y];
                else if (forced[y] == 1)
                    out -= blue[y];
                int r = red[x]+red[y];
                int b = blue[x]+blue[y];
                int f = forced[x];
                if (f == -1)
                    f = forced[y];
                u.unite(x, y);
                x = u.rep(x);
                forced[x] = f;
                red[x] = r;
                blue[x] = b;
                if (forced[x] == -1)
                    out += min(red[x], blue[x]);
                else if (forced[x] == 0)
                    out += red[x];
                else if (forced[x] == 1)
                    out += blue[x];
            }
        }
        cout << out << "\n";
    }
}
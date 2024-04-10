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

struct euleriantour {

    vector<vector<int>> adj;
    vector<int> in, bad, circ;

    // n vertices
    euleriantour(int n) : adj(n), in(n, 0) {}

    // directed edge from i to j
    void edge(int i, int j) {
        adj[j].push_back(i);
        in[i]++;
    }

    void dfs(int i) {
        // Hierholzers algorithm
        while (!adj[i].empty()) {
            int j = adj[i].back();
            adj[i].pop_back();
            dfs(j);
        }
        circ.push_back(i);
    }

    // runs in O(E). one time use. assumes graph is connected.
    vector<int> solve() {
        for (int i = 0; i < adj.size(); i++)
            if (adj[i].size() != in[i])
                bad.push_back(i);

        if (bad.size() == 0) { // found a circuit
            for (int i = 0; i < adj.size(); i++)
                if (!adj[i].empty()) {
                    dfs(i);
                    break;
                }
        } else if (bad.size() == 2) { // found a path
            for (int i : bad)
                if (adj[i].size() == in[i]+1)
                    dfs(i);
        }

        return circ;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    euleriantour t(256*256);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        t.edge(256*s[0]+s[1], 256*s[1]+s[2]);
    }
    auto s = t.solve();
    if (s.empty() || s.size() != n+1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto& x : s)
            cout << char(x/256);
        cout << char(s.back()%256) << "\n";
    }
}
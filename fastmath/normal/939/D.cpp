#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>
#include <bitset>

using namespace std;

vector <int> g[26];

vector <pair <char, char> > ans;
bool used[26];
void dfs(int u) {
    used[u] = true;
    for (int v : g[u]) {
        if (!used[v]) {
            ans.push_back({'a' + u, 'a' + v});
            dfs(v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < n; ++i) {
        int u = s[i] - 'a';
        int v = t[i] - 'a';
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < 26; ++i) {
        if (!used[i]) dfs(i);
    }

    cout << ans.size() << '\n';
    for (pair <char, char> e: ans) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}
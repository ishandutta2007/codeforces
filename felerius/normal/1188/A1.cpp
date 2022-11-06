#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

size_t n;
vector<vector<size_t>> adj;



int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    adj.resize(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    bool pos = true;
    for (size_t i = 0; i < n; ++i) {
        pos &= adj[i].size() != 2;
    }

    if (pos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
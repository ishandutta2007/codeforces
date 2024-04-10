#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

vector <vector <int>> g;

bool is_leaf(int u) {
    return g[u].size() == 0;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int u;
        cin >> u;
        --u;
        g[u].push_back(i);
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (is_leaf(i)) continue;
        int cnt = 0;
        for (auto u : g[i]) {
            if (is_leaf(u)) ++cnt;
        }
        if (cnt < 3) flag = false;
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
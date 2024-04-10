#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 7;

vector <int> g[N];
bool used[N];

vector <int> cmp;
set <int> have, tmp;
int n, m;

void process(int u) {
    for (auto v : g[u]) {
        if (have.count(v)) {
            have.erase(v);
            tmp.insert(v);
        }
    }
    vector <int> to_process;
    while (!have.empty()) {
        int v = *have.begin();
        have.erase(have.begin());
        ++cmp.back();
        used[v] = 1;
        to_process.push_back(v);
    }
    swap(have, tmp);
    for (auto v : to_process) {
        process(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) have.insert(i);
    for (int u = 0; u < n; ++u) {
        if (used[u]) continue;
        cmp.push_back(1);
        have.erase(u);
        process(u);
    }
    cout << cmp.size() << endl;
    sort(cmp.begin(), cmp.end());
    for (auto e : cmp) {
        cout << e << " ";
    }
}
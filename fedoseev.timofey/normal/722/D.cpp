#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e6;
vector <int> g[N];
int used[N];
int mt[N];

int timer = 0;

bool kuhn(int u) {
    if (used[u] == timer) return false;
    used[u] = timer;
    for (auto v : g[u]) {
        if (mt[v] == -1) {
            mt[v] = u;
            return true;
        }
    }
    for (auto v : g[u]) {
        if (kuhn(mt[v])) {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

vector <int> get(int x) {
    vector <int> num;
    while (x >= 1) {
        num.push_back(x);
        x /= 2;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < N; ++i) mt[i] = -1;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> cur(n);
    for (int i = 0; i < n; ++i) {
        cur[i] = get(a[i]);
    }
    vector <int> all;
    for (auto &v : cur) {
        for (auto u : v) {
            all.push_back(u);
        }
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    for (int i = 0; i < n; ++i) {
        for (auto u : cur[i]) {
            int id = lower_bound(all.begin(), all.end(), u) - all.begin();
            g[id].push_back(i);
        }
    }
    int cnt = 0;
    for (int i = 0; i < (int)all.size(); ++i) {
        ++timer;
        if (kuhn(i)) ++cnt;
        if (cnt == n) break;
    }
    vector <int> res;
    for (int i = 0; i < N; ++i) {
        if (mt[i] != -1) {
            res.push_back(mt[i]);
        }
    }
    assert((int)res.size() == n);
    for (auto t : res) {
        cout << all[t] << ' ';
    }
}